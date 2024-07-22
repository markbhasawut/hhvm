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

import module.thrift_types
import module.thrift_metadata
import apache.thrift.type.schema.thrift_types

class PrimitivesServiceInterface(
    ServiceInterface,
    metaclass=ABCMeta
):

    @staticmethod
    def service_name() -> bytes:
        return b"PrimitivesService"

    def getFunctionTable(self) -> _typing.Mapping[bytes, _typing.Callable[..., object]]:
        functionTable = {
            b"init": (RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE, self._fbthrift__handler_init),
            b"method_that_throws": (RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE, self._fbthrift__handler_method_that_throws),
            b"return_void_method": (RpcKind.SINGLE_REQUEST_SINGLE_RESPONSE, self._fbthrift__handler_return_void_method),
        }
        return {**super().getFunctionTable(), **functionTable}

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.PrimitivesService"

    @staticmethod
    def __get_metadata__() -> _fbthrift_metadata.ThriftMetadata:
        return module.thrift_metadata.gen_metadata_service_PrimitivesService()

    @staticmethod
    def __get_metadata_service_response__() -> _fbthrift_metadata.ThriftServiceMetadataResponse:
        return module.thrift_metadata._fbthrift_metadata_service_response_PrimitivesService()



    async def init(
            self,
            param0: int,
            param1: int
        ) -> int:
        raise NotImplementedError("async def init is not implemented")

    async def _fbthrift__handler_init(self, args: _fbthrift_iobuf.IOBuf, protocol: Protocol) -> _fbthrift_iobuf.IOBuf:
        args_struct = deserialize(module.thrift_types._fbthrift_PrimitivesService_init_args, args, protocol)
        value = await self.init(args_struct.param0,args_struct.param1,)
        return_struct = module.thrift_types._fbthrift_PrimitivesService_init_result(success=value)
        

        return serialize_iobuf(return_struct, protocol)


    async def method_that_throws(
            self
        ) -> module.thrift_types.Result:
        raise NotImplementedError("async def method_that_throws is not implemented")

    async def _fbthrift__handler_method_that_throws(self, args: _fbthrift_iobuf.IOBuf, protocol: Protocol) -> _fbthrift_iobuf.IOBuf:
        args_struct = deserialize(module.thrift_types._fbthrift_PrimitivesService_method_that_throws_args, args, protocol)
        try:
            value = await self.method_that_throws()
            return_struct = module.thrift_types._fbthrift_PrimitivesService_method_that_throws_result(success=value)
            
        except module.thrift_types.CustomException as e:
            return_struct = module.thrift_types._fbthrift_PrimitivesService_method_that_throws_result(e=e)
            buf = serialize_iobuf(return_struct, protocol)
            exp = PythonUserException('CustomException', str(e), buf)
            raise exp


        return serialize_iobuf(return_struct, protocol)


    async def return_void_method(
            self,
            id: int
        ) -> None:
        raise NotImplementedError("async def return_void_method is not implemented")

    async def _fbthrift__handler_return_void_method(self, args: _fbthrift_iobuf.IOBuf, protocol: Protocol) -> _fbthrift_iobuf.IOBuf:
        args_struct = deserialize(module.thrift_types._fbthrift_PrimitivesService_return_void_method_args, args, protocol)
        value = await self.return_void_method(args_struct.id,)
        return_struct = module.thrift_types._fbthrift_PrimitivesService_return_void_method_result()
        

        return serialize_iobuf(return_struct, protocol)

