
#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from thrift.python.capi.cpp_converter cimport cpp_to_python, python_to_cpp
from libcpp.utility cimport move as cmove

cdef extern from "thrift/compiler/test/fixtures/python_capi/gen-python-capi/containers/thrift_types_capi.h":
    pass

cdef cTemplateLists TemplateLists_convert_to_cpp(object inst) except *:
    return cmove(python_to_cpp[cTemplateLists](inst))

cdef object TemplateLists_from_cpp(const cTemplateLists& c_struct):
    return cpp_to_python[cTemplateLists](c_struct)

