#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

# pyre-unsafe

import typing as __T  # sometimes `t` is used as a field name

from thrift import Thrift
from thrift.protocol.TProtocol import TProtocolBase

__property__ = property  # sometimes `property` is used as a field name


UTF8STRINGS: bool


class Ord:
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
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "facebook.thrift.annotation.rust.thrift_types.Ord": ...   # type: ignore
    def _to_py3(self) -> "facebook.thrift.annotation.rust.types.Ord": ...   # type: ignore
    def _to_py_deprecated(self) -> Ord: ...


class NewType:
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
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "facebook.thrift.annotation.rust.thrift_types.NewType": ...   # type: ignore
    def _to_py3(self) -> "facebook.thrift.annotation.rust.types.NewType": ...   # type: ignore
    def _to_py_deprecated(self) -> NewType: ...


class Type:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        name: __T.Optional[str] = ...
    ) -> None:
        ...

    @__property__
    def name(self) -> str: ...
    @name.setter
    def name(self, value: __T.Optional[str]) -> None: ...


    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "facebook.thrift.annotation.rust.thrift_types.Type": ...   # type: ignore
    def _to_py3(self) -> "facebook.thrift.annotation.rust.types.Type": ...   # type: ignore
    def _to_py_deprecated(self) -> Type: ...


class Adapter:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        name: __T.Optional[str] = ...
    ) -> None:
        ...

    @__property__
    def name(self) -> str: ...
    @name.setter
    def name(self, value: __T.Optional[str]) -> None: ...


    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "facebook.thrift.annotation.rust.thrift_types.Adapter": ...   # type: ignore
    def _to_py3(self) -> "facebook.thrift.annotation.rust.types.Adapter": ...   # type: ignore
    def _to_py_deprecated(self) -> Adapter: ...


class Derive:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        derives: __T.Optional[__T.List[str]] = ...
    ) -> None:
        ...

    @__property__
    def derives(self) -> __T.List[str]: ...
    @derives.setter
    def derives(self, value: __T.Optional[__T.List[str]]) -> None: ...


    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "facebook.thrift.annotation.rust.thrift_types.Derive": ...   # type: ignore
    def _to_py3(self) -> "facebook.thrift.annotation.rust.types.Derive": ...   # type: ignore
    def _to_py_deprecated(self) -> Derive: ...


class ServiceExn:
    thrift_spec: __T.Tuple[__T.Optional[__T.Tuple[int, int, str, __T.Any, __T.Optional[int], int]]]
    thrift_field_annotations: __T.Dict[int, __T.Dict[str, str]]
    thrift_struct_annotations: __T.Dict[str, str]

    def __init__(
        self,
        anyhow_to_application_exn: __T.Optional[bool] = ...
    ) -> None:
        ...

    @__property__
    def anyhow_to_application_exn(self) -> bool: ...
    @anyhow_to_application_exn.setter
    def anyhow_to_application_exn(self, value: __T.Optional[bool]) -> None: ...


    def isUnion(self) -> bool: ...
    def checkRequired(self) -> None: ...
    def read(self, iprot: TProtocolBase) -> None: ...
    @__T.overload
    def readFromJson(self, json: __T.Dict[str, __T.Any], is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    @__T.overload
    def readFromJson(self, json: str, is_text: bool = ..., **kwargs: __T.Any) -> None: ...
    def write(self, oprot: TProtocolBase) -> None: ...
    def __eq__(self, other: __T.Any) -> bool: ...
    def __ne__(self, other: __T.Any) -> bool: ...
    def __dir__(self) -> __T.Sequence[str]: ...
    def _to_python(self) -> "facebook.thrift.annotation.rust.thrift_types.ServiceExn": ...   # type: ignore
    def _to_py3(self) -> "facebook.thrift.annotation.rust.types.ServiceExn": ...   # type: ignore
    def _to_py_deprecated(self) -> ServiceExn: ...


