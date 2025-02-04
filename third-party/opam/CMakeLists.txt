# When updating:
# - verify the gpg signature (fooasc) against key
#   1958 E634 BA58 0D63 9E4B  1EF6 AC26 8762 CB21 AF4D
#   available from https://keybase.io/altgr/pgp_keys.asc
# - generate the hash with `openssl dgst -sha512 foo'
#
# We separately store the hash to be sure we're getting the exact same
# build, not just any tarball.
#
# This also avoids the need to depend on gpg in the installation.
include(HPHPFunctions)

set(OPAM_VERSION "2.3.0")

if(LINUX)
  if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "x86_64"
  )
    message(STATUS "Using opam-${OPAM_VERSION}-x86_64-linux")
    set(OPAM_URL "opam-${OPAM_VERSION}-x86_64-linux")
    set(URL_HASH "SHA512=d4271d2387751313d5f904e8fdb3133ea893c72d09737139266d2bbe7624f81665a4276d2e55aa71856630ece8ce226b989560076599baae9afc053c5815f8c8")
  else()
    message(STATUS "Using opam-${OPAM_VERSION}-arm64-linux")
    set(OPAM_URL "opam-${OPAM_VERSION}-arm64-linux")
    set(URL_HASH "SHA512=a551cbaa44a6945e09b3daa3a3a7477821062d385037543cb71a188e4625c4ced76422689437aee602707076c1d16b68bed99ad5a31df98e69a8810dccb037b3")
  endif()
endif()

if(APPLE)
  if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "x86_64"
  )
    message(STATUS "Using opam-${OPAM_VERSION}-x86_64-macos")
    set(OPAM_URL "opam-${OPAM_VERSION}-x86_64-macos")
    set(URL_HASH "SHA512=18c98cbbd986e33e06943522d0cce6725615406c4f072e7487a56242e2f03de0f436a674b590a5ebfbbe47b7819358926bd3ce71c5b847227b5d0d3de120d6ee")
  else()
    message(STATUS "Using opam-${OPAM_VERSION}-arm64-macos")
    set(OPAM_URL "opam-${OPAM_VERSION}-arm64-macos")
    set(URL_HASH "SHA512=45a6ca26eed3fe5937b1940f2c41c24517c0920d9632fd9eea3e0613411e85cb4126effd645d2915e37c65022aa0c483d2c98f8ce25dd8b70bb98e2c4ecd7804")
  endif()
endif()

SET_HHVM_THIRD_PARTY_SOURCE_ARGS(
  OPAM_DOWNLOAD_ARGS
  Linux_URL
  "https://github.com/ocaml/opam/releases/download/${OPAM_VERSION}/${OPAM_URL}"
  Darwin_URL
  "https://github.com/ocaml/opam/releases/download/${OPAM_VERSION}/${OPAM_URL}"
  Linux_HASH
  "${URL_HASH}"
  Darwin_HASH
  "${URL_HASH}"
)

include(ExternalProject)
ExternalProject_Add(
  opamDownload
  ${OPAM_DOWNLOAD_ARGS}
  DOWNLOAD_NO_EXTRACT ON
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND
  install -m755 "<DOWNLOADED_FILE>" "<INSTALL_DIR>/opam"
)

ExternalProject_Get_Property(opamDownload INSTALL_DIR)
get_filename_component(OPAM_EXECUTABLE "${INSTALL_DIR}/opam" ABSOLUTE)

add_executable(opam IMPORTED GLOBAL)
add_dependencies(opam opamDownload)
set_property(TARGET opam PROPERTY IMPORTED_LOCATION "${OPAM_EXECUTABLE}")
