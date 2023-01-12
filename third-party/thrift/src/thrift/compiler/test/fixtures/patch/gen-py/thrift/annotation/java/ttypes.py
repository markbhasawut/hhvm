#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from __future__ import absolute_import
import sys
from thrift.util.Recursive import fix_spec
from thrift.Thrift import TType, TMessageType, TPriority, TRequestContext, TProcessorEventHandler, TServerInterface, TProcessor, TException, TApplicationException, UnimplementedTypedef
from thrift.protocol.TProtocol import TProtocolException

from json import loads
import sys
if sys.version_info[0] >= 3:
  long = int

import thrift.annotation.scope.ttypes


import pprint
import warnings
from thrift import Thrift
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.protocol import TCompactProtocol
from thrift.protocol import THeaderProtocol
fastproto = None
try:
  from thrift.protocol import fastproto
except ImportError:
  pass
all_structs = []
UTF8STRINGS = bool(0) or sys.version_info.major >= 3

__all__ = ['UTF8STRINGS', 'Adapter', 'Wrapper']

class Adapter:
  r"""
  Attributes:
   - adapterClassName
   - typeClassName
  """

  thrift_spec = None
  thrift_field_annotations = None
  thrift_struct_annotations = None
  __init__ = None
  @staticmethod
  def isUnion():
    return False

  def read(self, iprot):
    if (isinstance(iprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0)
      return
    if (isinstance(iprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2)
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.STRING:
          self.adapterClassName = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRING:
          self.typeClassName = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if (isinstance(oprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0))
      return
    if (isinstance(oprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2))
      return
    oprot.writeStructBegin('Adapter')
    if self.adapterClassName != None:
      oprot.writeFieldBegin('adapterClassName', TType.STRING, 1)
      oprot.writeString(self.adapterClassName.encode('utf-8')) if UTF8STRINGS and not isinstance(self.adapterClassName, bytes) else oprot.writeString(self.adapterClassName)
      oprot.writeFieldEnd()
    if self.typeClassName != None:
      oprot.writeFieldBegin('typeClassName', TType.STRING, 2)
      oprot.writeString(self.typeClassName.encode('utf-8')) if UTF8STRINGS and not isinstance(self.typeClassName, bytes) else oprot.writeString(self.typeClassName)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    relax_enum_validation = bool(kwargs.pop('relax_enum_validation', False))
    set_cls = kwargs.pop('custom_set_cls', set)
    dict_cls = kwargs.pop('custom_dict_cls', dict)
    if kwargs:
        extra_kwargs = ', '.join(kwargs.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'adapterClassName' in json_obj and json_obj['adapterClassName'] is not None:
      self.adapterClassName = json_obj['adapterClassName']
    if 'typeClassName' in json_obj and json_obj['typeClassName'] is not None:
      self.typeClassName = json_obj['typeClassName']

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.adapterClassName is not None:
      value = pprint.pformat(self.adapterClassName, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    adapterClassName=%s' % (value))
    if self.typeClassName is not None:
      value = pprint.pformat(self.typeClassName, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    typeClassName=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'adapterClassName',
      'typeClassName',
    )

  # Override the __hash__ function for Python3 - t10434117
  __hash__ = object.__hash__

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("facebook.thrift.annotation.java.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.Adapter, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("facebook.thrift.annotation.java.types")
    return thrift.py3.converter.to_py3_struct(py3_types.Adapter, self)

  def _to_py_deprecated(self):
    return self

class Wrapper:
  r"""
  Attributes:
   - wrapperClassName
   - typeClassName
  """

  thrift_spec = None
  thrift_field_annotations = None
  thrift_struct_annotations = None
  __init__ = None
  @staticmethod
  def isUnion():
    return False

  def read(self, iprot):
    if (isinstance(iprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0)
      return
    if (isinstance(iprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2)
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.STRING:
          self.wrapperClassName = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRING:
          self.typeClassName = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if (isinstance(oprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=0))
      return
    if (isinstance(oprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, False], utf8strings=UTF8STRINGS, protoid=2))
      return
    oprot.writeStructBegin('Wrapper')
    if self.wrapperClassName != None:
      oprot.writeFieldBegin('wrapperClassName', TType.STRING, 1)
      oprot.writeString(self.wrapperClassName.encode('utf-8')) if UTF8STRINGS and not isinstance(self.wrapperClassName, bytes) else oprot.writeString(self.wrapperClassName)
      oprot.writeFieldEnd()
    if self.typeClassName != None:
      oprot.writeFieldBegin('typeClassName', TType.STRING, 2)
      oprot.writeString(self.typeClassName.encode('utf-8')) if UTF8STRINGS and not isinstance(self.typeClassName, bytes) else oprot.writeString(self.typeClassName)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    relax_enum_validation = bool(kwargs.pop('relax_enum_validation', False))
    set_cls = kwargs.pop('custom_set_cls', set)
    dict_cls = kwargs.pop('custom_dict_cls', dict)
    if kwargs:
        extra_kwargs = ', '.join(kwargs.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'wrapperClassName' in json_obj and json_obj['wrapperClassName'] is not None:
      self.wrapperClassName = json_obj['wrapperClassName']
    if 'typeClassName' in json_obj and json_obj['typeClassName'] is not None:
      self.typeClassName = json_obj['typeClassName']

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.wrapperClassName is not None:
      value = pprint.pformat(self.wrapperClassName, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    wrapperClassName=%s' % (value))
    if self.typeClassName is not None:
      value = pprint.pformat(self.typeClassName, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    typeClassName=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'wrapperClassName',
      'typeClassName',
    )

  # Override the __hash__ function for Python3 - t10434117
  __hash__ = object.__hash__

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("facebook.thrift.annotation.java.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.Wrapper, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("facebook.thrift.annotation.java.types")
    return thrift.py3.converter.to_py3_struct(py3_types.Wrapper, self)

  def _to_py_deprecated(self):
    return self

all_structs.append(Adapter)
Adapter.thrift_spec = (
  None, # 0
  (1, TType.STRING, 'adapterClassName', True, None, 2, ), # 1
  (2, TType.STRING, 'typeClassName', True, None, 2, ), # 2
)

Adapter.thrift_struct_annotations = {
  "thrift.uri": "facebook.com/thrift/annotation/java/Adapter",
}
Adapter.thrift_field_annotations = {
}

def Adapter__init__(self, adapterClassName=None, typeClassName=None,):
  self.adapterClassName = adapterClassName
  self.typeClassName = typeClassName

Adapter.__init__ = Adapter__init__

def Adapter__setstate__(self, state):
  state.setdefault('adapterClassName', None)
  state.setdefault('typeClassName', None)
  self.__dict__ = state

Adapter.__getstate__ = lambda self: self.__dict__.copy()
Adapter.__setstate__ = Adapter__setstate__

all_structs.append(Wrapper)
Wrapper.thrift_spec = (
  None, # 0
  (1, TType.STRING, 'wrapperClassName', True, None, 2, ), # 1
  (2, TType.STRING, 'typeClassName', True, None, 2, ), # 2
)

Wrapper.thrift_struct_annotations = {
  "thrift.uri": "facebook.com/thrift/annotation/java/Wrapper",
}
Wrapper.thrift_field_annotations = {
}

def Wrapper__init__(self, wrapperClassName=None, typeClassName=None,):
  self.wrapperClassName = wrapperClassName
  self.typeClassName = typeClassName

Wrapper.__init__ = Wrapper__init__

def Wrapper__setstate__(self, state):
  state.setdefault('wrapperClassName', None)
  state.setdefault('typeClassName', None)
  self.__dict__ = state

Wrapper.__getstate__ = lambda self: self.__dict__.copy()
Wrapper.__setstate__ = Wrapper__setstate__

fix_spec(all_structs)
del all_structs
