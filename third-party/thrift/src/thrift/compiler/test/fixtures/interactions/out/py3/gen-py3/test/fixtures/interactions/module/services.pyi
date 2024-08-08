#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/interactions/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import folly.iobuf as _fbthrift_iobuf
import typing as _typing
from thrift.py3.server import RequestContext, ServiceInterface
from abc import abstractmethod, ABCMeta

import test.fixtures.interactions.module.types as _test_fixtures_interactions_module_types
import test.fixtures.another_interactions.shared.services as _test_fixtures_another_interactions_shared_services
import test.fixtures.another_interactions.shared.types as _test_fixtures_another_interactions_shared_types

_MyServiceInterfaceT = _typing.TypeVar('_MyServiceInterfaceT', bound='MyServiceInterface')


class MyServiceInterface(
    ServiceInterface,
    metaclass=ABCMeta,
):


    @abstractmethod
    async def foo(
        self
    ) -> None: ...


    @abstractmethod
    async def interact(
        self,
        arg: int
    ) -> None: ...


    @abstractmethod
    async def interactFast(
        self
    ) -> int: ...

    @staticmethod
    def createPublisher_serialize(callback=None) -> _typing.Tuple[
        _typing.AsyncGenerator[int, None],
        _test_fixtures_interactions_module_types.ServerPublisher_cint32_t
    ]: ...


    @abstractmethod
    async def serialize(
        self
    ) -> _typing.Tuple[int, _typing.Union[_typing.Awaitable[_typing.AsyncGenerator[int, None]],_typing.AsyncGenerator[int, None]]]: ...
    pass


_FactoriesInterfaceT = _typing.TypeVar('_FactoriesInterfaceT', bound='FactoriesInterface')


class FactoriesInterface(
    ServiceInterface,
    metaclass=ABCMeta,
):


    @abstractmethod
    async def foo(
        self
    ) -> None: ...


    @abstractmethod
    async def interact(
        self,
        arg: int
    ) -> None: ...


    @abstractmethod
    async def interactFast(
        self
    ) -> int: ...

    @staticmethod
    def createPublisher_serialize(callback=None) -> _typing.Tuple[
        _typing.AsyncGenerator[int, None],
        _test_fixtures_interactions_module_types.ServerPublisher_cint32_t
    ]: ...


    @abstractmethod
    async def serialize(
        self
    ) -> _typing.Tuple[int, _typing.Union[_typing.Awaitable[_typing.AsyncGenerator[int, None]],_typing.AsyncGenerator[int, None]]]: ...
    pass


_PerformInterfaceT = _typing.TypeVar('_PerformInterfaceT', bound='PerformInterface')


class PerformInterface(
    ServiceInterface,
    metaclass=ABCMeta,
):


    @abstractmethod
    async def foo(
        self
    ) -> None: ...
    pass


_InteractWithSharedInterfaceT = _typing.TypeVar('_InteractWithSharedInterfaceT', bound='InteractWithSharedInterface')


class InteractWithSharedInterface(
    ServiceInterface,
    metaclass=ABCMeta,
):


    @abstractmethod
    async def do_some_similar_things(
        self
    ) -> _test_fixtures_another_interactions_shared_types.DoSomethingResult: ...
    pass


