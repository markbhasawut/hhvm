// @generated by Thrift for thrift/compiler/test/fixtures/namespace_from_package_without_module_name/src/module.thrift
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

pub struct TestService<'mock> {
    pub init: r#impl::test_service::init<'mock>,
    _marker: ::std::marker::PhantomData<&'mock ()>,
}

impl crate::DynClient for dyn ::::TestService {
    type Mock<'mock> = TestService<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        TestService {
            init: r#impl::test_service::init::unimplemented(),
            _marker: ::std::marker::PhantomData,
        }
    }
}

impl<'mock> ::::TestService for TestService<'mock> {
    fn init(
        &self,
        arg_int1: ::std::primitive::i64,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
        let mut closure = self.init.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i64) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_int1.clone())))
    }
}

impl<'mock, T> ::::TestServiceExt<T> for TestService<'mock>
where
    T: ::fbthrift::Transport,
{    fn init_with_rpc_opts(
        &self,
        arg_int1: ::std::primitive::i64,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::primitive::i64, crate::errors::test_service::InitError>> {
        <Self as ::::TestService>::init(
            self,
            arg_int1,
        )
    }

    fn transport(&self) -> &T {
        ::fbthrift::help::GetTransport::transport(self)
    }
}

impl<'mock, T> ::fbthrift::help::GetTransport<T> for TestService<'mock>
where
    T: ::fbthrift::Transport,
{
    fn transport(&self) -> &T {
        unimplemented!("TestServiceExt::transport is not implemented for mock client")
    }
}

pub mod r#impl {
    pub mod test_service {

        pub struct init<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<
                    ::std::primitive::i64,
                    ::::errors::test_service::InitError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> init<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i64| panic!(
                        "{}::{} is not mocked",
                        "TestService",
                        "init",
                    ))),
                }
            }

            pub fn ret(&self, value: ::std::primitive::i64) {
                self.mock(move |_: ::std::primitive::i64| value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::primitive::i64 + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |int1| ::std::result::Result::Ok(mock(int1)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i64) -> ::std::result::Result<::std::primitive::i64, ::::errors::test_service::InitError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |int1| mock(int1));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::test_service::InitError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i64| ::std::result::Result::Err(exception.clone().into()));
            }
        }
    }
}
