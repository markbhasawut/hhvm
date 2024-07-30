/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/sink/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "thrift/compiler/test/fixtures/sink/gen-cpp2/module_types.h"
#include <thrift/lib/cpp2/async/ClientSinkBridge.h>
#include <thrift/lib/cpp2/async/Sink.h>

namespace apache { namespace thrift {
  class Cpp2RequestContext;
  namespace detail { namespace ac { struct ClientRequestContext; }}
  namespace transport { class THeader; }
}}

namespace cpp2 {
class SinkService;
} // namespace cpp2
namespace apache::thrift {

template <>
class Client<::cpp2::SinkService> : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override {
    return "SinkService";
  }


 protected:
  void fbthrift_serialize_and_send_method(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "method"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_method();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "method"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_method(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "method"} */
  static folly::exception_wrapper recv_wrapped_method(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "method"} */
  static apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_method(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "method"} */
  virtual apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_method(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "method"} */
  virtual folly::exception_wrapper recv_instance_wrapped_method(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_method(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_method(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
 protected:
  void fbthrift_serialize_and_send_methodAndReponse(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodAndReponse"} */
  folly::coro::Task<apache::thrift::ResponseAndClientSink<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodAndReponse();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodAndReponse"} */
  folly::coro::Task<apache::thrift::ResponseAndClientSink<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodAndReponse(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodAndReponse"} */
  static folly::exception_wrapper recv_wrapped_methodAndReponse(apache::thrift::ResponseAndClientSink<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodAndReponse"} */
  static apache::thrift::ResponseAndClientSink<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_methodAndReponse(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodAndReponse"} */
  virtual apache::thrift::ResponseAndClientSink<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_methodAndReponse(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodAndReponse"} */
  virtual folly::exception_wrapper recv_instance_wrapped_methodAndReponse(apache::thrift::ResponseAndClientSink<::cpp2::InitialResponse, ::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_methodAndReponse(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_methodAndReponse(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodAndReponseCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
 protected:
  void fbthrift_serialize_and_send_methodThrow(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodThrow();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodThrow(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodThrow"} */
  static folly::exception_wrapper recv_wrapped_methodThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodThrow"} */
  static apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_methodThrow(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodThrow"} */
  virtual apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_methodThrow(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodThrow"} */
  virtual folly::exception_wrapper recv_instance_wrapped_methodThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_methodThrow(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_methodThrow(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodThrowCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
 protected:
  void fbthrift_serialize_and_send_methodSinkThrow(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodSinkThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodSinkThrow();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodSinkThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodSinkThrow(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodSinkThrow"} */
  static folly::exception_wrapper recv_wrapped_methodSinkThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodSinkThrow"} */
  static apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_methodSinkThrow(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodSinkThrow"} */
  virtual apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_methodSinkThrow(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodSinkThrow"} */
  virtual folly::exception_wrapper recv_instance_wrapped_methodSinkThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_methodSinkThrow(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_methodSinkThrow(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodSinkThrowCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
 protected:
  void fbthrift_serialize_and_send_methodFinalThrow(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFinalThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodFinalThrow();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFinalThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodFinalThrow(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFinalThrow"} */
  static folly::exception_wrapper recv_wrapped_methodFinalThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFinalThrow"} */
  static apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_methodFinalThrow(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFinalThrow"} */
  virtual apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_methodFinalThrow(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFinalThrow"} */
  virtual folly::exception_wrapper recv_instance_wrapped_methodFinalThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_methodFinalThrow(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_methodFinalThrow(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodFinalThrowCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
 protected:
  void fbthrift_serialize_and_send_methodBothThrow(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodBothThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodBothThrow();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodBothThrow"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodBothThrow(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodBothThrow"} */
  static folly::exception_wrapper recv_wrapped_methodBothThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodBothThrow"} */
  static apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_methodBothThrow(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodBothThrow"} */
  virtual apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_methodBothThrow(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodBothThrow"} */
  virtual folly::exception_wrapper recv_instance_wrapped_methodBothThrow(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_methodBothThrow(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_methodBothThrow(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodBothThrowCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
 protected:
  void fbthrift_serialize_and_send_methodFast(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::SinkClientCallback* callback, bool stealRpcOptions = false);
 public:
#if FOLLY_HAS_COROUTINES
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFast"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodFast();
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFast"} */
  folly::coro::Task<apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>> co_methodFast(apache::thrift::RpcOptions& rpcOptions);
#endif // FOLLY_HAS_COROUTINES

  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFast"} */
  static folly::exception_wrapper recv_wrapped_methodFast(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFast"} */
  static apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_methodFast(::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFast"} */
  virtual apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse> recv_instance_methodFast(::apache::thrift::ClientReceiveState& state);
  /** Glean {"file": "thrift/compiler/test/fixtures/sink/src/module.thrift", "service": "SinkService", "function": "methodFast"} */
  virtual folly::exception_wrapper recv_instance_wrapped_methodFast(apache::thrift::ClientSink<::cpp2::SinkPayload, ::cpp2::FinalResponse>& _return, ::apache::thrift::ClientReceiveState& state);
 private:
  template <typename Protocol_>
  apache::thrift::SerializedRequest fbthrift_serialize_methodFast(Protocol_* prot, const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack);
  template <typename RpcOptions>
  void fbthrift_send_methodFast(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::SinkClientCallback* callback);
  std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> methodFastCtx(apache::thrift::RpcOptions* rpcOptions);
 public:
};

} // namespace apache::thrift

namespace cpp2 {
using SinkServiceAsyncClient [[deprecated("Use apache::thrift::Client<SinkService> instead")]] = ::apache::thrift::Client<SinkService>;
} // namespace cpp2
