/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/basic-annotations/gen-cpp2/module_constants.h"

#include <thrift/lib/cpp2/gen/module_constants_cpp.h>


namespace cpp2 {

::cpp2::YourStruct const& module_constants::myStruct() {
  static folly::Indestructible<::cpp2::YourStruct> const instance{StaticCast::fromThrift(::cpp2::detail::YourStruct(::apache::thrift::detail::make_structured_constant<::cpp2::detail::YourStruct>(::apache::thrift::detail::wrap_struct_argument<::apache::thrift::ident::majorVer>(static_cast<::std::int64_t>(42)), ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::ident::package>(apache::thrift::StringTraits<std::string>::fromStringLiteral("package")), ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::ident::my_enum>( ::cpp2::YourEnum::DOMAIN))))};
  return *instance;
}

} // cpp2
