/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/interactions/src/shared.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_types_h.h>



namespace apache {
namespace thrift {
namespace ident {
struct s_res;
struct i_res;
} // namespace ident
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_s_res
#define APACHE_THRIFT_ACCESSOR_s_res
APACHE_THRIFT_DEFINE_ACCESSOR(s_res);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_i_res
#define APACHE_THRIFT_ACCESSOR_i_res
APACHE_THRIFT_DEFINE_ACCESSOR(i_res);
#endif
} // namespace detail
} // namespace thrift
} // namespace apache

// BEGIN declare_enums

// END declare_enums
// BEGIN forward_declare
namespace thrift::shared_interactions {
class DoSomethingResult;
} // namespace thrift::shared_interactions
// END forward_declare
namespace apache::thrift::detail::annotation {
} // namespace apache::thrift::detail::annotation

namespace apache::thrift::detail::qualifier {
} // namespace apache::thrift::detail::qualifier

// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace thrift::shared_interactions {
using ::apache::thrift::detail::operator!=;
using ::apache::thrift::detail::operator>;
using ::apache::thrift::detail::operator<=;
using ::apache::thrift::detail::operator>=;


/** Glean {"file": "thrift/compiler/test/fixtures/interactions/src/shared.thrift", "name": "DoSomethingResult", "kind": "struct" } */
class DoSomethingResult final  {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;
  template<class> friend struct ::apache::thrift::detail::invoke_reffer;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_is_runtime_annotation = false;
  static std::string_view __fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord);
  static std::string_view __fbthrift_get_class_name();
  using __fbthrift_reflection_ident_list = folly::tag_t<
    ::apache::thrift::ident::s_res,
    ::apache::thrift::ident::i_res
  >;

  static constexpr std::int16_t __fbthrift_reflection_field_id_list[] = {0,1,2};
  using __fbthrift_reflection_type_tags = folly::tag_t<
    ::apache::thrift::type::string_t,
    ::apache::thrift::type::i32_t
  >;

  static constexpr std::size_t __fbthrift_field_size_v = 2;

  template<class T>
  using __fbthrift_id = ::apache::thrift::type::field_id<__fbthrift_reflection_field_id_list[folly::to_underlying(T::value)]>;

  template<class T>
  using __fbthrift_type_tag = ::apache::thrift::detail::at<__fbthrift_reflection_type_tags, T::value>;

  template<class T>
  using __fbthrift_ident = ::apache::thrift::detail::at<__fbthrift_reflection_ident_list, T::value>;

  template<class T> using __fbthrift_ordinal = ::apache::thrift::type::ordinal_tag<
    ::apache::thrift::detail::getFieldOrdinal<T,
                                              __fbthrift_reflection_ident_list,
                                              __fbthrift_reflection_type_tags>(
      __fbthrift_reflection_field_id_list
    )
  >;
  void __fbthrift_clear();
  void __fbthrift_clear_terse_fields();
  bool __fbthrift_is_empty() const;

 public:
  using __fbthrift_cpp2_type = DoSomethingResult;
  static constexpr bool __fbthrift_cpp2_is_union =
    false;
  static constexpr bool __fbthrift_cpp2_uses_op_encode =
    false;


 public:

  DoSomethingResult();

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]]
  DoSomethingResult(apache::thrift::FragileConstructor, ::std::string s_res__arg, ::std::int32_t i_res__arg);

  DoSomethingResult(DoSomethingResult&&) noexcept;

  DoSomethingResult(const DoSomethingResult& src);


  DoSomethingResult& operator=(DoSomethingResult&&) noexcept;
  DoSomethingResult& operator=(const DoSomethingResult& src);

  ~DoSomethingResult();

 private:
  ::std::string __fbthrift_field_s_res;
 private:
  ::std::int32_t __fbthrift_field_i_res;
 private:
  apache::thrift::detail::isset_bitset<2, apache::thrift::detail::IssetBitsetOption::Unpacked> __isset;

 public:

  bool operator==(const DoSomethingResult&) const;
  bool operator<(const DoSomethingResult&) const;

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> s_res_ref() const& {
    return {this->__fbthrift_field_s_res, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> s_res_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_s_res), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> s_res_ref() & {
    return {this->__fbthrift_field_s_res, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> s_res_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_s_res), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> s_res() const& {
    return {this->__fbthrift_field_s_res, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> s_res() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_s_res), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> s_res() & {
    return {this->__fbthrift_field_s_res, __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> s_res() && {
    return {static_cast<T&&>(this->__fbthrift_field_s_res), __isset.at(0), __isset.bit(0)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> i_res_ref() const& {
    return {this->__fbthrift_field_i_res, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> i_res_ref() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_i_res), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> i_res_ref() & {
    return {this->__fbthrift_field_i_res, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> i_res_ref() && {
    return {static_cast<T&&>(this->__fbthrift_field_i_res), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> i_res() const& {
    return {this->__fbthrift_field_i_res, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> i_res() const&& {
    return {static_cast<const T&&>(this->__fbthrift_field_i_res), __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> i_res() & {
    return {this->__fbthrift_field_i_res, __isset.at(1), __isset.bit(1)};
  }

  template <typename..., typename T = ::std::int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> i_res() && {
    return {static_cast<T&&>(this->__fbthrift_field_i_res), __isset.at(1), __isset.bit(1)};
  }

  const ::std::string& get_s_res() const& {
    return __fbthrift_field_s_res;
  }

  ::std::string get_s_res() && {
    return std::move(__fbthrift_field_s_res);
  }

  template <typename T_DoSomethingResult_s_res_struct_setter = ::std::string>
  [[deprecated("Use `FOO.s_res_ref() = BAR;` instead of `FOO.set_s_res(BAR);`")]]
  ::std::string& set_s_res(T_DoSomethingResult_s_res_struct_setter&& s_res_) {
    s_res_ref() = std::forward<T_DoSomethingResult_s_res_struct_setter>(s_res_);
    return __fbthrift_field_s_res;
  }

  ::std::int32_t get_i_res() const {
    return __fbthrift_field_i_res;
  }

  [[deprecated("Use `FOO.i_res_ref() = BAR;` instead of `FOO.set_i_res(BAR);`")]]
  ::std::int32_t& set_i_res(::std::int32_t i_res_) {
    i_res_ref() = i_res_;
    return __fbthrift_field_i_res;
  }

  template <class Protocol_>
  unsigned long read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<DoSomethingResult>;
  friend void swap(DoSomethingResult& a, DoSomethingResult& b);
};

template <class Protocol_>
unsigned long DoSomethingResult::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}


} // namespace thrift::shared_interactions
