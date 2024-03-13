#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.utility cimport move as cmove
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as _fbthrift_iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.types cimport (
    bstring,
    bytes_to_string,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
    terse_field_ref as __terse_field_ref,
    union_field_ref as __union_field_ref,
    get_union_field_value as __get_union_field_value,
)
from thrift.py3.common cimport (
    RpcOptions as __RpcOptions,
    Protocol as __Protocol,
    cThriftMetadata as __fbthrift_cThriftMetadata,
    MetadataBox as __MetadataBox,
)
from folly.optional cimport cOptional as __cOptional

cimport c.types_fields as _fbthrift_types_fields

cdef extern from "thrift/compiler/test/fixtures/transitive-deps/gen-py3/c/types.h":
  pass





cdef extern from "thrift/compiler/test/fixtures/transitive-deps/gen-cpp2/c_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass ExceptionMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/transitive-deps/gen-cpp2/c_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass StructMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/transitive-deps/gen-cpp2/c_types_custom_protocol.h" namespace "::cpp2":

    cdef cppclass cC "::cpp2::C":
        cC() except +
        cC(const cC&) except +
        bint operator==(cC&)
        bint operator!=(cC&)
        bint operator<(cC&)
        bint operator>(cC&)
        bint operator<=(cC&)
        bint operator>=(cC&)
        __field_ref[cint64_t] i_ref "i_ref" ()


    cdef cppclass cE "::cpp2::E"(cTException):
        cE() except +
        cE(const cE&) except +
        bint operator==(cE&)
        bint operator!=(cE&)
        bint operator<(cE&)
        bint operator>(cE&)
        bint operator<=(cE&)
        bint operator>=(cE&)




cdef class C(thrift.py3.types.Struct):
    cdef shared_ptr[cC] _cpp_obj
    cdef _fbthrift_types_fields.__C_FieldsSetter _fields_setter
    cdef inline object i_impl(self)

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cC])



cdef class E(thrift.py3.exceptions.GeneratedError):
    cdef shared_ptr[cE] _cpp_obj
    cdef _fbthrift_types_fields.__E_FieldsSetter _fields_setter

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cE])



