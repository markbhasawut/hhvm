// @generated by Thrift for thrift/compiler/test/fixtures/doctext/src/module.thrift
// This file is probably not the place you want to edit!

//! Thrift service definitions for `module`.


/// Service definitions for `C`.
pub mod c {
    #![doc = "Detailed overview of service"]

    #[derive(Clone, Debug)]
    pub enum FExn {

        ApplicationException(::fbthrift::ApplicationException),
    }

    impl ::std::convert::From<FExn> for ::fbthrift::NonthrowingFunctionError {
        fn from(err: FExn) -> Self {
            match err {
                FExn::ApplicationException(aexn) => ::fbthrift::NonthrowingFunctionError::ApplicationException(aexn),
            }
        }
    }

    impl ::std::convert::From<::fbthrift::NonthrowingFunctionError> for FExn {
        fn from(err: ::fbthrift::NonthrowingFunctionError) -> Self {
            match err {
                ::fbthrift::NonthrowingFunctionError::ApplicationException(aexn) => FExn::ApplicationException(aexn),
                ::fbthrift::NonthrowingFunctionError::ThriftError(err) => FExn::ApplicationException(::fbthrift::ApplicationException {
                    message: err.to_string(),
                    type_: ::fbthrift::ApplicationExceptionErrorCode::InternalError,
                }),
            }
        }
    }

    impl ::std::convert::From<::fbthrift::ApplicationException> for FExn {
        fn from(exn: ::fbthrift::ApplicationException) -> Self {
            Self::ApplicationException(exn)
        }
    }

    impl ::fbthrift::ExceptionInfo for FExn {
        fn exn_name(&self) -> &'static str {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_name(),
            }
        }

        fn exn_value(&self) -> String {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_value(),
            }
        }

        fn exn_is_declared(&self) -> bool {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_is_declared(),
            }
        }
    }

    impl ::fbthrift::ResultInfo for FExn {
        fn result_type(&self) -> ::fbthrift::ResultType {
            match self {
                Self::ApplicationException(_aexn) => ::fbthrift::ResultType::Exception,
            }
        }
    }

    impl ::fbthrift::help::SerializeExn for FExn {
        type Success = ();

        fn write_result<P>(
            res: ::std::result::Result<&Self::Success, &Self>,
            p: &mut P,
            function_name: &'static str,
        )
        where
            P: ::fbthrift::ProtocolWriter,
        {
            if let ::std::result::Result::Err(Self::ApplicationException(aexn)) = res {
                ::fbthrift::Serialize::write(aexn, p);
                return;
            }
            p.write_struct_begin(function_name);
            match res {
                ::std::result::Result::Ok(_success) => {
                    p.write_field_begin("Success", ::fbthrift::TType::Void, 0i16);
                    ::fbthrift::Serialize::write(_success, p);
                    p.write_field_end();
                }

                ::std::result::Result::Err(Self::ApplicationException(_aexn)) => unreachable!(),
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    #[derive(Clone, Debug)]
    pub enum NumbersStreamExn {

        ApplicationException(::fbthrift::ApplicationException),
    }

    impl ::fbthrift::ExceptionInfo for NumbersStreamExn {
        fn exn_name(&self) -> &'static str {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_name(),
            }
        }

        fn exn_value(&self) -> String {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_value(),
            }
        }

        fn exn_is_declared(&self) -> bool {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_is_declared(),
            }
        }
    }

    impl ::fbthrift::ResultInfo for NumbersStreamExn {
        fn result_type(&self) -> ::fbthrift::ResultType {
            match self {
                Self::ApplicationException(_aexn) => ::fbthrift::ResultType::Exception,
            }
        }
    }

    impl ::std::convert::From<::fbthrift::ApplicationException> for NumbersStreamExn {
        fn from(exn: ::fbthrift::ApplicationException) -> Self {
            Self::ApplicationException(exn)
        }
    }

    impl ::fbthrift::help::SerializeExn for NumbersStreamExn {
        type Success = crate::types::number;

        fn write_result<P>(
            res: ::std::result::Result<&Self::Success, &Self>,
            p: &mut P,
            function_name: &'static str,
        )
        where
            P: ::fbthrift::ProtocolWriter,
        {
            if let ::std::result::Result::Err(Self::ApplicationException(aexn)) = res {
                ::fbthrift::Serialize::write(aexn, p);
                return;
            }
            p.write_struct_begin(function_name);
            match res {
                ::std::result::Result::Ok(success) => {
                    p.write_field_begin(
                        "Success",
                        ::fbthrift::TType::I32,
                        0i16,
                    );
                    ::fbthrift::Serialize::write(success, p);
                    p.write_field_end();
                }

                ::std::result::Result::Err(Self::ApplicationException(_)) => unreachable!(),
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    #[derive(Clone, Debug)]
    pub enum NumbersExn {

        ApplicationException(::fbthrift::ApplicationException),
    }

    impl ::std::convert::From<NumbersExn> for ::fbthrift::NonthrowingFunctionError {
        fn from(err: NumbersExn) -> Self {
            match err {
                NumbersExn::ApplicationException(aexn) => ::fbthrift::NonthrowingFunctionError::ApplicationException(aexn),
            }
        }
    }

    impl ::std::convert::From<::fbthrift::NonthrowingFunctionError> for NumbersExn {
        fn from(err: ::fbthrift::NonthrowingFunctionError) -> Self {
            match err {
                ::fbthrift::NonthrowingFunctionError::ApplicationException(aexn) => NumbersExn::ApplicationException(aexn),
                ::fbthrift::NonthrowingFunctionError::ThriftError(err) => NumbersExn::ApplicationException(::fbthrift::ApplicationException {
                    message: err.to_string(),
                    type_: ::fbthrift::ApplicationExceptionErrorCode::InternalError,
                }),
            }
        }
    }

    impl ::std::convert::From<::fbthrift::ApplicationException> for NumbersExn {
        fn from(exn: ::fbthrift::ApplicationException) -> Self {
            Self::ApplicationException(exn)
        }
    }

    impl ::fbthrift::ExceptionInfo for NumbersExn {
        fn exn_name(&self) -> &'static str {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_name(),
            }
        }

        fn exn_value(&self) -> String {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_value(),
            }
        }

        fn exn_is_declared(&self) -> bool {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_is_declared(),
            }
        }
    }

    impl ::fbthrift::ResultInfo for NumbersExn {
        fn result_type(&self) -> ::fbthrift::ResultType {
            match self {
                Self::ApplicationException(_aexn) => ::fbthrift::ResultType::Exception,
            }
        }
    }

    impl ::fbthrift::help::SerializeExn for NumbersExn {
        type Success = ();

        fn write_result<P>(
            res: ::std::result::Result<&Self::Success, &Self>,
            p: &mut P,
            function_name: &'static str,
        )
        where
            P: ::fbthrift::ProtocolWriter,
        {
            if let ::std::result::Result::Err(Self::ApplicationException(aexn)) = res {
                ::fbthrift::Serialize::write(aexn, p);
                return;
            }
            p.write_struct_begin(function_name);
            match res {
                ::std::result::Result::Ok(_success) => {
                    p.write_field_begin("Success", ::fbthrift::TType::Void, 0i16);
                    p.write_field_end();
                }

                ::std::result::Result::Err(Self::ApplicationException(_aexn)) => unreachable!(),
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    #[derive(Clone, Debug)]
    pub enum ThingExn {
        bang(crate::types::Bang),
        ApplicationException(::fbthrift::ApplicationException),
    }

    impl ::std::convert::From<crate::types::Bang> for ThingExn {
        fn from(exn: crate::types::Bang) -> Self {
            Self::bang(exn)
        }
    }


    impl ::std::convert::From<::fbthrift::ApplicationException> for ThingExn {
        fn from(exn: ::fbthrift::ApplicationException) -> Self {
            Self::ApplicationException(exn)
        }
    }

    impl ::fbthrift::ExceptionInfo for ThingExn {
        fn exn_name(&self) -> &'static str {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_name(),
                Self::bang(exn) => exn.exn_name(),
            }
        }

        fn exn_value(&self) -> String {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_value(),
                Self::bang(exn) => exn.exn_value(),
            }
        }

        fn exn_is_declared(&self) -> bool {
            match self {
                Self::ApplicationException(aexn) => aexn.exn_is_declared(),
                Self::bang(exn) => exn.exn_is_declared(),
            }
        }
    }

    impl ::fbthrift::ResultInfo for ThingExn {
        fn result_type(&self) -> ::fbthrift::ResultType {
            match self {
                Self::ApplicationException(_aexn) => ::fbthrift::ResultType::Exception,
                Self::bang(_exn) => fbthrift::ResultType::Error,
            }
        }
    }

    impl ::fbthrift::help::SerializeExn for ThingExn {
        type Success = ::std::string::String;

        fn write_result<P>(
            res: ::std::result::Result<&Self::Success, &Self>,
            p: &mut P,
            function_name: &'static str,
        )
        where
            P: ::fbthrift::ProtocolWriter,
        {
            if let ::std::result::Result::Err(Self::ApplicationException(aexn)) = res {
                ::fbthrift::Serialize::write(aexn, p);
                return;
            }
            p.write_struct_begin(function_name);
            match res {
                ::std::result::Result::Ok(_success) => {
                    p.write_field_begin("Success", ::fbthrift::TType::String, 0i16);
                    ::fbthrift::Serialize::write(_success, p);
                    p.write_field_end();
                }
                ::std::result::Result::Err(Self::bang(inner)) => {
                    p.write_field_begin(
                        "bang",
                        ::fbthrift::TType::Struct,
                        1,
                    );
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ::std::result::Result::Err(Self::ApplicationException(_aexn)) => unreachable!(),
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }
}
