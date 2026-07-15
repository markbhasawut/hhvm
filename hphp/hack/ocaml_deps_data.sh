#!/bin/bash

export OCAML_VERSION="5.5.0+options"

export HACK_OPAM_DEPS=(
  base.v0.17.3
  base64.3.5.2
  camlp-streams.5.0.1
  cmdliner.2.1.1
  core_kernel.v0.17.0
  core_unix.v0.17.1
  dtoa.0.3.3
  dune.3.24.0
  fileutils.0.6.6
  fmt.0.11.0
  iomux.0.4
  landmarks-ppx.1.7
  lru.0.3.1
  lwt.5.10.1
  lwt_log.1.1.2
  lwt_ppx.5.9.3
  memtrace.0.2.3
  merlin.5.8-505
  mtime.2.1.0
  ocp-indent.1.9.0
  ounit2.2.2.7
  pcre.8.0.5
  ppx_deriving.6.1.2
  ppx_gen_rec.2.0.0
  ppx_sexp_conv.v0.17.1
  ppx_yojson_conv.v0.17.1
  sedlex.3.7
  sexplib.v0.17.0
  sqlite3.5.4.1
  uchar.0.0.2
  uutf.1.0.4
  visitors.20260520
  wtf8.1.0.2
  yojson.3.0.0
  ocamlbuild.0.16.1
  ocamlformat.0.29.0
  ocaml-option-flambda
  ocaml-option-no-compression
)

# The rest of the file exports variables based on the above configuration.

export HACK_OCAML_VERSION="${OCAML_VERSION}"
export OCAML_BASE_NAME=ocaml-variants
export OCAML_COMPILER_NAME="${OCAML_BASE_NAME}.${HACK_OCAML_VERSION}"

UNAME=$(uname -s)
ARCH=$(uname -m)
SUPPORT_FP=false
if [ "$ARCH" == "arm64" ] || [ "$ARCH" == "aarch64" ]; then
  SUPPORT_FP=true
elif [ "$ARCH" == "x86_64" ]; then
  if [ "$UNAME" == "Linux" ] || [ "$UNAME" == "Darwin" ]; then
    SUPPORT_FP=true
  fi
fi

if [ "$SUPPORT_FP" == "true" ]; then
  HACK_OPAM_DEPS+=(ocaml-option-fp)
  export HACK_OPAM_DEPS
else
  echo 'Platform/architecture does not support +fp, skipping'
fi
