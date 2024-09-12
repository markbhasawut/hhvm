/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/adapter/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/module_types.h"

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace facebook::thrift::test {
class Service;
} // namespace facebook::thrift::test
namespace apache::thrift {

template <>
class Client<::facebook::thrift::test::Service> : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "Service";
  }

  static const char* __fbthrift_thrift_uri() {
    return "facebook.com/thrift/test/Service";
  }


  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual void func(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual void func(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
 protected:
  void fbthrift_serialize_and_send_func(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3, bool stealRpcOptions = false);
 public:

  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual ::facebook::thrift::test::MyI32_4873 sync_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual ::facebook::thrift::test::MyI32_4873 sync_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);

  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual folly::Future<::facebook::thrift::test::MyI32_4873> future_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual folly::SemiFuture<::facebook::thrift::test::MyI32_4873> semifuture_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual folly::Future<::facebook::thrift::test::MyI32_4873> future_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual folly::SemiFuture<::facebook::thrift::test::MyI32_4873> semifuture_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);

#if FOLLY_HAS_COROUTINES
#if __clang__
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  template <int = 0>
  folly::coro::Task<::facebook::thrift::test::MyI32_4873> co_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
    return co_func<false>(nullptr, p_arg1, p_arg2, p_arg3);
  }
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  template <int = 0>
  folly::coro::Task<::facebook::thrift::test::MyI32_4873> co_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
    return co_func<true>(&rpcOptions, p_arg1, p_arg2, p_arg3);
  }
#else
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  folly::coro::Task<::facebook::thrift::test::MyI32_4873> co_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
    co_return co_await folly::coro::detachOnCancel(semifuture_func(p_arg1, p_arg2, p_arg3));
  }
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  folly::coro::Task<::facebook::thrift::test::MyI32_4873> co_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
    co_return co_await folly::coro::detachOnCancel(semifuture_func(rpcOptions, p_arg1, p_arg2, p_arg3));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::facebook::thrift::test::MyI32_4873> co_func(apache::thrift::RpcOptions* rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = funcCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions* defaultRpcOptions = new apache::thrift::RpcOptions();
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if (ctx != nullptr) {
      ctx->processClientInterceptorsOnRequest().throwUnlessValue();
    }
    if constexpr (hasRpcOptions) {
      fbthrift_serialize_and_send_func(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_arg1, p_arg2, p_arg3);
    } else {
      fbthrift_serialize_and_send_func(*defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback), p_arg1, p_arg2, p_arg3);
    }
    if (cancellable) {
      folly::CancellationCallback cb(cancelToken, [&] { CancellableCallback::cancel(std::move(cancellableCallback)); });
      co_await callback.co_waitUntilDone();
    } else {
      co_await callback.co_waitUntilDone();
    }
    if (ctx != nullptr) {
      ctx->processClientInterceptorsOnResponse().throwUnlessValue();
    }
    if (returnState.isException()) {
      co_yield folly::coro::co_error(std::move(returnState.exception()));
    }
    returnState.resetProtocolId(protocolId);
    returnState.resetCtx(std::move(ctx));
    SCOPE_EXIT {
      if (hasRpcOptions && returnState.header()) {
        auto* rheader = returnState.header();
        if (!rheader->getHeaders().empty()) {
          rpcOptions->setReadHeaders(rheader->releaseHeaders());
        }
        rpcOptions->setRoutingData(rheader->releaseRoutingData());
      }
    };
    ::facebook::thrift::test::MyI32_4873 _return;
    if (auto ew = recv_wrapped_func(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual void func(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);


  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  static folly::exception_wrapper recv_wrapped_func(::facebook::thrift::test::MyI32_4873& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  static ::facebook::thrift::test::MyI32_4873 recv_func(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual ::facebook::thrift::test::MyI32_4873 recv_instance_func(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/adapter/src/module.thrift", "service": "Service", "function": "func"} */
  virtual folly::exception_wrapper recv_instance_wrapped_func(::facebook::thrift::test::MyI32_4873& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  apache::thrift::SerializedRequest fbthrift_serialize_func(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
  template <typename RpcOptions>
  void fbthrift_send_func(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> funcCtx(apache::thrift::RpcOptions* rpcOptions);
  template <typename CallbackType>
  folly::SemiFuture<::facebook::thrift::test::MyI32_4873> fbthrift_semifuture_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::std::string& p_arg2, const ::facebook::thrift::test::Foo& p_arg3);
 public:
};

} // namespace apache::thrift

namespace facebook::thrift::test {
using ServiceAsyncClient [[deprecated("Use apache::thrift::Client<Service> instead")]] = ::apache::thrift::Client<Service>;
} // namespace facebook::thrift::test
