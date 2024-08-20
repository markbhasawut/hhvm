/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic/gen-cpp2/DbMixedStackArgumentsAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace test::fixtures::basic {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::string, ::std::string*>> DbMixedStackArguments_getDataByKey0_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::binary, ::std::string*>> DbMixedStackArguments_getDataByKey0_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::string, ::std::string*>> DbMixedStackArguments_getDataByKey1_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::binary, ::std::string*>> DbMixedStackArguments_getDataByKey1_presult;
} // namespace test::fixtures::basic
template <typename RpcOptions>
void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::fbthrift_send_getDataByKey0(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback) {

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "getDataByKey0",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "test.dev/fixtures/basic/DbMixedStackArguments");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE>(std::move(request), std::forward<RpcOptions>(rpcOptions), std::move(callback), std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata));
}

template <typename RpcOptions>
void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::fbthrift_send_getDataByKey1(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback) {

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "getDataByKey1",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "test.dev/fixtures/basic/DbMixedStackArguments");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE>(std::move(request), std::forward<RpcOptions>(rpcOptions), std::move(callback), std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata));
}



void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey0(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  getDataByKey0(rpcOptions, std::move(callback), p_key);
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey0(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key) {
  auto [ctx, header] = getDataByKey0Ctx(&rpcOptions);
  auto [wrappedCallback, contextStack] = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(std::move(callback), std::move(ctx));
  fbthrift_serialize_and_send_getDataByKey0(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_key);
}

apache::thrift::SerializedRequest apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::fbthrift_serialize_getDataByKey0(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack, const ::std::string& p_key) {
  return apache::thrift::detail::ac::withProtocolWriter(apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(), [&](auto&& prot) {
    using ProtocolWriter = std::decay_t<decltype(prot)>;
    ::test::fixtures::basic::DbMixedStackArguments_getDataByKey0_pargs args;
    args.get<0>().value = const_cast<::std::string*>(&p_key);
    const auto sizer = [&](ProtocolWriter* p) { return args.serializedSizeZC(p); };
    const auto writer = [&](ProtocolWriter* p) { args.write(p); };
    return apache::thrift::preprocessSendT<ProtocolWriter>(
        &prot,
        rpcOptions,
        contextStack,
        header,
        "getDataByKey0",
        writer,
        sizer,
        channel_->getChecksumSamplingRate());
  });
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::fbthrift_serialize_and_send_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::std::string& p_key, bool stealRpcOptions) {
  apache::thrift::SerializedRequest request = fbthrift_serialize_getDataByKey0(rpcOptions, *header, contextStack, p_key);
  if (stealRpcOptions) {
    fbthrift_send_getDataByKey0(std::move(request), std::move(rpcOptions), std::move(header), std::move(callback));
  } else {
    fbthrift_send_getDataByKey0(std::move(request), rpcOptions, std::move(header), std::move(callback));
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey0Ctx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      interceptors_,
      getServiceName(),
      "DbMixedStackArguments.getDataByKey0",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::sync_getDataByKey0(::std::string& _return, const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_getDataByKey0(rpcOptions, _return, p_key);
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::sync_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return, const ::std::string& p_key) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = getDataByKey0Ctx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
#if FOLLY_HAS_COROUTINES
  const bool shouldProcessClientInterceptors = ctxAndHeader.first && ctxAndHeader.first->shouldProcessClientInterceptors();
  if (shouldProcessClientInterceptors) {
    folly::coro::blockingWait(ctxAndHeader.first->processClientInterceptorsOnRequest());
  }
#endif
  callback.waitUntilDone(
    evb,
    [&] {
      fbthrift_serialize_and_send_getDataByKey0(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_key);
    });
#if FOLLY_HAS_COROUTINES
  if (shouldProcessClientInterceptors) {
    folly::coro::blockingWait(ctxAndHeader.first->processClientInterceptorsOnResponse());
  }
#endif
  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_getDataByKey0(_return, returnState);
  });
}


folly::Future<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::future_getDataByKey0(const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_getDataByKey0(rpcOptions, p_key);
}

folly::SemiFuture<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::semifuture_getDataByKey0(const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_getDataByKey0(rpcOptions, p_key);
}

folly::Future<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::future_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
  using CallbackHelper = apache::thrift::detail::FutureCallbackHelper<::std::string>;
  folly::Promise<CallbackHelper::PromiseResult> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::string>>(std::move(promise), recv_wrapped_getDataByKey0, channel_);
  getDataByKey0(rpcOptions, std::move(callback), p_key);
  return std::move(future).thenValue(CallbackHelper::extractResult);
}

folly::SemiFuture<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::semifuture_getDataByKey0(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_getDataByKey0, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getDataByKey0(rpcOptions, std::move(callback), p_key);
  return std::move(callbackAndFuture.second);
}


void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey0(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::string& p_key) {
  getDataByKey0(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_key);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_wrapped_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::test::fixtures::basic::DbMixedStackArguments_getDataByKey0_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_getDataByKey0(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_instance_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_getDataByKey0(_return, state);
}

folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_instance_wrapped_getDataByKey0(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_getDataByKey0(_return, state);
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey1(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  getDataByKey1(rpcOptions, std::move(callback), p_key);
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey1(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::std::string& p_key) {
  auto [ctx, header] = getDataByKey1Ctx(&rpcOptions);
  auto [wrappedCallback, contextStack] = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(std::move(callback), std::move(ctx));
  fbthrift_serialize_and_send_getDataByKey1(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_key);
}

apache::thrift::SerializedRequest apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::fbthrift_serialize_getDataByKey1(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack, const ::std::string& p_key) {
  return apache::thrift::detail::ac::withProtocolWriter(apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(), [&](auto&& prot) {
    using ProtocolWriter = std::decay_t<decltype(prot)>;
    ::test::fixtures::basic::DbMixedStackArguments_getDataByKey1_pargs args;
    args.get<0>().value = const_cast<::std::string*>(&p_key);
    const auto sizer = [&](ProtocolWriter* p) { return args.serializedSizeZC(p); };
    const auto writer = [&](ProtocolWriter* p) { args.write(p); };
    return apache::thrift::preprocessSendT<ProtocolWriter>(
        &prot,
        rpcOptions,
        contextStack,
        header,
        "getDataByKey1",
        writer,
        sizer,
        channel_->getChecksumSamplingRate());
  });
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::fbthrift_serialize_and_send_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::std::string& p_key, bool stealRpcOptions) {
  apache::thrift::SerializedRequest request = fbthrift_serialize_getDataByKey1(rpcOptions, *header, contextStack, p_key);
  if (stealRpcOptions) {
    fbthrift_send_getDataByKey1(std::move(request), std::move(rpcOptions), std::move(header), std::move(callback));
  } else {
    fbthrift_send_getDataByKey1(std::move(request), rpcOptions, std::move(header), std::move(callback));
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey1Ctx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      interceptors_,
      getServiceName(),
      "DbMixedStackArguments.getDataByKey1",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::sync_getDataByKey1(::std::string& _return, const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_getDataByKey1(rpcOptions, _return, p_key);
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::sync_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return, const ::std::string& p_key) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = getDataByKey1Ctx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
#if FOLLY_HAS_COROUTINES
  const bool shouldProcessClientInterceptors = ctxAndHeader.first && ctxAndHeader.first->shouldProcessClientInterceptors();
  if (shouldProcessClientInterceptors) {
    folly::coro::blockingWait(ctxAndHeader.first->processClientInterceptorsOnRequest());
  }
#endif
  callback.waitUntilDone(
    evb,
    [&] {
      fbthrift_serialize_and_send_getDataByKey1(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_key);
    });
#if FOLLY_HAS_COROUTINES
  if (shouldProcessClientInterceptors) {
    folly::coro::blockingWait(ctxAndHeader.first->processClientInterceptorsOnResponse());
  }
#endif
  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_getDataByKey1(_return, returnState);
  });
}


folly::Future<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::future_getDataByKey1(const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_getDataByKey1(rpcOptions, p_key);
}

folly::SemiFuture<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::semifuture_getDataByKey1(const ::std::string& p_key) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_getDataByKey1(rpcOptions, p_key);
}

folly::Future<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::future_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
  using CallbackHelper = apache::thrift::detail::FutureCallbackHelper<::std::string>;
  folly::Promise<CallbackHelper::PromiseResult> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::string>>(std::move(promise), recv_wrapped_getDataByKey1, channel_);
  getDataByKey1(rpcOptions, std::move(callback), p_key);
  return std::move(future).thenValue(CallbackHelper::extractResult);
}

folly::SemiFuture<::std::string> apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::semifuture_getDataByKey1(apache::thrift::RpcOptions& rpcOptions, const ::std::string& p_key) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_getDataByKey1, channel_);
  auto callback = std::move(callbackAndFuture.first);
  getDataByKey1(rpcOptions, std::move(callback), p_key);
  return std::move(callbackAndFuture.second);
}


void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::getDataByKey1(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::std::string& p_key) {
  getDataByKey1(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_key);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_wrapped_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::test::fixtures::basic::DbMixedStackArguments_getDataByKey1_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_getDataByKey1(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_instance_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_getDataByKey1(_return, state);
}

folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::DbMixedStackArguments>::recv_instance_wrapped_getDataByKey1(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_getDataByKey1(_return, state);
}


