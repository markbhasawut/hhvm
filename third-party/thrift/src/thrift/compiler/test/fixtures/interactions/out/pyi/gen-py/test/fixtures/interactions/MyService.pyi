#
# Autogenerated by Thrift for 
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
import typing as __T

from thrift import Thrift
from thrift.protocol.TProtocol import TProtocolBase

import test.fixtures.another_interactions.ttypes
from test.fixtures.interactions.ttypes import *


class Iface:  # MyService
    def foo(self) -> None: ...
    def interact(self, arg: int) -> None: ...
    def interactFast(self) -> int: ...

class Client(Iface, __T.ContextManager[Client]):  # MyService
    def __init__(self, iprot: __T.Optional[TProtocolBase], oprot: __T.Optional[TProtocolBase] = None, cpp_transport: __T.Optional[__T.TypeVar("SyncClient")] = None) -> None: ...
    def set_persistent_header(self, key: str, value: str) -> None: ...
    def get_persistent_headers(self) -> __T.Mapping[str, str]: ...
    def clear_persistent_headers(self) -> None: ...
    def set_onetime_header(self, key: str, value: str) -> None: ...
    def get_last_response_headers(self) -> __T.Mapping[str, str]: ...
    def set_max_frame_size(self, size: int) -> None: ...
    def send_foo(self) -> None: ...
    def recv_foo(self) -> None: ...
    def send_interact(self, arg: __T.Optional[int] = ...) -> None: ...
    def recv_interact(self) -> None: ...
    def send_interactFast(self) -> None: ...
    def recv_interactFast(self) -> int: ...

class Processor(Iface, Thrift.TProcessor):  # MyService
    def __init__(self, handler: Iface) -> None:
        self._handler: Iface
        self._onewayMethods: __T.Sequence[__T.Callable]
        self._processMap: __T.Dict[str, __T.Callable]

    def process_foo(self, seqid: int, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> None: ...
    def process_interact(self, seqid: int, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> None: ...
    def process_interactFast(self, seqid: int, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> None: ...
    def process_main(self, iprot: TProtocolBase, oprot: TProtocolBase, server_ctx: __T.Any = ...) -> __T.Optional[bool]: ...
    def onewayMethods(self) -> __T.Tuple[__T.Callable]: ...

class foo_args:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self
    ) -> None:
        ...

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class foo_result:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(self, success: None = ...) -> None:
        self.success: None

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class interact_args:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        arg: __T.Optional[int] = ...
    ) -> None:
        self.arg: __T.Optional[int]

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class interact_result:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(self, success: None = ...) -> None:
        self.success: None

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class interactFast_args:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self
    ) -> None:
        ...

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...

class interactFast_result:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(self, success: int = ...) -> None:
        self.success: int

    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
