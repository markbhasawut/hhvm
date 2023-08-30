#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

from abc import ABCMeta
import typing as _typing

import folly.iobuf as _fbthrift_iobuf

import apache.thrift.metadata.thrift_types as _fbthrift_metadata
from thrift.python.serializer import serialize_iobuf, deserialize, Protocol
from thrift.python.server import ServiceInterface, RpcKind, PythonUserException

import service.thrift_types
import service.thrift_metadata
import includes.thrift_types
import module.thrift_types
import transitive.thrift_types

class MyServiceInterface(
    ServiceInterface,
    metaclass=ABCMeta
):

    @staticmethod
    def service_name() -> bytes:
        return b"MyService"

    # pyre-ignore[3]: it can return anything
    def getFunctionTable(self) -> _typing.Mapping[bytes, _typing.Callable[..., _typing.Any]]:
        functionTable = {
            b"query": (RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE, self._fbthrift__handler_query),
            b"has_arg_docs": (RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE, self._fbthrift__handler_has_arg_docs),
        }
        return {**super().getFunctionTable(), **functionTable}

    @staticmethod
    def __get_thrift_name__() -> str:
        return "service.MyService"

    @staticmethod
    def __get_metadata__() -> _fbthrift_metadata.ThriftMetadata:
        return service.thrift_metadata.gen_metadata_service_MyService()

    @staticmethod
    def __get_metadata_service_response__() -> _fbthrift_metadata.ThriftServiceMetadataResponse:
        return service.thrift_metadata._fbthrift_metadata_service_response_MyService()



    async def query(
            self,
            s: module.thrift_types.MyStruct,
            i: includes.thrift_types.Included
        ) -> None:
        raise NotImplementedError("async def query is not implemented")

    async def _fbthrift__handler_query(self, args: _fbthrift_iobuf.IOBuf, protocol: Protocol) -> _fbthrift_iobuf.IOBuf:
        args_struct = deserialize(service.thrift_types._fbthrift_MyService_query_args, args, protocol)
        value = await self.query(args_struct.s,args_struct.i,)
        return_struct = service.thrift_types._fbthrift_MyService_query_result()

        return serialize_iobuf(return_struct, protocol)


    async def has_arg_docs(
            self,
            s: module.thrift_types.MyStruct,
            i: includes.thrift_types.Included
        ) -> None:
        raise NotImplementedError("async def has_arg_docs is not implemented")

    async def _fbthrift__handler_has_arg_docs(self, args: _fbthrift_iobuf.IOBuf, protocol: Protocol) -> _fbthrift_iobuf.IOBuf:
        args_struct = deserialize(service.thrift_types._fbthrift_MyService_has_arg_docs_args, args, protocol)
        value = await self.has_arg_docs(args_struct.s,args_struct.i,)
        return_struct = service.thrift_types._fbthrift_MyService_has_arg_docs_result()

        return serialize_iobuf(return_struct, protocol)

