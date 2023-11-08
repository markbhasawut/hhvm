HHVM_DEFINE_EXTENSION("std" REQUIRED
  SOURCES
    ext_std.cpp
    ext_std_classobj.cpp
    ext_std_errorfunc.cpp
    ext_std_file.cpp
    ext_std_function.cpp
    ext_std_gc.cpp
    ext_std_math.cpp
    ext_std_misc.cpp
    ext_std_network.cpp
    ext_std_network-posix.cpp
    ext_std_network-win.cpp
    ext_std_options.cpp
    ext_std_output.cpp
    ext_std_process.cpp
    ext_std_string.cpp
    ext_std_variable.cpp
  HEADERS
    ext_std.h
    ext_std_classobj.h
    ext_std_errorfunc.h
    ext_std_file.h
    ext_std_function.h
    ext_std_math.h
    ext_std_misc.h
    ext_std_network.h
    ext_std_network-internal.h
    ext_std_options.h
    ext_std_output.h
    ext_std_string.h
    ext_std_variable.h
  SYSTEMLIB
    ext_std_classobj.php
    ext_std_errorfunc.php
    ext_std_file.php
    ext_std_function.php
    ext_std_gc.php
    ext_std_intrinsics.php
    ext_std_math.php
    ext_std_misc.php
    ext_std_network.php
    ext_std_options.php
    ext_std_output.php
    ext_std_process.php
    ext_std_string.php
    ext_std_variable.php
  DEPENDS
    libBoost
    libFolly
)
