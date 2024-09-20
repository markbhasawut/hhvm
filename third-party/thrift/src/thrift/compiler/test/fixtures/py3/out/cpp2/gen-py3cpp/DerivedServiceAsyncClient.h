/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/py3/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/py3/gen-py3cpp/module_types.h"
#if __has_include("thrift/compiler/test/fixtures/py3/gen-py3cpp/SimpleServiceAsyncClient.h")
#include "thrift/compiler/test/fixtures/py3/gen-py3cpp/SimpleServiceAsyncClient.h"
#else
#include "thrift/compiler/test/fixtures/py3/gen-py3cpp/module_clients.h"
#endif

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace py3::simple {
class DerivedService;
} // namespace py3::simple
namespace apache::thrift {

template <>
class Client<::py3::simple::DerivedService> : public ::py3::simple::SimpleServiceAsyncClient {
 public:
  using ::py3::simple::SimpleServiceAsyncClient::SimpleServiceAsyncClient;

  char const* getServiceName() const noexcept override {
    return "DerivedService";
  }


  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual void get_six(std::unique_ptr<apache::thrift::RequestCallback> callback);
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual void get_six(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback);
 protected:
  void fbthrift_serialize_and_send_get_six(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions = false);
 public:

  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual ::std::int32_t sync_get_six();
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual ::std::int32_t sync_get_six(apache::thrift::RpcOptions& rpcOptions);

  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual folly::Future<::std::int32_t> future_get_six();
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual folly::SemiFuture<::std::int32_t> semifuture_get_six();
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual folly::Future<::std::int32_t> future_get_six(apache::thrift::RpcOptions& rpcOptions);
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual folly::SemiFuture<::std::int32_t> semifuture_get_six(apache::thrift::RpcOptions& rpcOptions);

#if FOLLY_HAS_COROUTINES
#if __clang__
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  template <int = 0>
  folly::coro::Task<::std::int32_t> co_get_six() {
    return co_get_six<false>(nullptr);
  }
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  template <int = 0>
  folly::coro::Task<::std::int32_t> co_get_six(apache::thrift::RpcOptions& rpcOptions) {
    return co_get_six<true>(&rpcOptions);
  }
#else
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  folly::coro::Task<::std::int32_t> co_get_six() {
    co_return co_await folly::coro::detachOnCancel(semifuture_get_six());
  }
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  folly::coro::Task<::std::int32_t> co_get_six(apache::thrift::RpcOptions& rpcOptions) {
    co_return co_await folly::coro::detachOnCancel(semifuture_get_six(rpcOptions));
  }
#endif
 private:
  template <bool hasRpcOptions>
  folly::coro::Task<::std::int32_t> co_get_six(apache::thrift::RpcOptions* rpcOptions) {
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    const bool cancellable = cancelToken.canBeCancelled();
    apache::thrift::ClientReceiveState returnState;
    apache::thrift::ClientCoroCallback<false> callback(&returnState, co_await folly::coro::co_current_executor);
    auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
    auto [ctx, header] = get_sixCtx(rpcOptions);
    using CancellableCallback = apache::thrift::CancellableRequestClientCallback<false>;
    auto cancellableCallback = cancellable ? CancellableCallback::create(&callback, channel_) : nullptr;
    static apache::thrift::RpcOptions* defaultRpcOptions = new apache::thrift::RpcOptions();
    auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(cancellableCallback ? (apache::thrift::RequestClientCallback*)cancellableCallback.get() : &callback);
    if (ctx != nullptr) {
      auto argsAsRefs = std::tie();
      ctx->processClientInterceptorsOnRequest(apache::thrift::ClientInterceptorOnRequestArguments(argsAsRefs)).throwUnlessValue();
    }
    if constexpr (hasRpcOptions) {
      fbthrift_serialize_and_send_get_six(*rpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
    } else {
      fbthrift_serialize_and_send_get_six(*defaultRpcOptions, std::move(header), ctx.get(), std::move(wrappedCallback));
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
    ::std::int32_t _return;
    if (auto ew = recv_wrapped_get_six(_return, returnState)) {
      co_yield folly::coro::co_error(std::move(ew));
    }
    co_return _return;
  }
 public:
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual void get_six(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback);


  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  static folly::exception_wrapper recv_wrapped_get_six(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  static ::std::int32_t recv_get_six(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual ::std::int32_t recv_instance_get_six(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/py3/src/module.thrift", "service": "DerivedService", "function": "get_six"} */
  virtual folly::exception_wrapper recv_instance_wrapped_get_six(::std::int32_t& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  apache::thrift::SerializedRequest fbthrift_serialize_get_six(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_get_six(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> get_sixCtx(apache::thrift::RpcOptions* rpcOptions);
  template <typename CallbackType>
  folly::SemiFuture<::std::int32_t> fbthrift_semifuture_get_six(apache::thrift::RpcOptions& rpcOptions);
 public:
};

} // namespace apache::thrift

namespace py3::simple {
using DerivedServiceAsyncClient [[deprecated("Use apache::thrift::Client<DerivedService> instead")]] = ::apache::thrift::Client<DerivedService>;
} // namespace py3::simple
