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

import thrift.annotation.thrift.ttypes


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

__all__ = ['UTF8STRINGS', 'MyEnum', 'MyStruct', 'MyUnion']

class MyEnum:
  MyValue1 = 0
  MyValue2 = 1

  _VALUES_TO_NAMES = {
    0: "MyValue1",
    1: "MyValue2",
  }

  _NAMES_TO_VALUES = {
    "MyValue1": 0,
    "MyValue2": 1,
  }

class MyStruct:
  r"""
  Attributes:
   - myIntField
   - myStringField
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
        if ftype == TType.I64:
          self.myIntField = iprot.readI64()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRING:
          self.myStringField = iprot.readString().decode('utf-8') if UTF8STRINGS else iprot.readString()
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
    oprot.writeStructBegin('MyStruct')
    if self.myIntField != None:
      oprot.writeFieldBegin('myIntField', TType.I64, 1)
      oprot.writeI64(self.myIntField)
      oprot.writeFieldEnd()
    if self.myStringField != None:
      oprot.writeFieldBegin('myStringField', TType.STRING, 2)
      oprot.writeString(self.myStringField.encode('utf-8')) if UTF8STRINGS and not isinstance(self.myStringField, bytes) else oprot.writeString(self.myStringField)
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
    if 'myIntField' in json_obj and json_obj['myIntField'] is not None:
      self.myIntField = long(json_obj['myIntField'])
    if 'myStringField' in json_obj and json_obj['myStringField'] is not None:
      self.myStringField = json_obj['myStringField']

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.myIntField is not None:
      value = pprint.pformat(self.myIntField, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    myIntField=%s' % (value))
    if self.myStringField is not None:
      value = pprint.pformat(self.myStringField, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    myStringField=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'myIntField',
      'myStringField',
    )

  # Override the __hash__ function for Python3 - t10434117
  __hash__ = object.__hash__

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("test.fixtures.basic.module.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.MyStruct, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("test.fixtures.basic.module.types")
    return thrift.py3.converter.to_py3_struct(py3_types.MyStruct, self)

  def _to_py_deprecated(self):
    return self

class MyUnion(object):
  r"""
  Attributes:
   - myEnum
   - myDataItem
  """

  thrift_spec = None
  __init__ = None

  __EMPTY__ = 0
  MYENUM = 1
  MYDATAITEM = 2
  
  @staticmethod
  def isUnion():
    return True

  def get_myEnum(self):
    assert self.field == 1
    return self.value

  def get_myDataItem(self):
    assert self.field == 2
    return self.value

  def set_myEnum(self, value):
    self.field = 1
    self.value = value

  def set_myDataItem(self, value):
    self.field = 2
    self.value = value

  def getType(self):
    return self.field

  def __repr__(self):
    value = pprint.pformat(self.value)
    member = ''
    if self.field == 1:
      padding = ' ' * 7
      value = padding.join(value.splitlines(True))
      member = '\n    %s=%s' % ('myEnum', value)
    if self.field == 2:
      padding = ' ' * 11
      value = padding.join(value.splitlines(True))
      member = '\n    %s=%s' % ('myDataItem', value)
    return "%s(%s)" % (self.__class__.__name__, member)

  def read(self, iprot):
    self.field = 0
    self.value = None
    if (isinstance(iprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, True], utf8strings=UTF8STRINGS, protoid=0)
      return
    if (isinstance(iprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(iprot, THeaderProtocol.THeaderProtocolAccelerate) and iprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastproto is not None:
      fastproto.decode(self, iprot.trans, [self.__class__, self.thrift_spec, True], utf8strings=UTF8STRINGS, protoid=2)
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break

      if fid == 1:
        if ftype == TType.I32:
          _fbthrift_myEnum = iprot.readI32()
          assert self.field == 0 and self.value is None
          self.set_myEnum(_fbthrift_myEnum)
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRUCT:
          _fbthrift_myDataItem = MyStruct()
          _fbthrift_myDataItem.read(iprot)
          assert self.field == 0 and self.value is None
          self.set_myDataItem(_fbthrift_myDataItem)
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if (isinstance(oprot, TBinaryProtocol.TBinaryProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_BINARY_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, True], utf8strings=UTF8STRINGS, protoid=0))
      return
    if (isinstance(oprot, TCompactProtocol.TCompactProtocolAccelerated) or (isinstance(oprot, THeaderProtocol.THeaderProtocolAccelerate) and oprot.get_protocol_id() == THeaderProtocol.THeaderProtocol.T_COMPACT_PROTOCOL)) and self.thrift_spec is not None and fastproto is not None:
      oprot.trans.write(fastproto.encode(self, [self.__class__, self.thrift_spec, True], utf8strings=UTF8STRINGS, protoid=2))
      return
    oprot.writeUnionBegin('MyUnion')
    if self.field == 1:
      oprot.writeFieldBegin('myEnum', TType.I32, 1)
      myEnum = self.value
      oprot.writeI32(myEnum)
      oprot.writeFieldEnd()
    if self.field == 2:
      oprot.writeFieldBegin('myDataItem', TType.STRUCT, 2)
      myDataItem = self.value
      myDataItem.write(oprot)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeUnionEnd()
  
  def readFromJson(self, json, is_text=True, **kwargs):
    relax_enum_validation = bool(kwargs.pop('relax_enum_validation', False))
    set_cls = kwargs.pop('custom_set_cls', set)
    dict_cls = kwargs.pop('custom_dict_cls', dict)
    if kwargs:
        extra_kwargs = ', '.join(kwargs.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    self.field = 0
    self.value = None
    obj = json
    if is_text:
      obj = loads(json)
    if not isinstance(obj, dict) or len(obj) > 1:
      raise TProtocolException(TProtocolException.INVALID_DATA, 'Can not parse')
    
    if 'myEnum' in obj:
      _fbthrift_myEnum = obj['myEnum']
      if not _fbthrift_myEnum in MyEnum._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type MyEnum' % _fbthrift_myEnum
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      self.set_myEnum(_fbthrift_myEnum)
    if 'myDataItem' in obj:
      _fbthrift_myDataItem = MyStruct()
      _fbthrift_myDataItem.readFromJson(obj['myDataItem'], is_text=False, relax_enum_validation=relax_enum_validation, custom_set_cls=set_cls, custom_dict_cls=dict_cls)
      self.set_myDataItem(_fbthrift_myDataItem)

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__

  def __ne__(self, other):
    return not (self == other)

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("test.fixtures.basic.module.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.MyUnion, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("test.fixtures.basic.module.types")
    return thrift.py3.converter.to_py3_struct(py3_types.MyUnion, self)

  def _to_py_deprecated(self):
    return self

all_structs.append(MyStruct)
MyStruct.thrift_spec = (
  None, # 0
  (1, TType.I64, 'myIntField', None, None, 2, ), # 1
  (2, TType.STRING, 'myStringField', True, None, 2, ), # 2
)

MyStruct.thrift_struct_annotations = {
}
MyStruct.thrift_field_annotations = {
}

def MyStruct__init__(self, myIntField=None, myStringField=None,):
  self.myIntField = myIntField
  self.myStringField = myStringField

MyStruct.__init__ = MyStruct__init__

def MyStruct__setstate__(self, state):
  state.setdefault('myIntField', None)
  state.setdefault('myStringField', None)
  self.__dict__ = state

MyStruct.__getstate__ = lambda self: self.__dict__.copy()
MyStruct.__setstate__ = MyStruct__setstate__

all_structs.append(MyUnion)
MyUnion.thrift_spec = (
  None, # 0
  (1, TType.I32, 'myEnum', MyEnum, None, 2, ), # 1
  (2, TType.STRUCT, 'myDataItem', [MyStruct, MyStruct.thrift_spec, False], None, 2, ), # 2
)

MyUnion.thrift_struct_annotations = {
}
MyUnion.thrift_field_annotations = {
}

def MyUnion__init__(self, myEnum=None, myDataItem=None,):
  self.field = 0
  self.value = None
  if myEnum is not None:
    assert self.field == 0 and self.value is None
    self.field = 1
    self.value = myEnum
  if myDataItem is not None:
    assert self.field == 0 and self.value is None
    self.field = 2
    self.value = myDataItem

MyUnion.__init__ = MyUnion__init__

fix_spec(all_structs)
del all_structs
