/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/python_capi/src/containers.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/python_capi/gen-cpp2/containers_metadata.h"

// some of these functions can be so large that the compiler gives up optimizing
// them - and issues a warning which may be treated as an error!
//
// these functions are so rarely called that it is probably okay for them not to
// be optimized in practice
FOLLY_CLANG_DISABLE_WARNING("-Wignored-optimization-argument")

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;
using ThriftService = ::apache::thrift::metadata::ThriftService;
using ThriftServiceContext = ::apache::thrift::metadata::ThriftServiceContext;
using ThriftFunctionGenerator = void (*)(ThriftMetadata&, ThriftService&);


const ::apache::thrift::metadata::ThriftStruct&
StructMetadata<::test::fixtures::python_capi::TemplateLists>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs()->emplace("containers.TemplateLists", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return res.first->second;
  }
  ::apache::thrift::metadata::ThriftStruct& containers_TemplateLists = res.first->second;
  containers_TemplateLists.name() = "containers.TemplateLists";
  containers_TemplateLists.is_union() = false;
  static const auto* const
  containers_TemplateLists_fields = new std::array<EncodedThriftField, 5>{ {
    { 1, "std_string", true, std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("std::vector") } }).cv_struct_ref(), }},    { 2, "deque_string", false, std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BINARY_TYPE)), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("std::deque") } }).cv_struct_ref(), }},    { 3, "small_vector_iobuf", false, std::make_unique<Typedef>("containers.small_vector_iobuf", std::make_unique<List>(std::make_unique<Typedef>("containers.IOBuf", std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_BINARY_TYPE), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"name", cvString("folly::IOBuf") } }).cv_struct_ref(),  })), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("folly::small_vector") } }).cv_struct_ref(),  }), std::vector<ThriftConstStruct>{ }},    { 4, "nested_small_vector", false, std::make_unique<List>(std::make_unique<Typedef>("containers.fbvector_string", std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("folly::fbvector") } }).cv_struct_ref(),  })), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("folly::small_vector") } }).cv_struct_ref(), }},    { 5, "small_vector_tensor", false, std::make_unique<List>(std::make_unique<Typedef>("containers.fbvector_fbvector_string", std::make_unique<List>(std::make_unique<Typedef>("containers.fbvector_string", std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::THRIFT_STRING_TYPE)), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("folly::fbvector") } }).cv_struct_ref(),  })), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("folly::fbvector") } }).cv_struct_ref(),  })), std::vector<ThriftConstStruct>{ *cvStruct("cpp.Type", { {"template", cvString("folly::fbvector") } }).cv_struct_ref(), }},  }};
  for (const auto& f : *containers_TemplateLists_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id() = f.id;
    field.name() = f.name;
    field.is_optional() = f.is_optional;
    f.metadata_type_interface->writeAndGenType(*field.type(), metadata);
    field.structured_annotations() = f.structured_annotations;
    containers_TemplateLists.fields()->push_back(std::move(field));
  }
  return res.first->second;
}

} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
