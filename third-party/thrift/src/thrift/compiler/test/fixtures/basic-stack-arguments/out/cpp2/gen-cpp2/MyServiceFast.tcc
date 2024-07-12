/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-stack-arguments/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/basic-stack-arguments/gen-cpp2/MyServiceFast.h"

#include <thrift/lib/cpp2/gen/service_tcc.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int64_t*>> MyServiceFast_hasDataById_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::integral, bool*>> MyServiceFast_hasDataById_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int64_t*>> MyServiceFast_getDataById_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::string, ::std::string*>> MyServiceFast_getDataById_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int64_t*>, apache::thrift::FieldData<2, ::apache::thrift::type_class::string, ::std::string*>> MyServiceFast_putDataById_pargs;
typedef apache::thrift::ThriftPresult<true> MyServiceFast_putDataById_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::integral, ::std::int64_t*>, apache::thrift::FieldData<2, ::apache::thrift::type_class::string, ::std::string*>> MyServiceFast_lobDataById_pargs;
template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::setUpAndProcess_hasDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, [[maybe_unused]] apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, nullptr, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, iface_)) {
    return;
  }
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  apache::thrift::ServerRequest serverRequest{std::move(req), std::move(serializedRequest), ctx, {}, {}, {}, {}};
  executeRequest_hasDataById<ProtocolIn_, ProtocolOut_>(std::move(serverRequest));
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::executeRequest_hasDataById(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  struct ArgsState {
    ::std::int64_t uarg_id{0};
    ::cpp2::MyServiceFast_hasDataById_pargs pargs() {
      ::cpp2::MyServiceFast_hasDataById_pargs args;
      args.get<0>().value = &uarg_id;
      return args;
    }

    auto asTupleOfRefs() & {
      return std::tie(
        std::as_const(uarg_id)
      );
    }
  } args;

  auto ctxStack = apache::thrift::ContextStack::create(
    this->getEventHandlersSharedPtr(),
    this->getServiceName(),
    "MyServiceFast.hasDataById",
    serverRequest.requestContext());
  try {
    auto pargs = args.pargs();
    deserializeRequest<ProtocolIn_>(pargs, "hasDataById", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "hasDataById");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = apache::thrift::HandlerCallbackPtr<bool>::make(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , this->getServiceName()
    , "hasDataById"
    , return_hasDataById<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_hasDataById<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , nullptr
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  const auto makeExecuteHandler = [&] {
    return [ifacePtr = iface_](auto&& cb, ArgsState args) mutable {
      (void)args;
      ifacePtr->async_eb_hasDataById(std::move(cb), args.uarg_id);
    };
  };
#if FOLLY_HAS_COROUTINES
  if (apache::thrift::detail::shouldProcessServiceInterceptorsOnRequest(*callback)) {
    [](auto callback, auto executeHandler, ArgsState args) -> folly::coro::Task<void> {
      auto argRefs = args.asTupleOfRefs();
      co_await apache::thrift::detail::processServiceInterceptorsOnRequest(
          *callback,
          apache::thrift::detail::ServiceInterceptorOnRequestArguments(argRefs));
      executeHandler(std::move(callback), std::move(args));
    }(std::move(callback), makeExecuteHandler(), std::move(args))
              .scheduleOn(apache::thrift::detail::ServerRequestHelper::executor(serverRequest))
              .startInlineUnsafe();
  } else {
    makeExecuteHandler()(std::move(callback), std::move(args));
  }
#else
  makeExecuteHandler()(std::move(callback), std::move(args));
#endif // FOLLY_HAS_COROUTINES
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::SerializedResponse MyServiceFastAsyncProcessor::return_hasDataById(apache::thrift::ContextStack* ctx, bool const& _return) {
  ProtocolOut_ prot;
  ::cpp2::MyServiceFast_hasDataById_presult result;
  result.get<0>().value = const_cast<bool*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse("hasDataById", &prot, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServiceFastAsyncProcessor::throw_wrapped_hasDataById(apache::thrift::ResponseChannelRequest::UniquePtr req,[[maybe_unused]] int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "hasDataById");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::setUpAndProcess_getDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, [[maybe_unused]] apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, nullptr, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, iface_)) {
    return;
  }
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  apache::thrift::ServerRequest serverRequest{std::move(req), std::move(serializedRequest), ctx, {}, {}, {}, {}};
  executeRequest_getDataById<ProtocolIn_, ProtocolOut_>(std::move(serverRequest));
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::executeRequest_getDataById(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  struct ArgsState {
    ::std::int64_t uarg_id{0};
    ::cpp2::MyServiceFast_getDataById_pargs pargs() {
      ::cpp2::MyServiceFast_getDataById_pargs args;
      args.get<0>().value = &uarg_id;
      return args;
    }

    auto asTupleOfRefs() & {
      return std::tie(
        std::as_const(uarg_id)
      );
    }
  } args;

  auto ctxStack = apache::thrift::ContextStack::create(
    this->getEventHandlersSharedPtr(),
    this->getServiceName(),
    "MyServiceFast.getDataById",
    serverRequest.requestContext());
  try {
    auto pargs = args.pargs();
    deserializeRequest<ProtocolIn_>(pargs, "getDataById", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "getDataById");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = apache::thrift::HandlerCallbackPtr<::std::string>::make(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , this->getServiceName()
    , "getDataById"
    , return_getDataById<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_getDataById<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , nullptr
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  const auto makeExecuteHandler = [&] {
    return [ifacePtr = iface_](auto&& cb, ArgsState args) mutable {
      (void)args;
      ifacePtr->async_eb_getDataById(std::move(cb), args.uarg_id);
    };
  };
#if FOLLY_HAS_COROUTINES
  if (apache::thrift::detail::shouldProcessServiceInterceptorsOnRequest(*callback)) {
    [](auto callback, auto executeHandler, ArgsState args) -> folly::coro::Task<void> {
      auto argRefs = args.asTupleOfRefs();
      co_await apache::thrift::detail::processServiceInterceptorsOnRequest(
          *callback,
          apache::thrift::detail::ServiceInterceptorOnRequestArguments(argRefs));
      executeHandler(std::move(callback), std::move(args));
    }(std::move(callback), makeExecuteHandler(), std::move(args))
              .scheduleOn(apache::thrift::detail::ServerRequestHelper::executor(serverRequest))
              .startInlineUnsafe();
  } else {
    makeExecuteHandler()(std::move(callback), std::move(args));
  }
#else
  makeExecuteHandler()(std::move(callback), std::move(args));
#endif // FOLLY_HAS_COROUTINES
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::SerializedResponse MyServiceFastAsyncProcessor::return_getDataById(apache::thrift::ContextStack* ctx, ::std::string const& _return) {
  ProtocolOut_ prot;
  ::cpp2::MyServiceFast_getDataById_presult result;
  result.get<0>().value = const_cast<::std::string*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse("getDataById", &prot, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServiceFastAsyncProcessor::throw_wrapped_getDataById(apache::thrift::ResponseChannelRequest::UniquePtr req,[[maybe_unused]] int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "getDataById");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::setUpAndProcess_putDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, [[maybe_unused]] apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, nullptr, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, iface_)) {
    return;
  }
  if (!req->getShouldStartProcessing()) {
    apache::thrift::HandlerCallbackBase::releaseRequest(std::move(req), eb);
    return;
  }
  apache::thrift::ServerRequest serverRequest{std::move(req), std::move(serializedRequest), ctx, {}, {}, {}, {}};
  executeRequest_putDataById<ProtocolIn_, ProtocolOut_>(std::move(serverRequest));
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::executeRequest_putDataById(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  struct ArgsState {
    ::std::int64_t uarg_id{0};
    ::std::string uarg_data;
    ::cpp2::MyServiceFast_putDataById_pargs pargs() {
      ::cpp2::MyServiceFast_putDataById_pargs args;
      args.get<0>().value = &uarg_id;
      args.get<1>().value = &uarg_data;
      return args;
    }

    auto asTupleOfRefs() & {
      return std::tie(
        std::as_const(uarg_id),
        std::as_const(uarg_data)
      );
    }
  } args;

  auto ctxStack = apache::thrift::ContextStack::create(
    this->getEventHandlersSharedPtr(),
    this->getServiceName(),
    "MyServiceFast.putDataById",
    serverRequest.requestContext());
  try {
    auto pargs = args.pargs();
    deserializeRequest<ProtocolIn_>(pargs, "putDataById", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    folly::exception_wrapper ew(std::current_exception());
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "putDataById");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = apache::thrift::HandlerCallbackPtr<void>::make(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , this->getServiceName()
    , "putDataById"
    , return_putDataById<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_putDataById<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , nullptr
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  const auto makeExecuteHandler = [&] {
    return [ifacePtr = iface_](auto&& cb, ArgsState args) mutable {
      (void)args;
      ifacePtr->async_eb_putDataById(std::move(cb), args.uarg_id, args.uarg_data);
    };
  };
#if FOLLY_HAS_COROUTINES
  if (apache::thrift::detail::shouldProcessServiceInterceptorsOnRequest(*callback)) {
    [](auto callback, auto executeHandler, ArgsState args) -> folly::coro::Task<void> {
      auto argRefs = args.asTupleOfRefs();
      co_await apache::thrift::detail::processServiceInterceptorsOnRequest(
          *callback,
          apache::thrift::detail::ServiceInterceptorOnRequestArguments(argRefs));
      executeHandler(std::move(callback), std::move(args));
    }(std::move(callback), makeExecuteHandler(), std::move(args))
              .scheduleOn(apache::thrift::detail::ServerRequestHelper::executor(serverRequest))
              .startInlineUnsafe();
  } else {
    makeExecuteHandler()(std::move(callback), std::move(args));
  }
#else
  makeExecuteHandler()(std::move(callback), std::move(args));
#endif // FOLLY_HAS_COROUTINES
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::SerializedResponse MyServiceFastAsyncProcessor::return_putDataById(apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  ::cpp2::MyServiceFast_putDataById_presult result;
  return serializeResponse("putDataById", &prot, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void MyServiceFastAsyncProcessor::throw_wrapped_putDataById(apache::thrift::ResponseChannelRequest::UniquePtr req,[[maybe_unused]] int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "putDataById");
    return;
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::setUpAndProcess_lobDataById(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, [[maybe_unused]] apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, nullptr, apache::thrift::RpcKind::SINGLE_REQUEST_NO_RESPONSE, iface_)) {
    return;
  }
  apache::thrift::ServerRequest serverRequest{std::move(req), std::move(serializedRequest), ctx, {}, {}, {}, {}};
  executeRequest_lobDataById<ProtocolIn_, ProtocolOut_>(std::move(serverRequest));
}

template <typename ProtocolIn_, typename ProtocolOut_>
void MyServiceFastAsyncProcessor::executeRequest_lobDataById(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  struct ArgsState {
    ::std::int64_t uarg_id{0};
    ::std::string uarg_data;
    ::cpp2::MyServiceFast_lobDataById_pargs pargs() {
      ::cpp2::MyServiceFast_lobDataById_pargs args;
      args.get<0>().value = &uarg_id;
      args.get<1>().value = &uarg_data;
      return args;
    }

    auto asTupleOfRefs() & {
      return std::tie(
        std::as_const(uarg_id),
        std::as_const(uarg_data)
      );
    }
  } args;

  auto ctxStack = apache::thrift::ContextStack::create(
    this->getEventHandlersSharedPtr(),
    this->getServiceName(),
    "MyServiceFast.lobDataById",
    serverRequest.requestContext());
  try {
    auto pargs = args.pargs();
    deserializeRequest<ProtocolIn_>(pargs, "lobDataById", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (...) {
    LOG(ERROR) << "exception in function lobDataById: " << folly::exceptionStr(std::current_exception());
    apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)->runInEventBaseThread([req = apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))] {});
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::moveRequestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::moveConcurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallbackBase>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , nullptr /* contextStack */
    , this->getServiceName()
    , "lobDataById"
    , nullptr /* exceptionFuncPointer */
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification
    , concurrencyControllerNotification, std::move(serverRequest.requestData())
    );
  const auto makeExecuteHandler = [&] {
    return [ifacePtr = iface_](auto&& cb, ArgsState args) mutable {
      (void)args;
      ifacePtr->async_eb_lobDataById(std::move(cb), args.uarg_id, args.uarg_data);
    };
  };
#if FOLLY_HAS_COROUTINES
  if (apache::thrift::detail::shouldProcessServiceInterceptorsOnRequest(*callback)) {
    [](auto callback, auto executeHandler, ArgsState args) -> folly::coro::Task<void> {
      auto argRefs = args.asTupleOfRefs();
      co_await apache::thrift::detail::processServiceInterceptorsOnRequest(
          *callback,
          apache::thrift::detail::ServiceInterceptorOnRequestArguments(argRefs));
      executeHandler(std::move(callback), std::move(args));
    }(std::move(callback), makeExecuteHandler(), std::move(args))
              .scheduleOn(apache::thrift::detail::ServerRequestHelper::executor(serverRequest))
              .startInlineUnsafe();
  } else {
    makeExecuteHandler()(std::move(callback), std::move(args));
  }
#else
  makeExecuteHandler()(std::move(callback), std::move(args));
#endif // FOLLY_HAS_COROUTINES
}


} // namespace cpp2
