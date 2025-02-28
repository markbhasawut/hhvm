include(ExternalProject)

set(TBB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/src")

# TBB recommends using `tbb_build` but the whole logic seems pretty
# fragile and opaque so we just call Make directly. This way we get
# to control our arguments.

ExternalProject_Add(
  bundled_tbb
  EXCLUDE_FROM_ALL
  SOURCE_DIR "${TBB_ROOT}"
  BUILD_ALWAYS ON
  PATCH_COMMAND ""
  CMAKE_ARGS
  -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}
  -DCMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}
  -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
  -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
  -DCMAKE_OSX_SYSROOT=${CMAKE_OSX_SYSROOT}
  -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
  -DCMAKE_INSTALL_INCLUDEDIR=include
  -DCMAKE_INSTALL_LIBDIR=lib
  ${EXTRA_ARGS}
)

add_library(tbb INTERFACE)
add_dependencies(tbb bundled_tbb)

ExternalProject_Get_Property(bundled_tbb INSTALL_DIR)
target_include_directories(tbb INTERFACE "${TBB_ROOT}/include")

set(TBB_STATIC_LIB_PATH ${INSTALL_DIR}$<IF:$<CONFIG:Debug>,_debug,_release>/${CMAKE_STATIC_LIBRARY_PREFIX}tbb$<$<CONFIG:Debug>:_debug>${CMAKE_STATIC_LIBRARY_SUFFIX})

target_link_libraries(
  tbb
  INTERFACE
  "${TBB_STATIC_LIB_PATH}"
)
