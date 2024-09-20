/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic/gen-cpp2/FB303ServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace test::fixtures::basic {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int32_t*>> FB303Service_simple_rpc_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::structure, ::test::fixtures::basic::ReservedKeyword*>> FB303Service_simple_rpc_presult;
} // namespace test::fixtures::basic
template <typename RpcOptions>
void apache::thrift::Client<::test::fixtures::basic::FB303Service>::fbthrift_send_simple_rpc(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback) {

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "simple_rpc",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "test.dev/fixtures/basic/FB303Service");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE>(std::move(request), std::forward<RpcOptions>(rpcOptions), std::move(callback), std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata));
}



void apache::thrift::Client<::test::fixtures::basic::FB303Service>::simple_rpc(std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_int_parameter) {
  ::apache::thrift::RpcOptions rpcOptions;
  simple_rpc(rpcOptions, std::move(callback), p_int_parameter);
}

void apache::thrift::Client<::test::fixtures::basic::FB303Service>::simple_rpc(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, ::std::int32_t p_int_parameter) {
  auto [ctx, header] = simple_rpcCtx(&rpcOptions);
  auto [wrappedCallback, contextStack] = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(std::move(callback), std::move(ctx));
  fbthrift_serialize_and_send_simple_rpc(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_int_parameter);
}

apache::thrift::SerializedRequest apache::thrift::Client<::test::fixtures::basic::FB303Service>::fbthrift_serialize_simple_rpc(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack, ::std::int32_t p_int_parameter) {
  return apache::thrift::detail::ac::withProtocolWriter(apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(), [&](auto&& prot) {
    using ProtocolWriter = std::decay_t<decltype(prot)>;
    ::test::fixtures::basic::FB303Service_simple_rpc_pargs args;
    args.get<0>().value = &p_int_parameter;
    const auto sizer = [&](ProtocolWriter* p) { return args.serializedSizeZC(p); };
    const auto writer = [&](ProtocolWriter* p) { args.write(p); };
    return apache::thrift::preprocessSendT<ProtocolWriter>(
        &prot,
        rpcOptions,
        contextStack,
        header,
        "simple_rpc",
        writer,
        sizer,
        channel_->getChecksumSamplingRate());
  });
}

void apache::thrift::Client<::test::fixtures::basic::FB303Service>::fbthrift_serialize_and_send_simple_rpc(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, ::std::int32_t p_int_parameter, bool stealRpcOptions) {
  apache::thrift::SerializedRequest request = fbthrift_serialize_simple_rpc(rpcOptions, *header, contextStack, p_int_parameter);
  if (stealRpcOptions) {
    fbthrift_send_simple_rpc(std::move(request), std::move(rpcOptions), std::move(header), std::move(callback));
  } else {
    fbthrift_send_simple_rpc(std::move(request), rpcOptions, std::move(header), std::move(callback));
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::test::fixtures::basic::FB303Service>::simple_rpcCtx(apache::thrift::RpcOptions* rpcOptions) {
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
      "FB303Service.simple_rpc",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::test::fixtures::basic::FB303Service>::sync_simple_rpc(::test::fixtures::basic::ReservedKeyword& _return, ::std::int32_t p_int_parameter) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_simple_rpc(rpcOptions, _return, p_int_parameter);
}

void apache::thrift::Client<::test::fixtures::basic::FB303Service>::sync_simple_rpc(apache::thrift::RpcOptions& rpcOptions, ::test::fixtures::basic::ReservedKeyword& _return, ::std::int32_t p_int_parameter) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = simple_rpcCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  auto* contextStack  = ctxAndHeader.first.get();
  if (contextStack != nullptr) {
    auto argsAsRefs = std::tie(p_int_parameter);
    contextStack->processClientInterceptorsOnRequest(apache::thrift::ClientInterceptorOnRequestArguments(argsAsRefs)).throwUnlessValue();
  }
  callback.waitUntilDone(
    evb,
    [&] {
      fbthrift_serialize_and_send_simple_rpc(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback), p_int_parameter);
    });
  if (contextStack != nullptr) {
    contextStack->processClientInterceptorsOnResponse().throwUnlessValue();
  }
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
      recv_simple_rpc(_return, returnState);
  });
}


template <typename CallbackType>
folly::SemiFuture<::test::fixtures::basic::ReservedKeyword> apache::thrift::Client<::test::fixtures::basic::FB303Service>::fbthrift_semifuture_simple_rpc(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_int_parameter) {
  using CallbackHelper = apache::thrift::detail::FutureCallbackHelper<::test::fixtures::basic::ReservedKeyword>;
  folly::Promise<CallbackHelper::PromiseResult> promise;
  auto semifuture = promise.getSemiFuture();
  auto ctxAndHeader = simple_rpcCtx(&rpcOptions);
  auto wrappedCallbackAndContextStack = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(
    std::make_unique<CallbackType>(std::move(promise), recv_wrapped_simple_rpc, channel_),
    std::move(ctxAndHeader.first));
  auto header = std::move(ctxAndHeader.second);
  auto* contextStack = wrappedCallbackAndContextStack.second;
  auto wrappedCallback = std::move(wrappedCallbackAndContextStack.first);
  if (contextStack != nullptr) {
    auto argsAsRefs = std::tie(p_int_parameter);
    if (auto exTry = contextStack->processClientInterceptorsOnRequest(apache::thrift::ClientInterceptorOnRequestArguments(argsAsRefs));
        exTry.hasException()) {
      return folly::makeSemiFuture<::test::fixtures::basic::ReservedKeyword>(std::move(exTry).exception());
    }
  }
  apache::thrift::SerializedRequest request = fbthrift_serialize_simple_rpc(rpcOptions, *header, contextStack, p_int_parameter);
  fbthrift_send_simple_rpc(std::move(request), rpcOptions, std::move(header), std::move(wrappedCallback));
  return std::move(semifuture).deferValue(CallbackHelper::processClientInterceptorsAndExtractResult);
}

folly::Future<::test::fixtures::basic::ReservedKeyword> apache::thrift::Client<::test::fixtures::basic::FB303Service>::future_simple_rpc(::std::int32_t p_int_parameter) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_simple_rpc(rpcOptions, p_int_parameter);
}

folly::SemiFuture<::test::fixtures::basic::ReservedKeyword> apache::thrift::Client<::test::fixtures::basic::FB303Service>::semifuture_simple_rpc(::std::int32_t p_int_parameter) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_simple_rpc(rpcOptions, p_int_parameter);
}

folly::Future<::test::fixtures::basic::ReservedKeyword> apache::thrift::Client<::test::fixtures::basic::FB303Service>::future_simple_rpc(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_int_parameter) {
  using CallbackType = apache::thrift::FutureCallback<::test::fixtures::basic::ReservedKeyword>;
  return fbthrift_semifuture_simple_rpc<CallbackType>(rpcOptions, p_int_parameter).toUnsafeFuture();
}

folly::SemiFuture<::test::fixtures::basic::ReservedKeyword> apache::thrift::Client<::test::fixtures::basic::FB303Service>::semifuture_simple_rpc(apache::thrift::RpcOptions& rpcOptions, ::std::int32_t p_int_parameter) {
  using CallbackType = apache::thrift::SemiFutureCallback<::test::fixtures::basic::ReservedKeyword>;
  return fbthrift_semifuture_simple_rpc<CallbackType>(rpcOptions, p_int_parameter);
}


void apache::thrift::Client<::test::fixtures::basic::FB303Service>::simple_rpc(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, ::std::int32_t p_int_parameter) {
  simple_rpc(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_int_parameter);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::FB303Service>::recv_wrapped_simple_rpc(::test::fixtures::basic::ReservedKeyword& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::test::fixtures::basic::FB303Service_simple_rpc_presult;
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

void apache::thrift::Client<::test::fixtures::basic::FB303Service>::recv_simple_rpc(::test::fixtures::basic::ReservedKeyword& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_simple_rpc(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::test::fixtures::basic::FB303Service>::recv_instance_simple_rpc(::test::fixtures::basic::ReservedKeyword& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_simple_rpc(_return, state);
}

folly::exception_wrapper apache::thrift::Client<::test::fixtures::basic::FB303Service>::recv_instance_wrapped_simple_rpc(::test::fixtures::basic::ReservedKeyword& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_simple_rpc(_return, state);
}


