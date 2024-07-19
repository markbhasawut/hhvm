// @generated by Thrift for thrift/compiler/test/fixtures/doctext/src/module.thrift
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

pub struct C<'mock> {
    pub f: r#impl::c::f<'mock>,
    pub numbers: r#impl::c::numbers<'mock>,
    pub thing: r#impl::c::thing<'mock>,
    _marker: ::std::marker::PhantomData<&'mock ()>,
}

impl crate::DynClient for dyn ::::C {
    type Mock<'mock> = C<'mock>;
    fn mock<'mock>() -> Self::Mock<'mock> {
        C {
            f: r#impl::c::f::unimplemented(),
            numbers: r#impl::c::numbers::unimplemented(),
            thing: r#impl::c::thing::unimplemented(),
            _marker: ::std::marker::PhantomData,
        }
    }
}

impl<'mock> ::::C for C<'mock> {
    fn f(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::c::FError>> {
        let mut closure = self.f.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
    fn numbers(
        &self,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::number, crate::errors::c::NumbersStreamError>>, crate::errors::c::NumbersError>> {
        let mut closure = self.numbers.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut() -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure()))
    }
    fn thing(
        &self,
        arg_a: ::std::primitive::i32,
        arg_b: &::std::primitive::str,
        arg_c: &::std::collections::BTreeSet<::std::primitive::i32>,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::c::ThingError>> {
        let mut closure = self.thing.closure.lock().unwrap();
        let closure: &mut dyn ::std::ops::FnMut(::std::primitive::i32, ::std::string::String, ::std::collections::BTreeSet<::std::primitive::i32>) -> _ = &mut **closure;
        ::std::boxed::Box::pin(::futures::future::ready(closure(arg_a.clone(), arg_b.to_owned(), arg_c.clone())))
    }
}

impl<'mock, T> ::::CExt<T> for C<'mock>
where
    T: ::fbthrift::Transport,
{    fn f_with_rpc_opts(
        &self,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<(), crate::errors::c::FError>> {
        <Self as ::::C>::f(
            self,
        )
    }
    fn numbers_with_rpc_opts(
        &self,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::number, crate::errors::c::NumbersStreamError>>, crate::errors::c::NumbersError>> {
        <Self as ::::C>::numbers(
            self,
        )
    }
    fn thing_with_rpc_opts(
        &self,
        arg_a: ::std::primitive::i32,
        arg_b: &::std::primitive::str,
        arg_c: &::std::collections::BTreeSet<::std::primitive::i32>,
        _rpc_options: T::RpcOptions,
    ) -> ::futures::future::BoxFuture<'static, ::std::result::Result<::std::string::String, crate::errors::c::ThingError>> {
        <Self as ::::C>::thing(
            self,
            arg_a,
            arg_b,
            arg_c,
        )
    }

    fn transport(&self) -> &T {
        ::fbthrift::help::GetTransport::transport(self)
    }
}

impl<'mock, T> ::fbthrift::help::GetTransport<T> for C<'mock>
where
    T: ::fbthrift::Transport,
{
    fn transport(&self) -> &T {
        unimplemented!("CExt::transport is not implemented for mock client")
    }
}

pub mod r#impl {
    pub mod c {

        pub struct f<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    (),
                    ::::errors::c::FError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> f<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "C",
                        "f",
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

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<(), ::::errors::c::FError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::c::FError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct numbers<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut() -> ::std::result::Result<
                    ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::number, crate::errors::c::NumbersStreamError>>,
                    ::::errors::c::NumbersError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> numbers<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|| panic!(
                        "{}::{} is not mocked",
                        "C",
                        "numbers",
                    ))),
                }
            }

            pub fn ret(&self, _value: ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::number, crate::errors::c::NumbersStreamError>>) {
                unimplemented!("Mocking streams is not yet implemented, as value isn't cloneable")
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut() -> ::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::number, crate::errors::c::NumbersStreamError>> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Ok(mock()));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut() -> ::std::result::Result<::futures::stream::BoxStream<'static, ::std::result::Result<crate::types::number, crate::errors::c::NumbersStreamError>>, ::::errors::c::NumbersError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || mock());
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::c::NumbersError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move || ::std::result::Result::Err(exception.clone().into()));
            }
        }

        pub struct thing<'mock> {
            pub(crate) closure: ::std::sync::Mutex<::std::boxed::Box<
                dyn ::std::ops::FnMut(::std::primitive::i32, ::std::string::String, ::std::collections::BTreeSet<::std::primitive::i32>) -> ::std::result::Result<
                    ::std::string::String,
                    ::::errors::c::ThingError,
                > + ::std::marker::Send + ::std::marker::Sync + 'mock,
            >>,
        }

        #[allow(clippy::redundant_closure)]
        impl<'mock> thing<'mock> {
            pub(crate) fn unimplemented() -> Self {
                Self {
                    closure: ::std::sync::Mutex::new(::std::boxed::Box::new(|_: ::std::primitive::i32, _: ::std::string::String, _: ::std::collections::BTreeSet<::std::primitive::i32>| panic!(
                        "{}::{} is not mocked",
                        "C",
                        "thing",
                    ))),
                }
            }

            pub fn ret(&self, value: ::std::string::String) {
                self.mock(move |_: ::std::primitive::i32, _: ::std::string::String, _: ::std::collections::BTreeSet<::std::primitive::i32>| value.clone());
            }

            pub fn mock(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i32, ::std::string::String, ::std::collections::BTreeSet<::std::primitive::i32>) -> ::std::string::String + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |a, b, c| ::std::result::Result::Ok(mock(a, b, c)));
            }

            pub fn mock_result(&self, mut mock: impl ::std::ops::FnMut(::std::primitive::i32, ::std::string::String, ::std::collections::BTreeSet<::std::primitive::i32>) -> ::std::result::Result<::std::string::String, ::::errors::c::ThingError> + ::std::marker::Send + ::std::marker::Sync + 'mock) {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |a, b, c| mock(a, b, c));
            }

            pub fn throw<E>(&self, exception: E)
            where
                E: ::std::convert::Into<::::errors::c::ThingError>,
                E: ::std::clone::Clone + ::std::marker::Send + ::std::marker::Sync + 'mock,
            {
                let mut closure = self.closure.lock().unwrap();
                *closure = ::std::boxed::Box::new(move |_: ::std::primitive::i32, _: ::std::string::String, _: ::std::collections::BTreeSet<::std::primitive::i32>| ::std::result::Result::Err(exception.clone().into()));
            }
        }
    }
}
