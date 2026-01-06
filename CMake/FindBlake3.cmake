find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
    # BLAKE3 is commonly provided as 'blake3' or 'libblake3' by package managers
    pkg_check_modules(PC_BLAKE3 QUIET libblake3 blake3)
endif()

# Fallback to manual search if pkg-config is missing or fails
find_path(BLAKE3_INCLUDE_DIR
    NAMES blake3.h
    HINTS ${PC_BLAKE3_INCLUDE_DIRS} /home/linuxbrew/.linuxbrew/include
)

find_library(BLAKE3_LIBRARY
    NAMES blake3 libblake3
    HINTS ${PC_BLAKE3_LIBRARY_DIRS} /home/linuxbrew/.linuxbrew/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Blake3
    REQUIRED_VARS BLAKE3_LIBRARY BLAKE3_INCLUDE_DIR
    VERSION_VAR PC_BLAKE3_VERSION
)

if(Blake3_FOUND AND NOT TARGET Blake3::Blake3)
    add_library(Blake3::Blake3 UNKNOWN IMPORTED)
    set_target_properties(Blake3::Blake3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BLAKE3_INCLUDE_DIR}"
        IMPORTED_LOCATION "${BLAKE3_LIBRARY}"
    )
endif()
