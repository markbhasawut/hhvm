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

def __EXPAND_THRIFT_SPEC(spec):
    next_id = 0
    for item in spec:
        item_id = item[0]
        if next_id >= 0 and item_id < 0:
            next_id = item_id
        if item_id != next_id:
            for _ in range(next_id, item_id):
                yield None
        yield item
        next_id = item_id + 1

class ThriftEnumWrapper(int):
  def __new__(cls, enum_class, value):
    return super().__new__(cls, value)
  def __init__(self, enum_class, value):    self.enum_class = enum_class
  def __repr__(self):
    return self.enum_class.__name__ + '.' + self.enum_class._VALUES_TO_NAMES[self]

all_structs = []
UTF8STRINGS = bool(0) or sys.version_info.major >= 3

__all__ = ['UTF8STRINGS', 'Metasyntactic', 'MyEnum1', 'MyEnum2', 'MyEnum3', 'MyEnum4', 'MyBitmaskEnum1', 'MyBitmaskEnum2', 'SomeStruct', 'MyStruct']

class Metasyntactic:
  FOO = 1
  BAR = 2
  BAZ = 3
  BAX = 4

  _VALUES_TO_NAMES = {
    1: "FOO",
    2: "BAR",
    3: "BAZ",
    4: "BAX",
  }

  _NAMES_TO_VALUES = {
    "FOO": 1,
    "BAR": 2,
    "BAZ": 3,
    "BAX": 4,
  }

class MyEnum1:
  ME1_0 = 0
  ME1_1 = 1
  ME1_2 = 2
  ME1_3 = 3
  ME1_5 = 5
  ME1_6 = 6

  _VALUES_TO_NAMES = {
    0: "ME1_0",
    1: "ME1_1",
    2: "ME1_2",
    3: "ME1_3",
    5: "ME1_5",
    6: "ME1_6",
  }

  _NAMES_TO_VALUES = {
    "ME1_0": 0,
    "ME1_1": 1,
    "ME1_2": 2,
    "ME1_3": 3,
    "ME1_5": 5,
    "ME1_6": 6,
  }

class MyEnum2:
  ME2_0 = 0
  ME2_1 = 1
  ME2_2 = 2

  _VALUES_TO_NAMES = {
    0: "ME2_0",
    1: "ME2_1",
    2: "ME2_2",
  }

  _NAMES_TO_VALUES = {
    "ME2_0": 0,
    "ME2_1": 1,
    "ME2_2": 2,
  }

class MyEnum3:
  ME3_0 = 0
  ME3_1 = 1
  ME3_N2 = -2
  ME3_N1 = -1
  ME3_9 = 9
  ME3_10 = 10

  _VALUES_TO_NAMES = {
    0: "ME3_0",
    1: "ME3_1",
    -2: "ME3_N2",
    -1: "ME3_N1",
    9: "ME3_9",
    10: "ME3_10",
  }

  _NAMES_TO_VALUES = {
    "ME3_0": 0,
    "ME3_1": 1,
    "ME3_N2": -2,
    "ME3_N1": -1,
    "ME3_9": 9,
    "ME3_10": 10,
  }

class MyEnum4:
  ME4_A = 2147483645
  ME4_B = 2147483646
  ME4_C = 2147483647
  ME4_D = -2147483648

  _VALUES_TO_NAMES = {
    2147483645: "ME4_A",
    2147483646: "ME4_B",
    2147483647: "ME4_C",
    -2147483648: "ME4_D",
  }

  _NAMES_TO_VALUES = {
    "ME4_A": 2147483645,
    "ME4_B": 2147483646,
    "ME4_C": 2147483647,
    "ME4_D": -2147483648,
  }

class MyBitmaskEnum1:
  ONE = 1
  TWO = 2
  FOUR = 4

  _VALUES_TO_NAMES = {
    1: "ONE",
    2: "TWO",
    4: "FOUR",
  }

  _NAMES_TO_VALUES = {
    "ONE": 1,
    "TWO": 2,
    "FOUR": 4,
  }

class MyBitmaskEnum2:
  ONE = 1
  TWO = 2
  FOUR = 4

  _VALUES_TO_NAMES = {
    1: "ONE",
    2: "TWO",
    4: "FOUR",
  }

  _NAMES_TO_VALUES = {
    "ONE": 1,
    "TWO": 2,
    "FOUR": 4,
  }

class SomeStruct:
  r"""
  Attributes:
   - reasonable
   - fine
   - questionable
   - tags
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
        if ftype == TType.I32:
          self.reasonable = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.I32:
          self.fine = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 3:
        if ftype == TType.I32:
          self.questionable = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 4:
        if ftype == TType.SET:
          self.tags = set()
          (_etype3, _size0) = iprot.readSetBegin()
          if _size0 >= 0:
            for _i4 in range(_size0):
              _elem5 = iprot.readI32()
              self.tags.add(_elem5)
          else: 
            while iprot.peekSet():
              _elem6 = iprot.readI32()
              self.tags.add(_elem6)
          iprot.readSetEnd()
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
    oprot.writeStructBegin('SomeStruct')
    if self.reasonable != None:
      oprot.writeFieldBegin('reasonable', TType.I32, 1)
      oprot.writeI32(self.reasonable)
      oprot.writeFieldEnd()
    if self.fine != None:
      oprot.writeFieldBegin('fine', TType.I32, 2)
      oprot.writeI32(self.fine)
      oprot.writeFieldEnd()
    if self.questionable != None:
      oprot.writeFieldBegin('questionable', TType.I32, 3)
      oprot.writeI32(self.questionable)
      oprot.writeFieldEnd()
    if self.tags != None:
      oprot.writeFieldBegin('tags', TType.SET, 4)
      oprot.writeSetBegin(TType.I32, len(self.tags))
      for iter7 in self.tags:
        oprot.writeI32(iter7)
      oprot.writeSetEnd()
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    kwargs_copy = dict(kwargs)
    relax_enum_validation = bool(kwargs_copy.pop('relax_enum_validation', False))
    set_cls = kwargs_copy.pop('custom_set_cls', set)
    dict_cls = kwargs_copy.pop('custom_dict_cls', dict)
    wrap_enum_constants = kwargs_copy.pop('wrap_enum_constants', False)
    if wrap_enum_constants and relax_enum_validation:
        raise ValueError(
            'wrap_enum_constants cannot be used together with relax_enum_validation'
        )
    if kwargs_copy:
        extra_kwargs = ', '.join(kwargs_copy.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'reasonable' in json_obj and json_obj['reasonable'] is not None:
      self.reasonable = json_obj['reasonable']
      if not self.reasonable in Metasyntactic._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type Metasyntactic' % self.reasonable
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.reasonable = ThriftEnumWrapper(Metasyntactic, self.reasonable)
    if 'fine' in json_obj and json_obj['fine'] is not None:
      self.fine = json_obj['fine']
      if not self.fine in Metasyntactic._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type Metasyntactic' % self.fine
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.fine = ThriftEnumWrapper(Metasyntactic, self.fine)
    if 'questionable' in json_obj and json_obj['questionable'] is not None:
      self.questionable = json_obj['questionable']
      if not self.questionable in Metasyntactic._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type Metasyntactic' % self.questionable
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.questionable = ThriftEnumWrapper(Metasyntactic, self.questionable)
    if 'tags' in json_obj and json_obj['tags'] is not None:
      self.tags = set_cls()
      for _tmp_e8 in json_obj['tags']:
        if _tmp_e8 > 0x7fffffff or _tmp_e8 < -0x80000000:
          raise TProtocolException(TProtocolException.INVALID_DATA, 'number exceeds limit in field')
        self.tags.add(_tmp_e8)

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.reasonable is not None:
      value = pprint.pformat(self.reasonable, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    reasonable=%s' % (value))
    if self.fine is not None:
      value = pprint.pformat(self.fine, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    fine=%s' % (value))
    if self.questionable is not None:
      value = pprint.pformat(self.questionable, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    questionable=%s' % (value))
    if self.tags is not None:
      value = pprint.pformat(self.tags, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    tags=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'reasonable',
      'fine',
      'questionable',
      'tags',
    )

  __hash__ = object.__hash__

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("test.fixtures.enums.module.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.SomeStruct, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("test.fixtures.enums.module.types")
    return thrift.py3.converter.to_py3_struct(py3_types.SomeStruct, self)

  def _to_py_deprecated(self):
    return self

class MyStruct:
  r"""
  Attributes:
   - me2_3
   - me3_n3
   - me1_t1
   - me1_t2
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
        if ftype == TType.I32:
          self.me2_3 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.I32:
          self.me3_n3 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 4:
        if ftype == TType.I32:
          self.me1_t1 = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 6:
        if ftype == TType.I32:
          self.me1_t2 = iprot.readI32()
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
    if self.me2_3 != None:
      oprot.writeFieldBegin('me2_3', TType.I32, 1)
      oprot.writeI32(self.me2_3)
      oprot.writeFieldEnd()
    if self.me3_n3 != None:
      oprot.writeFieldBegin('me3_n3', TType.I32, 2)
      oprot.writeI32(self.me3_n3)
      oprot.writeFieldEnd()
    if self.me1_t1 != None:
      oprot.writeFieldBegin('me1_t1', TType.I32, 4)
      oprot.writeI32(self.me1_t1)
      oprot.writeFieldEnd()
    if self.me1_t2 != None:
      oprot.writeFieldBegin('me1_t2', TType.I32, 6)
      oprot.writeI32(self.me1_t2)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def readFromJson(self, json, is_text=True, **kwargs):
    kwargs_copy = dict(kwargs)
    relax_enum_validation = bool(kwargs_copy.pop('relax_enum_validation', False))
    set_cls = kwargs_copy.pop('custom_set_cls', set)
    dict_cls = kwargs_copy.pop('custom_dict_cls', dict)
    wrap_enum_constants = kwargs_copy.pop('wrap_enum_constants', False)
    if wrap_enum_constants and relax_enum_validation:
        raise ValueError(
            'wrap_enum_constants cannot be used together with relax_enum_validation'
        )
    if kwargs_copy:
        extra_kwargs = ', '.join(kwargs_copy.keys())
        raise ValueError(
            'Unexpected keyword arguments: ' + extra_kwargs
        )
    json_obj = json
    if is_text:
      json_obj = loads(json)
    if 'me2_3' in json_obj and json_obj['me2_3'] is not None:
      self.me2_3 = json_obj['me2_3']
      if not self.me2_3 in MyEnum2._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type MyEnum2' % self.me2_3
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.me2_3 = ThriftEnumWrapper(MyEnum2, self.me2_3)
    if 'me3_n3' in json_obj and json_obj['me3_n3'] is not None:
      self.me3_n3 = json_obj['me3_n3']
      if not self.me3_n3 in MyEnum3._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type MyEnum3' % self.me3_n3
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.me3_n3 = ThriftEnumWrapper(MyEnum3, self.me3_n3)
    if 'me1_t1' in json_obj and json_obj['me1_t1'] is not None:
      self.me1_t1 = json_obj['me1_t1']
      if not self.me1_t1 in MyEnum1._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type MyEnum1' % self.me1_t1
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.me1_t1 = ThriftEnumWrapper(MyEnum1, self.me1_t1)
    if 'me1_t2' in json_obj and json_obj['me1_t2'] is not None:
      self.me1_t2 = json_obj['me1_t2']
      if not self.me1_t2 in MyEnum1._VALUES_TO_NAMES:
        msg = 'Integer value ''%s'' is not a recognized value of enum type MyEnum1' % self.me1_t2
        if relax_enum_validation:
            warnings.warn(msg)
        else:
            raise TProtocolException(TProtocolException.INVALID_DATA, msg)
      if wrap_enum_constants:
        self.me1_t2 = ThriftEnumWrapper(MyEnum1, self.me1_t2)

  def __repr__(self):
    L = []
    padding = ' ' * 4
    if self.me2_3 is not None:
      value = pprint.pformat(self.me2_3, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    me2_3=%s' % (value))
    if self.me3_n3 is not None:
      value = pprint.pformat(self.me3_n3, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    me3_n3=%s' % (value))
    if self.me1_t1 is not None:
      value = pprint.pformat(self.me1_t1, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    me1_t1=%s' % (value))
    if self.me1_t2 is not None:
      value = pprint.pformat(self.me1_t2, indent=0)
      value = padding.join(value.splitlines(True))
      L.append('    me1_t2=%s' % (value))
    return "%s(%s)" % (self.__class__.__name__, "\n" + ",\n".join(L) if L else '')

  def __eq__(self, other):
    if not isinstance(other, self.__class__):
      return False

    return self.__dict__ == other.__dict__ 

  def __ne__(self, other):
    return not (self == other)

  def __dir__(self):
    return (
      'me2_3',
      'me3_n3',
      'me1_t1',
      'me1_t2',
    )

  __hash__ = object.__hash__

  def _to_python(self):
    import importlib
    import thrift.python.converter
    python_types = importlib.import_module("test.fixtures.enums.module.thrift_types")
    return thrift.python.converter.to_python_struct(python_types.MyStruct, self)

  def _to_py3(self):
    import importlib
    import thrift.py3.converter
    py3_types = importlib.import_module("test.fixtures.enums.module.types")
    return thrift.py3.converter.to_py3_struct(py3_types.MyStruct, self)

  def _to_py_deprecated(self):
    return self

all_structs.append(SomeStruct)
SomeStruct.thrift_spec = tuple(__EXPAND_THRIFT_SPEC((
  (1, TType.I32, 'reasonable', Metasyntactic,   1, 2, ), # 1
  (2, TType.I32, 'fine', Metasyntactic,   2, 2, ), # 2
  (3, TType.I32, 'questionable', Metasyntactic,   -1, 2, ), # 3
  (4, TType.SET, 'tags', (TType.I32,None), set([
  ]), 2, ), # 4
)))

SomeStruct.thrift_struct_annotations = {
}
SomeStruct.thrift_field_annotations = {
}

def SomeStruct__init__(self, reasonable=SomeStruct.thrift_spec[1][4], fine=SomeStruct.thrift_spec[2][4], questionable=SomeStruct.thrift_spec[3][4], tags=SomeStruct.thrift_spec[4][4],):
  self.reasonable = reasonable
  self.fine = fine
  self.questionable = questionable
  if tags is self.thrift_spec[4][4]:
    tags = set([
  ])
  self.tags = tags

SomeStruct.__init__ = SomeStruct__init__

def SomeStruct__setstate__(self, state):
  state.setdefault('reasonable',   1)
  state.setdefault('fine',   2)
  state.setdefault('questionable',   -1)
  state.setdefault('tags', set([
  ]))
  self.__dict__ = state

SomeStruct.__getstate__ = lambda self: self.__dict__.copy()
SomeStruct.__setstate__ = SomeStruct__setstate__

all_structs.append(MyStruct)
MyStruct.thrift_spec = tuple(__EXPAND_THRIFT_SPEC((
  (1, TType.I32, 'me2_3', MyEnum2,   3, 2, ), # 1
  (2, TType.I32, 'me3_n3', MyEnum3,   -3, 2, ), # 2
  (4, TType.I32, 'me1_t1', MyEnum1,   1, 2, ), # 4
  (6, TType.I32, 'me1_t2', MyEnum1,   1, 2, ), # 6
)))

MyStruct.thrift_struct_annotations = {
}
MyStruct.thrift_field_annotations = {
}

def MyStruct__init__(self, me2_3=MyStruct.thrift_spec[1][4], me3_n3=MyStruct.thrift_spec[2][4], me1_t1=MyStruct.thrift_spec[4][4], me1_t2=MyStruct.thrift_spec[6][4],):
  self.me2_3 = me2_3
  self.me3_n3 = me3_n3
  self.me1_t1 = me1_t1
  self.me1_t2 = me1_t2

MyStruct.__init__ = MyStruct__init__

def MyStruct__setstate__(self, state):
  state.setdefault('me2_3',   3)
  state.setdefault('me3_n3',   -3)
  state.setdefault('me1_t1',   1)
  state.setdefault('me1_t2',   1)
  self.__dict__ = state

MyStruct.__getstate__ = lambda self: self.__dict__.copy()
MyStruct.__setstate__ = MyStruct__setstate__

fix_spec(all_structs)
del all_structs
