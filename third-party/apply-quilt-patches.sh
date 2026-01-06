#!/bin/sh
#
#  Copyright (c) 2015-present, Facebook, Inc.
#  All rights reserved.
#
#  This source code is licensed under the MIT license found in the
#  LICENSE file in the root directory of this source tree.
#

# Applies a patch series maintained with the `quilt` tool
#
# The format is straightforward: if you have `foo.patch` and `bar.patch`,
# applied in that order, `patches/` contains:
#
# - bar.patch
# - foo.patch
# - series
#
# The 'series' file contains:
#
# ```
# foo.patch
# bar.patch
# ```
#
# Quilt uses the presence of a patches/ subdir to identify the root, similar
# to how Hack uses `.hhconfig` - so, to use quilt with an out-of-source patch
# dir is a little bit of work:
#
# ```
# $ cd ~/code/hhvm/build/third-party/fb-mysql/bundled_fbmysqlclient-prefix/src/bundled_fbmysqlclient/
# $ ln -s ~/code/hhvm/third-party/fb-mysql/patches
# $ export QUILT_PATCHES=$(pwd)/patches
# ```
#
# The essential commands are `quilt add`, `quilt refresh`, `quilt push`, and
# `quilt pop`.

QUILT_PATCHES="$1"
if [ ! -d "$QUILT_PATCHES" ]; then
  echo "Usage: $0 /path/to/patches"
  exit 1
fi

set -e

if [ -n "$HHVM_TP_QUILT" ]; then
  export QUILT_PATCHES
  echo "$0: using quilt executable: $HHVM_TP_QUILT"
  exec "${HHVM_TP_QUILT}" --quiltrc - push -a
fi

echo "$0: applying patches in $QUILT_PATCHES manually."

if [ -f "$QUILT_PATCHES/series" ]; then
  PATCH_LIST=$(grep -v '^#' "$QUILT_PATCHES/series" | grep -v '^$')
else
  PATCH_LIST=$(ls "$QUILT_PATCHES"/*.patch 2>/dev/null | xargs -n 1 basename)
fi

for PATCH_FILE in $PATCH_LIST; do
  echo "Applying patch '$PATCH_FILE'..."
  
  if [ -e ".quilt_$PATCH_FILE.stamp" ]; then
    echo "...skipping, already applied."
    continue
  fi

  PATCH_PATH="$QUILT_PATCHES/$PATCH_FILE"
  SUCCESS=0

  # Try different -p levels to apply the patch
  for level in 1 2 4 0; do
    if patch -p$level --force --dry-run < "$PATCH_PATH" > /dev/null 2>&1; then
      patch -p$level --force < "$PATCH_PATH"
      touch ".quilt_$PATCH_FILE.stamp"
      echo "... applied patch $PATCH_FILE at -p$level."
      SUCCESS=1
      break
    fi
  done

  if [ $SUCCESS -eq 0 ]; then
    # Final check: is it already merged/applied?
    if patch -p1 --reverse --force --dry-run < "$PATCH_PATH" > /dev/null 2>&1; then
      echo "... appears to have been merged upstream. Marking as applied."
      touch ".quilt_$PATCH_FILE.stamp"
    else
      echo "ERROR: Failed to apply patch '$PATCH_FILE.' (Path mismatch or conflict)"
      exit 1
    fi
  fi
done

echo "Applied all patches!"
