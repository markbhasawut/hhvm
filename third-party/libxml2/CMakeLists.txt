include(ExternalProject)
include(HPHPFunctions)

SET_HHVM_THIRD_PARTY_SOURCE_ARGS(
  LIBXML2_SOURCE_ARGS
  SOURCE_URL
  "https://github.com/GNOME/libxml2/archive/refs/tags/v2.15.1.tar.gz"
  SOURCE_HASH
  "SHA512=05d998e611a8b59cb6688d9432a0f8977cae94aa17b2f01a81c75333c4610b801d1b7e4d19e3206fb06eab4303a7046fc3cac9c814529c0757d61825ebb0aa4e"
)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Force the compiler to built with Position Independent Code
set(LIBXML2_CFLAGS "${CMAKE_C_FLAGS} -fvisibility=default")
set(LIBXML2_LDFLAGS "${CMAKE_EXE_LINKER_FLAGS} -fPIC")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/libxml2-prefix")
ExternalProject_add(
  bundled_libxml2
  ${LIBXML2_SOURCE_ARGS}
  CONFIGURE_COMMAND
    /bin/sh -c "
      <SOURCE_DIR>/autogen.sh \
      CC='${CMAKE_C_COMPILER}' \
      CXX='${CMAKE_CXX_COMPILER}' \
      CFLAGS='${LIBXML2_CFLAGS}' \
      LDFLAGS='${LIBXML2_LDFLAGS}' \
      --with-icu \
      --with-thread-alloc \
      --with-http \
      --enable-static \
      --disable-shared \
      --prefix=<INSTALL_DIR>"

  BUILD_COMMAND
    make -j ${nproc}
  
  INSTALL_COMMAND
    make -j ${nproc} install
)

ExternalProject_get_property(bundled_libxml2 INSTALL_DIR)

add_library(libxml2 INTERFACE)
add_dependencies(libxml2 bundled_libxml2)

ExternalProject_Get_Property(bundled_libxml2 INSTALL_DIR)
target_include_directories(libxml2 INTERFACE "${INSTALL_DIR}/include/libxml2")

set(LIBXML2_STATIC_LIB_PATH "${INSTALL_DIR}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}xml2${CMAKE_STATIC_LIBRARY_SUFFIX}")
target_link_libraries(libxml2 INTERFACE "${LIBXML2_STATIC_LIB_PATH}")

# Link against ICU and math library
target_link_libraries(libxml2 INTERFACE icuuc icudata m)
