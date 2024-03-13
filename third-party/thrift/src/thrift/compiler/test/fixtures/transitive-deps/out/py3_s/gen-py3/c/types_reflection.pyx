#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#


import folly.iobuf as _fbthrift_iobuf

from thrift.py3.reflection cimport (
    NumberType as __NumberType,
    StructType as __StructType,
    Qualifier as __Qualifier,
)


cimport c.types as _c_types

from thrift.py3.types cimport (
    constant_shared_ptr,
    default_inst,
)


cdef __StructSpec get_reflection__C():
    cdef _c_types.C defaults = _c_types.C._fbthrift_create(
        constant_shared_ptr[_c_types.cC](
            default_inst[_c_types.cC]()
        )
    )
    cdef __StructSpec spec = __StructSpec._fbthrift_create(
        name="C",
        kind=__StructType.STRUCT,
        annotations={
        },
    )
    spec.add_field(
        __FieldSpec._fbthrift_create(
            id=1,
            name="i",
            py_name="i",
            type=int,
            kind=__NumberType.I64,
            qualifier=__Qualifier.UNQUALIFIED,
            default=None,
            annotations={
            },
        ),
    )
    return spec
cdef __StructSpec get_reflection__E():
    cdef _c_types.E defaults = _c_types.E._fbthrift_create(
        constant_shared_ptr[_c_types.cE](
            default_inst[_c_types.cE]()
        )
    )
    cdef __StructSpec spec = __StructSpec._fbthrift_create(
        name="E",
        kind=__StructType.EXCEPTION,
        annotations={
        },
    )
    return spec
