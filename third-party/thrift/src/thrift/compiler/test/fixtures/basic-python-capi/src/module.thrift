/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

include "thrift/annotation/cpp.thrift"
include "thrift/annotation/python.thrift"

package "test.dev/fixtures/basic-python-capi"

enum MyEnum {
  MyValue1 = 0,
  MyValue2 = 1,
}

struct MyStruct {
  1: i64 MyIntField;
  2: string MyStringField;
  3: MyDataItem MyDataField;
  4: MyEnum myEnum;
  5: bool oneway;
  6: list<float> floatList;
  7: map<binary, string> strMap;
  8: set<i32> floatSet;
}

struct MyDataItem {}

@cpp.Adapter{name = "::thrift::test::lib::StructDoubler"}
@scope.Transitive
struct TransitiveDoubler {}

@TransitiveDoubler
struct DoubledPair {
  1: string s;
  2: i32 x;
}

struct StringPair {
  1: string normal;
  @cpp.Adapter{name = "::thrift::test::lib::StringDoubler"}
  2: string doubled;
}

struct EmptyStruct {}

typedef byte signed_byte

@python.MarshalCapi
struct PrimitiveStruct {
  1: bool booly;
  2: signed_byte charry;
  @cpp.Type{name = "uint16_t"}
  3: i16 shorty (cpp.name = "shortay");
  5: i32 inty;
  @cpp.Type{name = "uint64_t"}
  7: i64 longy;
  8: optional float floaty;
  @thrift.Box
  9: optional double dubby;
  @cpp.Ref{type = cpp.RefType.Unique}
  12: optional string stringy;
  @cpp.Ref{type = cpp.RefType.Shared}
  13: optional binary bytey;
}

union MyUnion {
  1: MyEnum myEnum;
  2: MyStruct myStruct;
  3: MyDataItem myDataItem;
  4: set<i64> doubleSet;
  5: list<double> doubleList;
  6: map<binary, string> strMap;
}
