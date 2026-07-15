/* Copyright (c) 2021, Meta Inc. All rights reserved. */

#include <caml/mlvalues.h>
#include <caml/memory.h>

#if defined(__linux__)
#include <sys/personality.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#endif

CAMLprim value caml_disable_ASLR(value args) {
  CAMLparam1(args);

#if defined(__linux__)
  /* Allow users to opt out of this behavior in restricted environments */
  if (getenv("HHVM_DISABLE_PERSONALITY")) {
    CAMLreturn(Val_unit);
  }

  int res = personality((unsigned long)0xffffffff);
  if (res == -1) {
      fprintf(stderr, "error: daemon_stubs.c: caml_disable_ASLR: failed to get personality\n");
      exit(1);
  }
  if (! (res & ADDR_NO_RANDOMIZE)) {
    res = personality((unsigned long)(res | ADDR_NO_RANDOMIZE));
    if(res == -1) {
      fprintf(stderr, "error: daemon_stubs.c: caml_disable_ASLR: failed to set personality\n");
      exit(1);
    }
    int i, argc = Wosize_val(args);
    char const** argv = (char const**)(malloc ((argc + 1) * sizeof(char const*)));
    for (i = 0; i < argc; ++i) {
      argv[i] = String_val(Field(args, i));
    }
    argv[argc] = (char const*)0;
    (void)execv(argv[0], (char *const *)argv); 
  }
#elif defined(_WIN32)
  /* Windows ignores runtime personality adjustments. 
     ASLR should be stripped via compiler/linker options (/DYNAMICBASE:NO). */
#elif defined(__APPLE__)
  /* macOS strictly enforces ASLR/PIE on modern platforms (especially arm64). 
     Architecture must handle closure isolation via clean data passing instead. */
#endif

  CAMLreturn(Val_unit);
}
