#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cython.operator cimport dereference as deref
from libcpp.utility cimport move as cmove
from thrift.py3.types cimport (
    assign_unique_ptr,
    assign_shared_ptr,
    assign_shared_const_ptr,
    bytes_to_string,
    make_unique,
)
cimport thrift.py3.types
from thrift.py3.types cimport (
    reset_field as __reset_field,
    StructFieldsSetter as __StructFieldsSetter
)

from thrift.py3.types cimport const_pointer_cast, BadEnum as _fbthrift_BadEnum


@__cython.auto_pickle(False)
cdef class __GeneratePatch_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __GeneratePatch_FieldsSetter _fbthrift_create(_apache_thrift_op_patch_types.cGeneratePatch* struct_cpp_obj):
        cdef __GeneratePatch_FieldsSetter __fbthrift_inst = __GeneratePatch_FieldsSetter.__new__(__GeneratePatch_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        return __fbthrift_inst

    cdef void set_field(__GeneratePatch_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __GeneratePatch_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)


@__cython.auto_pickle(False)
cdef class __GeneratePatchNew_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __GeneratePatchNew_FieldsSetter _fbthrift_create(_apache_thrift_op_patch_types.cGeneratePatchNew* struct_cpp_obj):
        cdef __GeneratePatchNew_FieldsSetter __fbthrift_inst = __GeneratePatchNew_FieldsSetter.__new__(__GeneratePatchNew_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        return __fbthrift_inst

    cdef void set_field(__GeneratePatchNew_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __GeneratePatchNew_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)


@__cython.auto_pickle(False)
cdef class __AssignOnlyPatch_FieldsSetter(__StructFieldsSetter):

    @staticmethod
    cdef __AssignOnlyPatch_FieldsSetter _fbthrift_create(_apache_thrift_op_patch_types.cAssignOnlyPatch* struct_cpp_obj):
        cdef __AssignOnlyPatch_FieldsSetter __fbthrift_inst = __AssignOnlyPatch_FieldsSetter.__new__(__AssignOnlyPatch_FieldsSetter)
        __fbthrift_inst._struct_cpp_obj = struct_cpp_obj
        return __fbthrift_inst

    cdef void set_field(__AssignOnlyPatch_FieldsSetter self, const char* name, object value) except *:
        cdef __cstring_view cname = __cstring_view(name)
        cdef cumap[__cstring_view, __AssignOnlyPatch_FieldsSetterFunc].iterator found = self._setters.find(cname)
        if found == self._setters.end():
            raise TypeError(f"invalid field name {name.decode('utf-8')}")
        deref(found).second(self, value)

