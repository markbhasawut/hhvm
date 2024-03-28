/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <memory>
#include <mutex>
#include <string>
#include <typeindex>
#include <unordered_map>

#include <folly/Conv.h>
#include <folly/Function.h>
#include <folly/Range.h>
#include <folly/SharedMutex.h>
#include <folly/ThreadLocal.h>
#include <folly/Utility.h>
#include <folly/container/F14Set.h>
#include <folly/experimental/settings/Immutables.h>
#include <folly/experimental/settings/Types.h>
#include <folly/lang/Aligned.h>

namespace folly {
namespace settings {
namespace detail {

/**
 * Can we store T in a global atomic?
 */
template <class T>
struct IsSmallPOD
    : std::integral_constant<
          bool,
          std::is_trivial<T>::value && sizeof(T) <= sizeof(uint64_t)> {};

template <class T>
struct SettingContents {
  std::string updateReason;
  T value;

  template <class... Args>
  SettingContents(std::string _reason, Args&&... args)
      : updateReason(std::move(_reason)), value(std::forward<Args>(args)...) {}
};

class SnapshotBase;

class SettingCoreBase {
 public:
  using Key = intptr_t;
  using Version = uint64_t;

  virtual SetResult setFromString(
      StringPiece newValue, StringPiece reason, SnapshotBase* snapshot) = 0;
  virtual void forceSetFromString(
      StringPiece newValue, StringPiece reason, SnapshotBase* snapshot) = 0;
  virtual std::pair<std::string, std::string> getAsString(
      const SnapshotBase* snapshot) const = 0;
  virtual SetResult resetToDefault(SnapshotBase* snapshot) = 0;
  virtual void forceResetToDefault(SnapshotBase* snapshot) = 0;
  virtual const SettingMetadata& meta() const = 0;
  virtual ~SettingCoreBase() {}

  /**
   * Hashable key uniquely identifying this setting in this process
   */
  Key getKey() const { return reinterpret_cast<Key>(this); }
};

void registerSetting(SettingCoreBase& core);

/**
 * Returns the monotonically increasing unique positive version.
 */
SettingCoreBase::Version nextGlobalVersion();

template <class T>
class SettingCore;

/**
 * Type erasure for setting values
 */
class BoxedValue {
 public:
  BoxedValue() = default;

  /**
   * Stores a value that can be retrieved later
   */
  template <class T>
  explicit BoxedValue(const SettingContents<T>& value)
      : value_(std::make_shared<SettingContents<T>>(value)) {}

  /**
   * Stores a value that can be both retrieved later and optionally
   * applied globally
   */
  template <class T>
  BoxedValue(const T& value, StringPiece reason, SettingCore<T>& core)
      : value_(std::make_shared<SettingContents<T>>(reason.str(), value)),
        publish_([value = value_,
                  &core](const FrozenSettingProjects& frozenProjects) {
          if (core.meta().mutability == Mutability::Immutable &&
              frozenProjects.contains(core.meta().project)) {
            return;
          }
          auto& contents = BoxedValue::unboxImpl<T>(value.get());
          core.setImpl(
              contents.value, contents.updateReason, /* snapshot */ nullptr);
        }) {}

  /**
   * Returns the reference to the stored value
   */
  template <class T>
  const SettingContents<T>& unbox() const {
    return BoxedValue::unboxImpl<T>(value_.get());
  }

  /**
   * Applies the stored value globally
   */
  void publish(const FrozenSettingProjects& frozenProjects) {
    if (publish_) {
      publish_(frozenProjects);
    }
  }

 private:
  std::shared_ptr<void> value_;
  std::function<void(const FrozenSettingProjects&)> publish_;

  template <class T>
  static const SettingContents<T>& unboxImpl(void* value) {
    return *static_cast<const SettingContents<T>*>(value);
  }
};

/**
 * If there are any outstanding snapshots that care about this
 * value that's about to be updated, save it to extend its lifetime
 */
void saveValueForOutstandingSnapshots(
    SettingCoreBase::Key settingKey,
    SettingCoreBase::Version version,
    const BoxedValue& value);

/**
 * @returns a pointer to a saved value at or before the given version
 */
const BoxedValue* getSavedValue(
    SettingCoreBase::Key key, SettingCoreBase::Version at);

class SnapshotBase {
 public:
  /**
   * Type that encapsulates the current pair of (to<string>(value), reason)
   */
  using SettingsInfo = std::pair<std::string, std::string>;

  /**
   * Apply all settings updates from this snapshot to the global state
   * unconditionally.
   */
  virtual void publish() = 0;

  /**
   * Look up a setting by name, and update the value from a string
   * representation.
   *
   * @returns The SetResult indicating if the setting was successfully updated.
   * @throws std::runtime_error  If there's a conversion error.
   */
  virtual SetResult setFromString(
      StringPiece settingName, StringPiece newValue, StringPiece reason) = 0;

  /**
   * Same as setFromString but will set frozen immutables in this snapshot.
   * However, it will still not publish them. This is mainly useful for setting
   * change dry-runs.
   */
  virtual SetResult forceSetFromString(
      StringPiece settingName, StringPiece newValue, StringPiece reason) = 0;

  /**
   * @return If the setting exists, the current setting information.
   *         Empty Optional otherwise.
   */
  virtual Optional<SettingsInfo> getAsString(StringPiece settingName) const = 0;

  /**
   * Reset the value of the setting identified by name to its default value.
   * The reason will be set to "default".
   *
   * @returns The SetResult indicating if the setting was successfully reset.
   */
  virtual SetResult resetToDefault(StringPiece settingName) = 0;

  /**
   * Same as resetToDefault but will reset frozen immutables in this snapshot.
   * However, it will still not publish them. This is mainly useful for setting
   * change dry-runs.
   */
  virtual SetResult forceResetToDefault(StringPiece settingName) = 0;

  /**
   * Iterates over all known settings and calls
   * func(meta, to<string>(value), reason) for each.
   */
  virtual void forEachSetting(
      const std::function<void(
          const SettingMetadata&, StringPiece, StringPiece)>& func) const = 0;

  virtual ~SnapshotBase();

 protected:
  detail::SettingCoreBase::Version at_;
  std::unordered_map<detail::SettingCoreBase::Key, detail::BoxedValue>
      snapshotValues_;

  template <typename T>
  friend class SettingCore;

  SnapshotBase();

  SnapshotBase(const SnapshotBase&) = delete;
  SnapshotBase& operator=(const SnapshotBase&) = delete;
  SnapshotBase(SnapshotBase&&) = delete;
  SnapshotBase& operator=(SnapshotBase&&) = delete;

  template <class T>
  const SettingContents<T>& get(const detail::SettingCore<T>& core) const {
    auto it = snapshotValues_.find(core.getKey());
    if (it != snapshotValues_.end()) {
      return it->second.template unbox<T>();
    }
    auto savedValue = detail::getSavedValue(core.getKey(), at_);
    if (savedValue) {
      return savedValue->template unbox<T>();
    }
    return core.getSlow();
  }

  template <class T>
  void set(detail::SettingCore<T>& core, const T& t, StringPiece reason) {
    snapshotValues_[core.getKey()] = detail::BoxedValue(t, reason, core);
  }
};

template <class T>
class SettingCore : public SettingCoreBase {
 public:
  using Contents = SettingContents<T>;

  SetResult setFromString(
      StringPiece newValue,
      StringPiece reason,
      SnapshotBase* snapshot) override {
    if (isFrozenImmutable()) {
      // Return the error before calling convertOrConstruct in case it throws.
      return makeUnexpected(SetErrorCode::FrozenImmutable);
    }
    forceSetFromString(newValue, reason, snapshot);
    return unit;
  }

  void forceSetFromString(
      StringPiece newValue,
      StringPiece reason,
      SnapshotBase* snapshot) override {
    setImpl(convertOrConstruct(newValue), reason, snapshot);
  }

  std::pair<std::string, std::string> getAsString(
      const SnapshotBase* snapshot) const override {
    auto& contents = snapshot ? snapshot->get(*this) : getSlow();
    return std::make_pair(
        folly::to<std::string>(contents.value), contents.updateReason);
  }

  SetResult resetToDefault(SnapshotBase* snapshot) override {
    if (isFrozenImmutable()) {
      // Return the error before calling convertOrConstruct in case it throws.
      return makeUnexpected(SetErrorCode::FrozenImmutable);
    }
    forceResetToDefault(snapshot);
    return folly::unit;
  }

  void forceResetToDefault(SnapshotBase* snapshot) override {
    setImpl(defaultValue_, "default", snapshot);
  }

  const SettingMetadata& meta() const override { return meta_; }

  /**
   * @param trivialStorage must refer to the same location
   *   as the internal trivialStorage_.  This hint will
   *   generate better inlined code since the address is known
   *   at compile time at the callsite.
   */
  std::conditional_t<IsSmallPOD<T>::value, T, const T&> getWithHint(
      std::atomic<uint64_t>& trivialStorage) const {
    return getImpl(IsSmallPOD<T>(), trivialStorage);
  }
  const SettingContents<T>& getSlow() const { return *tlValue(); }
  /***
   * SmallPOD version: just read the global atomic
   */
  T getImpl(std::true_type, std::atomic<uint64_t>& trivialStorage) const {
    uint64_t v = trivialStorage.load();
    T t;
    std::memcpy(&t, &v, sizeof(T));
    return t;
  }

  /**
   * Non-SmallPOD version: read the thread local shared_ptr
   */
  const T& getImpl(
      std::false_type, std::atomic<uint64_t>& /* ignored */) const {
    return const_cast<SettingCore*>(this)->tlValue()->value;
  }

  SetResult set(
      const T& t, StringPiece reason, SnapshotBase* snapshot = nullptr) {
    if (isFrozenImmutable()) {
      return makeUnexpected(SetErrorCode::FrozenImmutable);
    }
    setImpl(t, reason, snapshot);
    return unit;
  }

  const T& defaultValue() const { return defaultValue_; }

  using UpdateCallback = Function<void(const Contents&)>;
  class CallbackHandle {
   public:
    CallbackHandle(
        std::shared_ptr<UpdateCallback> callback, SettingCore<T>& setting)
        : callback_(std::move(callback)), setting_(setting) {}
    ~CallbackHandle() {
      if (callback_) {
        std::unique_lock lg(setting_.globalLock_);
        setting_.callbacks_.erase(callback_);
      }
    }
    CallbackHandle(const CallbackHandle&) = delete;
    CallbackHandle& operator=(const CallbackHandle&) = delete;
    CallbackHandle(CallbackHandle&&) = default;
    CallbackHandle& operator=(CallbackHandle&&) = default;

   private:
    std::shared_ptr<UpdateCallback> callback_;
    SettingCore<T>& setting_;
  };
  CallbackHandle addCallback(UpdateCallback callback) {
    auto callbackPtr = copy_to_shared_ptr(std::move(callback));

    auto copiedPtr = callbackPtr;
    {
      std::unique_lock lg(globalLock_);
      callbacks_.emplace(std::move(copiedPtr));
    }
    return CallbackHandle(std::move(callbackPtr), *this);
  }

  SettingCore(
      SettingMetadata meta,
      T defaultValue,
      std::atomic<uint64_t>& trivialStorage)
      : meta_(std::move(meta)),
        defaultValue_(std::move(defaultValue)),
        trivialStorage_(trivialStorage),
        localValue_([]() {
          return new cacheline_aligned<
              std::pair<Version, std::shared_ptr<Contents>>>(
              std::in_place, 0, nullptr);
        }) {
    forceResetToDefault(/* snapshot */ nullptr);
    registerSetting(*this);
  }

 private:
  friend class detail::BoxedValue;

  SettingMetadata meta_;
  const T defaultValue_;

  mutable SharedMutex globalLock_;
  std::shared_ptr<Contents> globalValue_;

  std::atomic<uint64_t>& trivialStorage_;

  F14FastSet<std::shared_ptr<UpdateCallback>> callbacks_;

  /* Thread local versions start at 0, this will force a read on first access.
   */
  cacheline_aligned<std::atomic<Version>> settingVersion_{std::in_place, 1};

  ThreadLocal<cacheline_aligned<std::pair<Version, std::shared_ptr<Contents>>>>
      localValue_;

  FOLLY_ALWAYS_INLINE const std::shared_ptr<Contents>& tlValue() const {
    auto& value = **localValue_;
    if (FOLLY_LIKELY(value.first == *settingVersion_)) {
      return value.second;
    }
    return tlValueSlow();
  }
  FOLLY_NOINLINE const std::shared_ptr<Contents>& tlValueSlow() const {
    auto& value = **localValue_;
    while (value.first < *settingVersion_) {
      /* If this destroys the old value, do it without holding the lock */
      value.second.reset();
      std::shared_lock lg(globalLock_);
      value.first = *settingVersion_;
      value.second = globalValue_;
    }
    return value.second;
  }

  void setImpl(const T& t, StringPiece reason, SnapshotBase* snapshot) {
    /* Check that we can still display it (will throw otherwise) */
    folly::to<std::string>(t);

    if (snapshot) {
      snapshot->set(*this, t, reason);
      return;
    }

    {
      std::unique_lock lg(globalLock_);

      if (globalValue_) {
        saveValueForOutstandingSnapshots(
            getKey(), *settingVersion_, BoxedValue(*globalValue_));
      }
      globalValue_ = std::make_shared<Contents>(reason.str(), t);
      if (IsSmallPOD<T>::value) {
        uint64_t v = 0;
        std::memcpy(&v, &t, sizeof(T));
        trivialStorage_.store(v);
      }
      *settingVersion_ = nextGlobalVersion();
    }
    invokeCallbacks(Contents(reason.str(), t));
  }

  void invokeCallbacks(const Contents& contents) {
    auto callbacksSnapshot = invoke([&] {
      std::shared_lock lg(globalLock_);
      // invoking arbitrary user code under the lock is dangerous
      return std::vector<std::shared_ptr<UpdateCallback>>(
          callbacks_.begin(), callbacks_.end());
    });

    for (auto& callbackPtr : callbacksSnapshot) {
      auto& callback = *callbackPtr;
      callback(contents);
    }
  }

  bool isFrozenImmutable() const {
    switch (meta_.mutability) {
      case Mutability::Mutable:
        return false;
      case Mutability::Immutable:
        return immutablesFrozen(meta_.project);
    }
  }

  T convertOrConstruct(StringPiece newValue) {
    if constexpr (std::is_constructible_v<T, StringPiece>) {
      return T(newValue);
    } else {
      SettingValueAndMetadata from(newValue, meta_);
      return to<T>(from);
    }
  }
};

} // namespace detail
} // namespace settings
} // namespace folly
