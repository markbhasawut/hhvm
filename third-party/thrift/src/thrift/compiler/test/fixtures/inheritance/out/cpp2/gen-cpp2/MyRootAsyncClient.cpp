/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/inheritance/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyRootAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> MyRoot_do_root_pargs;
typedef apache::thrift::ThriftPresult<true> MyRoot_do_root_presult;
} // namespace cpp2
template <typename RpcOptions>
void apache::thrift::Client<::cpp2::MyRoot>::fbthrift_send_do_root(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback) {

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "do_root",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "MyRoot");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE>(std::move(request), std::forward<RpcOptions>(rpcOptions), std::move(callback), std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata));
}



void apache::thrift::Client<::cpp2::MyRoot>::do_root(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  do_root(rpcOptions, std::move(callback));
}

void apache::thrift::Client<::cpp2::MyRoot>::do_root(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto [ctx, header] = do_rootCtx(&rpcOptions);
  auto [wrappedCallback, contextStack] = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(std::move(callback), std::move(ctx));
  fbthrift_serialize_and_send_do_root(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback));
}

apache::thrift::SerializedRequest apache::thrift::Client<::cpp2::MyRoot>::fbthrift_serialize_do_root(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack) {
  return apache::thrift::detail::ac::withProtocolWriter(apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(), [&](auto&& prot) {
    using ProtocolWriter = std::decay_t<decltype(prot)>;
    ::cpp2::MyRoot_do_root_pargs args;
    const auto sizer = [&](ProtocolWriter* p) { return args.serializedSizeZC(p); };
    const auto writer = [&](ProtocolWriter* p) { args.write(p); };
    return apache::thrift::preprocessSendT<ProtocolWriter>(
        &prot,
        rpcOptions,
        contextStack,
        header,
        "do_root",
        writer,
        sizer,
        channel_->getChecksumSamplingRate());
  });
}

void apache::thrift::Client<::cpp2::MyRoot>::fbthrift_serialize_and_send_do_root(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, bool stealRpcOptions) {
  apache::thrift::SerializedRequest request = fbthrift_serialize_do_root(rpcOptions, *header, contextStack);
  if (stealRpcOptions) {
    fbthrift_send_do_root(std::move(request), std::move(rpcOptions), std::move(header), std::move(callback));
  } else {
    fbthrift_send_do_root(std::move(request), rpcOptions, std::move(header), std::move(callback));
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::cpp2::MyRoot>::do_rootCtx(apache::thrift::RpcOptions* rpcOptions) {
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
      "MyRoot.do_root",
      *header);

  return {std::move(ctx), std::move(header)};
}

void apache::thrift::Client<::cpp2::MyRoot>::sync_do_root() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_do_root(rpcOptions);
}

void apache::thrift::Client<::cpp2::MyRoot>::sync_do_root(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = do_rootCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  auto* contextStack  = ctxAndHeader.first.get();
  if (contextStack != nullptr) {
    contextStack->processClientInterceptorsOnRequest().throwUnlessValue();
  }
  callback.waitUntilDone(
    evb,
    [&] {
      fbthrift_serialize_and_send_do_root(rpcOptions, std::move(ctxAndHeader.second), ctxAndHeader.first.get(), std::move(wrappedCallback));
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
      recv_do_root(returnState);
  });
}


template <typename CallbackType>
folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::fbthrift_semifuture_do_root(apache::thrift::RpcOptions& rpcOptions) {
  using CallbackHelper = apache::thrift::detail::FutureCallbackHelper<folly::Unit>;
  folly::Promise<CallbackHelper::PromiseResult> promise;
  auto semifuture = promise.getSemiFuture();
  auto ctxAndHeader = do_rootCtx(&rpcOptions);
  auto wrappedCallbackAndContextStack = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(
    std::make_unique<CallbackType>(std::move(promise), recv_wrapped_do_root, channel_),
    std::move(ctxAndHeader.first));
  auto header = std::move(ctxAndHeader.second);
  auto* contextStack = wrappedCallbackAndContextStack.second;
  auto wrappedCallback = std::move(wrappedCallbackAndContextStack.first);
  if (contextStack != nullptr) {
    if (auto exTry = contextStack->processClientInterceptorsOnRequest(); exTry.hasException()) {
      return folly::makeSemiFuture<folly::Unit>(std::move(exTry).exception());
    }
  }
  apache::thrift::SerializedRequest request = fbthrift_serialize_do_root(rpcOptions, *header, contextStack);
  fbthrift_send_do_root(std::move(request), rpcOptions, std::move(header), std::move(wrappedCallback));
  return std::move(semifuture).deferValue(CallbackHelper::processClientInterceptorsAndExtractResult);
}

folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::future_do_root() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_do_root(rpcOptions);
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::semifuture_do_root() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_do_root(rpcOptions);
}

folly::Future<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::future_do_root(apache::thrift::RpcOptions& rpcOptions) {
  using CallbackType = apache::thrift::FutureCallback<folly::Unit>;
  return fbthrift_semifuture_do_root<CallbackType>(rpcOptions).toUnsafeFuture();
}

folly::SemiFuture<folly::Unit> apache::thrift::Client<::cpp2::MyRoot>::semifuture_do_root(apache::thrift::RpcOptions& rpcOptions) {
  using CallbackType = apache::thrift::SemiFutureCallback<folly::Unit>;
  return fbthrift_semifuture_do_root<CallbackType>(rpcOptions);
}


void apache::thrift::Client<::cpp2::MyRoot>::do_root(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  do_root(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::cpp2::MyRoot>::recv_wrapped_do_root(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::cpp2::MyRoot_do_root_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void apache::thrift::Client<::cpp2::MyRoot>::recv_do_root(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_do_root(state);
  if (ew) {
    ew.throw_exception();
  }
}

void apache::thrift::Client<::cpp2::MyRoot>::recv_instance_do_root(::apache::thrift::ClientReceiveState& state) {
  recv_do_root(state);
}

folly::exception_wrapper apache::thrift::Client<::cpp2::MyRoot>::recv_instance_wrapped_do_root(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_do_root(state);
}


