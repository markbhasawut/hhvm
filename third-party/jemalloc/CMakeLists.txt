include(ExternalProject)

ExternalProject_add(
  bundled_jemalloc
  URL "https://github.com/jemalloc/jemalloc/releases/download/5.3.0/jemalloc-5.2.1.tar.bz2"
  URL_HASH SHA512=02fffb5b4d45eab0d890b9a41e638be35a7dffe16c8fc736bc6a423dc1d6573018665234253470bec61ca0b0863d5aa339c12596e517e41a0f1994b01c734817
  PREFIX "${JEMALLOC_PREFIX}"
  PATCH_COMMAND
    "${CMAKE_CURRENT_SOURCE_DIR}/../apply-quilt-patches.sh"
    "${CMAKE_CURRENT_SOURCE_DIR}/patches"
  CONFIGURE_COMMAND
    "<SOURCE_DIR>/configure"
      CC=${CMAKE_C_COMPILER}
      CXX=${CMAKE_CXX_COMPILER}
      CFLAGS=${CMAKE_C_FLAGS}
      CXXFLAGS=${CMAKE_CXX_FLAGS}
      LDFLAGS=${CMAKE_EXE_LINKER_FLAGS}
      --prefix=<INSTALL_DIR>
      --includedir=<INSTALL_DIR>/include
      --libdir=<INSTALL_DIR>/lib
      --disable-shared
      --enable-static
      --with-jemalloc-prefix=
  EXCLUDE_FROM_ALL
)

add_library(jemalloc INTERFACE)

if (NOT FORCE_TP_JEMALLOC)
  find_library(JEMALLOC_LIB NAMES jemalloc)
  find_path(JEMALLOC_INCLUDE_DIR NAMES jemalloc/jemalloc.h)
  set(CMAKE_REQUIRED_INCLUDES "${JEMALLOC_INCLUDE_DIR}")
  include(CheckCXXSourceCompiles)
  check_cxx_source_compiles("
#include <jemalloc/jemalloc.h>

#if JEMALLOC_VERSION_MAJOR < 5 || (JEMALLOC_VERSION_MAJOR == 5 && JEMALLOC_VERSION_MINOR < 3)
# error jemalloc version >= 5.3 required
#endif

  int main(void) { return 0; }" JEMALLOC_VERSION_MINIMUM)
  set(CMAKE_REQUIRED_INCLUDES)
endif()

if (JEMALLOC_VERSION_MINIMUM)
  message(STATUS "Found jemalloc: ${JEMALLOC_LIB} ${JEMALLOC_INCLUDE_DIR}")
  target_include_directories(jemalloc INTERFACE "${JEMALLOC_INCLUDE_DIR}")
else()
  message(STATUS "Using third-party bundled jemalloc")

  ExternalProject_Get_Property(bundled_jemalloc INSTALL_DIR)
  target_include_directories(jemalloc INTERFACE "${INSTALL_DIR}/include")
  set(JEMALLOC_LIB "${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}jemalloc_pic${CMAKE_STATIC_LIBRARY_SUFFIX}")
  add_dependencies(jemalloc bundled_jemalloc)
endif()

# the --no-as-needed and -force_load make the linker include all symbols,
# including ones that appear unused - this is essential when using jemalloc
# as a static library: it uses `__attribute__((constructor))` to do very early
# process-level initialization, and some linkers will omit those functions
# when linking a static library as there are no explicit callsites.
#
# This can lead to fun stuff like `malloc()` segfaulting on MacOS.
if (UNIX AND NOT APPLE)
  target_link_libraries(jemalloc INTERFACE "-Wl,--no-as-needed" "${JEMALLOC_LIB}" "-Wl,--as-needed")
  target_link_libraries(jemalloc INTERFACE dl pthread)
elseif (APPLE)
  target_link_libraries(jemalloc INTERFACE "-Wl,-force_load" "${JEMALLOC_LIB}")
endif()
