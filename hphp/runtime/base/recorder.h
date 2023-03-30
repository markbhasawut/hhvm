/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#pragma once

#include <cstddef>

#include "hphp/runtime/base/req-hash-map.h"
#include "hphp/runtime/base/req-vector.h"
#include "hphp/runtime/base/string-data.h"
#include "hphp/runtime/base/type-array.h"
#include "hphp/runtime/base/type-string.h"
#include "hphp/runtime/base/typed-value.h"
#include "hphp/runtime/vm/act-rec.h"

namespace HPHP {

struct Recorder {
  void onFunctionReturn(const ActRec* ar, TypedValue ret);
  void requestExit();
  void requestInit();
  void setEntryPoint(const String& entryPoint);

 private:
  struct NativeCall {
    TypedValue ret;
    Array args;
  };

  Array toArray() const;

  bool m_enabled{false};
  String m_entryPoint;
  req::vector_map<const StringData*, req::vector<NativeCall>> m_nativeCalls;
};

} // namespace HPHP
