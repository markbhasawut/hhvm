// @generated by Thrift for thrift/compiler/test/fixtures/rust-request-context/src/module.thrift
// This file is probably not the place you want to edit!

//! Mock definitions for `module`.
//!
//! Client mocks. For every service, a struct TheService that implements
//! client::TheService.
//!
//! As an example of the generated API, for the following thrift service in
//! example.thrift:
//!
//! ```thrift
//! service MyService {
//!     FunctionResponse myFunction(
//!         1: FunctionRequest request,
//!     ) throws {
//!         1: StorageException s,
//!         2: NotFoundException n,
//!     ),
//!
//!     // other functions
//! }
//! ```
//!
//! we would end up with this mock object in an `example_mocks` crate:
//!
//! ```
//! # const _: &str = stringify! {
//! impl example_clients::MyService for MyService<'mock> {...}
//!
//! pub struct MyService<'mock> {
//!     pub myFunction: myFunction<'mock>,
//!     // ...
//! }
//!
//! impl myFunction<'mock> {
//!     // directly return the given success response
//!     pub fn ret(&self, value: FunctionResponse);
//!
//!     // invoke closure to compute success response
//!     pub fn mock(
//!         &self,
//!         mock: impl FnMut(FunctionRequest) -> FunctionResponse + Send + Sync + 'mock,
//!     );
//!
//!     // invoke closure to compute response
//!     pub fn mock_result(
//!         &self,
//!         mock: impl FnMut(FunctionRequest) -> Result<FunctionResponse, example_services::errors::MyFunctionExn> + Send + Sync + 'mock,
//!     );
//!
//!     // return one of the function's declared exceptions
//!     pub fn throw<E>(&self, exception: E)
//!     where
//!         E: Clone + Into<example_services::errors::MyFunctionExn> + Send + Sync + 'mock;
//! }
//! # };
//! ```
//!
//! The intended usage from a test would be:
//!
//! ```
//! # const _: &str = stringify! {
//! use std::sync::Arc;
//! use example_clients::MyService;
//!
//! #[tokio::test]
//! async fn test_my_client() {
//!     let mock = Arc::new(example_mocks::new::<dyn MyService>());
//!
//!     // directly return a success response
//!     let resp = FunctionResponse {...};
//!     mock.myFunction.ret(resp);
//!
//!     // or give a closure to compute the success response
//!     mock.myFunction.mock(|request| FunctionResponse {...});
//!
//!     // or throw one of the function's exceptions
//!     mock.myFunction.throw(StorageException::ItFailed);
//!
//!     // or compute a Result (useful if your exceptions aren't Clone)
//!     mock.myFunction.mock_result(|request| Err(...));
//!
//!     let out = do_the_thing(mock).await.unwrap();
//!     assert!(out.what_i_expected());
//! }
//!
//! async fn do_the_thing(
//!     client: Arc<dyn MyService + Send + Sync + 'static>,
//! ) -> Out {...}
//! # };
//! ```

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies, unused_imports, clippy::all)]

pub(crate) use :: as types;
pub(crate) use :: as client;
pub(crate) use ::::errors;

pub fn new<'mock, Client>() -> Client::Mock<'mock>
where
    Client: ?::std::marker::Sized + DynClient,
{
    Client::mock()
}

pub trait DynClient {
    type Mock<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock>;
}

pub struct MyService<'mock> {
    pub ping: r#impl::my_service::ping<'mock>,
    pub getRandomData: r#impl::my_service::getRandomData<'mock>,
    pub hasDataById: r#impl::my_service::hasDataById<'mock>,
    pub getDataById: r#impl::my_service::getDataById<'mock>,
    pub putDataById: r#impl::my_service::putDataById<'mock>,
    pub lobDataById: r#impl::my_service::lobDataById<'mock>,
    pub streamById: r#impl::my_service::streamById<'mock>,
    pub streamByIdWithException: r#impl::my_service::streamByIdWithException<'mock>,
    pub streamByIdWithResponse: r#impl::my_service::streamByIdWithResponse<'mock>,
    pub startPingInteraction: r#impl::my_service::startPingInteraction<'mock>,
    _marker: ::std::marker::PhantomData<&'mock ()>,
}

impl crate::DynClient for dyn ::::MyService {
    type Mock<'mock> = MyService<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        MyService {
            ping: r#impl::my_service::ping::unimplemented(),
            getRandomData: r#impl::my_service::getRandomData::unimplemented(),
            hasDataById: r#impl::my_service::hasDataById::unimplemented(),
            getDataById: r#impl::my_service::getDataById::unimplemented(),
            putDataById: r#impl::my_service::putDataById::unimplemented(),
            lobDataById: r#impl::my_service::lobDataById::unimplemented(),
            streamById: r#impl::my_service::streamById::unimplemented(),
            streamByIdWithException: r#impl::my_service::streamByIdWithException::unimplemented(),
            streamByIdWithResponse: r#impl::my_service::streamByIdWithResponse::unimplemented(),
            startPingInteraction: r#impl::my_service::startPingInteraction::unimplemented(),
            _marker: ::std::marker::PhantomData,
        }
    }
}

impl<'mock> ::::MyService for MyService<'mock> {
    fn ping(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        let mut closure = self.ping.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
    fn getRandomData(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        let mut closure = self.getRandomData.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
    fn hasDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        let mut closure = self.hasDataById.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone())))
    }
    fn getDataById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        let mut closure = self.getDataById.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone())))
    }
    fn putDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        let mut closure = self.putDataById.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone(), arg_data.to_owned())))
    }
    fn lobDataById(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        let mut closure = self.lobDataById.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone(), arg_data.to_owned())))
    }
    fn streamById(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdStreamError>>, crate::errors::my_service::StreamByIdError>> {
        let mut closure = self.streamById.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone())))
    }
    fn streamByIdWithException(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithExceptionStreamError>>, crate::errors::my_service::StreamByIdWithExceptionError>> {
        let mut closure = self.streamByIdWithException.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone())))
    }
    fn streamByIdWithResponse(
        &self,
        arg_id: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(crate::types::MyDataItem, ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithResponseStreamError>>), crate::errors::my_service::StreamByIdWithResponseError>> {
        let mut closure = self.streamByIdWithResponse.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_id.clone())))
    }

    fn createMyInteraction(
        &self,
    ) -> ::std::result::Result<crate::client::my_service::MyInteractionClient, ::anyhow::Error> {
        unimplemented!("Mocking interactions is not yet implemented");
    }

    fn startPingInteraction(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<crate::client::my_service::MyInteractionClient, crate::errors::my_service::StartPingInteractionError>> {
        unimplemented!("Mocking interactions is not yet implemented");
    }
}

impl<'mock, T> ::::MyServiceExt<T> for MyService<'mock>
where
    T: ::fbthrift::Transport,
{    fn ping_with_rpc_opts(
        &self,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PingError>> {
        <Self as ::::MyService>::ping(
            self,
        )
    }
    fn getRandomData_with_rpc_opts(
        &self,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetRandomDataError>> {
        <Self as ::::MyService>::getRandomData(
            self,
        )
    }
    fn hasDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::bool, crate::errors::my_service::HasDataByIdError>> {
        <Self as ::::MyService>::hasDataById(
            self,
            arg_id,
        )
    }
    fn getDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::my_service::GetDataByIdError>> {
        <Self as ::::MyService>::getDataById(
            self,
            arg_id,
        )
    }
    fn putDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::PutDataByIdError>> {
        <Self as ::::MyService>::putDataById(
            self,
            arg_id,
            arg_data,
        )
    }
    fn lobDataById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        arg_data: &::std::primitive::str,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::my_service::LobDataByIdError>> {
        <Self as ::::MyService>::lobDataById(
            self,
            arg_id,
            arg_data,
        )
    }
    fn streamById_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdStreamError>>, crate::errors::my_service::StreamByIdError>> {
        <Self as ::::MyService>::streamById(
            self,
            arg_id,
        )
    }
    fn streamByIdWithException_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithExceptionStreamError>>, crate::errors::my_service::StreamByIdWithExceptionError>> {
        <Self as ::::MyService>::streamByIdWithException(
            self,
            arg_id,
        )
    }
    fn streamByIdWithResponse_with_rpc_opts(
        &self,
        arg_id: ::std::primitive::i64,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(crate::types::MyDataItem, ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithResponseStreamError>>), crate::errors::my_service::StreamByIdWithResponseError>> {
        <Self as ::::MyService>::streamByIdWithResponse(
            self,
            arg_id,
        )
    }
    fn startPingInteraction_with_rpc_opts(
        &self,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<crate::client::my_service::MyInteractionClient, crate::errors::my_service::StartPingInteractionError>> {
        <Self as ::::MyService>::startPingInteraction(
            self,
        )
    }

    fn transport(&self) -> &T {
        ::fbthrift::help::GetTransport::transport(self)
    }
}

impl<'mock, T> ::fbthrift::help::GetTransport<T> for MyService<'mock>
where
    T: ::fbthrift::Transport,
{
    fn transport(&self) -> &T {
        unimplemented!("MyServiceExt::transport is not implemented for mock client")
    }
}

pub mod r#impl {
    pub mod my_service {

        pub struct ping<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    (),
                    ::::errors::my_service::PingError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> ping<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "ping",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move || value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<(), ::::errors::my_service::PingError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::PingError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct getRandomData<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    ::std::string::String,
                    ::::errors::my_service::GetRandomDataError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> getRandomData<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "getRandomData",
                    ))),
                }
            }

            pub fn ret(&self, value: ::std::string::String) {
                self.mock(move || value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> ::std::string::String + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<::std::string::String, ::::errors::my_service::GetRandomDataError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::GetRandomDataError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct hasDataById<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                    ::std::primitive::bool,
                    ::::errors::my_service::HasDataByIdError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> hasDataById<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "hasDataById",
                    ))),
                }
            }

            pub fn ret(&self, value: ::std::primitive::bool) {
                self.mock(move |_: ::std::primitive::i64| value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::primitive::bool + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| ::std::result::Result::Ok(mock(id)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<::std::primitive::bool, ::::errors::my_service::HasDataByIdError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| mock(id));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::HasDataByIdError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct getDataById<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                    ::std::string::String,
                    ::::errors::my_service::GetDataByIdError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> getDataById<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "getDataById",
                    ))),
                }
            }

            pub fn ret(&self, value: ::std::string::String) {
                self.mock(move |_: ::std::primitive::i64| value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::string::String + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| ::std::result::Result::Ok(mock(id)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<::std::string::String, ::::errors::my_service::GetDataByIdError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| mock(id));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::GetDataByIdError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct putDataById<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> ::std::result::Result<
                    (),
                    ::::errors::my_service::PutDataByIdError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> putDataById<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64, _: ::std::string::String| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "putDataById",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move |_: ::std::primitive::i64, _: ::std::string::String| value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id, data| ::std::result::Result::Ok(mock(id, data)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> ::std::result::Result<(), ::::errors::my_service::PutDataByIdError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id, data| mock(id, data));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::PutDataByIdError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64, _: ::std::string::String| ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct lobDataById<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> ::std::result::Result<
                    (),
                    ::::errors::my_service::LobDataByIdError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> lobDataById<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64, _: ::std::string::String| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "lobDataById",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move |_: ::std::primitive::i64, _: ::std::string::String| value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id, data| ::std::result::Result::Ok(mock(id, data)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64, ::std::string::String) -> ::std::result::Result<(), ::::errors::my_service::LobDataByIdError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id, data| mock(id, data));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::LobDataByIdError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64, _: ::std::string::String| ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct streamById<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                    ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdStreamError>>,
                    ::::errors::my_service::StreamByIdError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> streamById<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "streamById",
                    ))),
                }
            }

            pub fn ret(&self, _value: ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdStreamError>>) {
                unimplemented!("Mocking streams is not yet implemented, as value isn't cloneable")
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdStreamError>> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| ::std::result::Result::Ok(mock(id)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdStreamError>>, ::::errors::my_service::StreamByIdError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| mock(id));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::StreamByIdError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct streamByIdWithException<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                    ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithExceptionStreamError>>,
                    ::::errors::my_service::StreamByIdWithExceptionError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> streamByIdWithException<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "streamByIdWithException",
                    ))),
                }
            }

            pub fn ret(&self, _value: ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithExceptionStreamError>>) {
                unimplemented!("Mocking streams is not yet implemented, as value isn't cloneable")
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithExceptionStreamError>> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| ::std::result::Result::Ok(mock(id)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithExceptionStreamError>>, ::::errors::my_service::StreamByIdWithExceptionError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| mock(id));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::StreamByIdWithExceptionError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct streamByIdWithResponse<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                    (crate::types::MyDataItem, ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithResponseStreamError>>),
                    ::::errors::my_service::StreamByIdWithResponseError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> streamByIdWithResponse<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "streamByIdWithResponse",
                    ))),
                }
            }

            pub fn ret(&self, _value: (crate::types::MyDataItem, ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithResponseStreamError>>)) {
                unimplemented!("Mocking streams is not yet implemented, as value isn't cloneable")
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> (crate::types::MyDataItem, ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithResponseStreamError>>) + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| ::std::result::Result::Ok(mock(id)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<(crate::types::MyDataItem, ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::MyStruct, crate::errors::my_service::StreamByIdWithResponseStreamError>>), ::::errors::my_service::StreamByIdWithResponseError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |id| mock(id));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::StreamByIdWithResponseError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
            }
        }


        pub struct startPingInteraction<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    (),
                    ::::errors::my_service::StartPingInteractionError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> startPingInteraction<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "MyService",
                        "startPingInteraction",
                    ))),
                }
            }

            pub fn ret(&self, value: ()) {
                self.mock(move || value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> () + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<(), ::::errors::my_service::StartPingInteractionError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::my_service::StartPingInteractionError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }
    }
}
