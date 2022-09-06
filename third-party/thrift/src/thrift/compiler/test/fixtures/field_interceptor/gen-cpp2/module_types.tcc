/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/field_interceptor/gen-cpp2/module_types.h"

#include <thrift/lib/cpp2/gen/module_types_tcc.h>
#include <thrift/lib/cpp2/op/Clear.h>
#include <thrift/lib/cpp2/op/Get.h>
#include <thrift/lib/cpp2/op/Encode.h>


namespace apache {
namespace thrift {
namespace detail {

template <>
struct TccStructTraits<::facebook::thrift::test::InterceptedFields> {
  static void translateFieldName(
      folly::StringPiece _fname,
      int16_t& fid,
      apache::thrift::protocol::TType& _ftype) noexcept;
};

} // namespace detail
} // namespace thrift
} // namespace apache

namespace facebook { namespace thrift { namespace test {

template <class Protocol_>
void InterceptedFields::readNoXfer(Protocol_* iprot) {
  __fbthrift_clear_terse_fields();

  apache::thrift::detail::ProtocolReaderStructReadState<Protocol_> _readState;

  _readState.readStructBegin(iprot);

  using apache::thrift::TProtocolException;


  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          0,
          1,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_access_field:
  {
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, this->__fbthrift_field_access_field, _readState);
    
  }
 this->__isset.set(0, true);

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          1,
          2,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_access_shared_field:
  {
    auto ptr = ::apache::thrift::detail::make_mutable_smart_ptr<::std::shared_ptr<::std::int32_t>>();
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, *ptr, _readState);
    this->__fbthrift_field_access_shared_field = std::move(ptr);
    
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          2,
          3,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_access_optional_shared_field:
  {
    auto ptr = ::apache::thrift::detail::make_mutable_smart_ptr<::std::shared_ptr<::std::int32_t>>();
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, *ptr, _readState);
    this->__fbthrift_field_access_optional_shared_field = std::move(ptr);
    
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          3,
          4,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_access_shared_const_field:
  {
    auto ptr = ::apache::thrift::detail::make_mutable_smart_ptr<::std::shared_ptr<const ::std::int32_t>>();
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, *ptr, _readState);
    this->__fbthrift_field_access_shared_const_field = std::move(ptr);
    
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          4,
          5,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_access_optional_shared_const_field:
  {
    auto ptr = ::apache::thrift::detail::make_mutable_smart_ptr<::std::shared_ptr<const ::std::int32_t>>();
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, *ptr, _readState);
    this->__fbthrift_field_access_optional_shared_const_field = std::move(ptr);
    
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          5,
          6,
          apache::thrift::protocol::T_I32))) {
    goto _loop;
  }
_readField_access_optional_boxed_field:
  {
    auto ptr = ::apache::thrift::detail::make_mutable_smart_ptr<::apache::thrift::detail::boxed_value_ptr<::std::int32_t>>();
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::readWithContext(*iprot, *ptr, _readState);
    this->__fbthrift_field_access_optional_boxed_field = std::move(ptr);
    
  }

  if (UNLIKELY(!_readState.advanceToNextField(
          iprot,
          6,
          0,
          apache::thrift::protocol::T_STOP))) {
    goto _loop;
  }

_end:
  _readState.readStructEnd(iprot);

  return;

_loop:
  _readState.afterAdvanceFailure(iprot);
  if (_readState.atStop()) {
    goto _end;
  }
  if (iprot->kUsesFieldNames()) {
    _readState.template fillFieldTraitsFromName<apache::thrift::detail::TccStructTraits<InterceptedFields>>();
  }

  switch (_readState.fieldId) {
    case 1:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_access_field;
      } else {
        goto _skip;
      }
    }
    case 2:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_access_shared_field;
      } else {
        goto _skip;
      }
    }
    case 3:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_access_optional_shared_field;
      } else {
        goto _skip;
      }
    }
    case 4:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_access_shared_const_field;
      } else {
        goto _skip;
      }
    }
    case 5:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_access_optional_shared_const_field;
      } else {
        goto _skip;
      }
    }
    case 6:
    {
      if (LIKELY(_readState.isCompatibleWithType(iprot, apache::thrift::protocol::T_I32))) {
        goto _readField_access_optional_boxed_field;
      } else {
        goto _skip;
      }
    }
    default:
    {
_skip:
      _readState.skip(iprot);
      _readState.readFieldEnd(iprot);
      _readState.readFieldBeginNoInline(iprot);
      goto _loop;
    }
  }
}

template <class Protocol_>
uint32_t InterceptedFields::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("InterceptedFields");
  {
    xfer += prot_->serializedFieldSize("access_field", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, this->__fbthrift_field_access_field);
  }
  {
    xfer += prot_->serializedFieldSize("access_shared_field", apache::thrift::protocol::T_I32, 2);
    if (this->__fbthrift_field_access_shared_field) {
      xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_shared_field);
    }
  }
  if (this->__fbthrift_field_access_optional_shared_field) {
    xfer += prot_->serializedFieldSize("access_optional_shared_field", apache::thrift::protocol::T_I32, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_optional_shared_field);
  }
  {
    xfer += prot_->serializedFieldSize("access_shared_const_field", apache::thrift::protocol::T_I32, 4);
    if (this->__fbthrift_field_access_shared_const_field) {
      xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_shared_const_field);
    }
  }
  if (this->__fbthrift_field_access_optional_shared_const_field) {
    xfer += prot_->serializedFieldSize("access_optional_shared_const_field", apache::thrift::protocol::T_I32, 5);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_optional_shared_const_field);
  }
  if (this->__fbthrift_field_access_optional_boxed_field) {
    xfer += prot_->serializedFieldSize("access_optional_boxed_field", apache::thrift::protocol::T_I32, 6);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_optional_boxed_field);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t InterceptedFields::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("InterceptedFields");
  {
    xfer += prot_->serializedFieldSize("access_field", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, this->__fbthrift_field_access_field);
  }
  {
    xfer += prot_->serializedFieldSize("access_shared_field", apache::thrift::protocol::T_I32, 2);
    if (this->__fbthrift_field_access_shared_field) {
      xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_shared_field);
    }
  }
  if (this->__fbthrift_field_access_optional_shared_field) {
    xfer += prot_->serializedFieldSize("access_optional_shared_field", apache::thrift::protocol::T_I32, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_optional_shared_field);
  }
  {
    xfer += prot_->serializedFieldSize("access_shared_const_field", apache::thrift::protocol::T_I32, 4);
    if (this->__fbthrift_field_access_shared_const_field) {
      xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_shared_const_field);
    }
  }
  if (this->__fbthrift_field_access_optional_shared_const_field) {
    xfer += prot_->serializedFieldSize("access_optional_shared_const_field", apache::thrift::protocol::T_I32, 5);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_optional_shared_const_field);
  }
  if (this->__fbthrift_field_access_optional_boxed_field) {
    xfer += prot_->serializedFieldSize("access_optional_boxed_field", apache::thrift::protocol::T_I32, 6);
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::serializedSize<false>(*prot_, *this->__fbthrift_field_access_optional_boxed_field);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t InterceptedFields::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("InterceptedFields");
  bool previousFieldHasValue = true;
  {
    constexpr int16_t kPrevFieldId = 0;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_I32, 1, kPrevFieldId>(*prot_, "access_field", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, this->__fbthrift_field_access_field);
    xfer += prot_->writeFieldEnd();
  }
  {
    constexpr int16_t kPrevFieldId = 1;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_I32, 2, kPrevFieldId>(*prot_, "access_shared_field", previousFieldHasValue);
    previousFieldHasValue = true;
    if (this->__fbthrift_field_access_shared_field) {
      xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, *this->__fbthrift_field_access_shared_field);
    }
    xfer += prot_->writeFieldEnd();
  }
  if (this->__fbthrift_field_access_optional_shared_field) {
    constexpr int16_t kPrevFieldId = 2;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_I32, 3, kPrevFieldId>(*prot_, "access_optional_shared_field", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, *this->__fbthrift_field_access_optional_shared_field);
    xfer += prot_->writeFieldEnd();
  } else {
    previousFieldHasValue = false;
  }
  {
    constexpr int16_t kPrevFieldId = 3;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_I32, 4, kPrevFieldId>(*prot_, "access_shared_const_field", previousFieldHasValue);
    previousFieldHasValue = true;
    if (this->__fbthrift_field_access_shared_const_field) {
      xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, *this->__fbthrift_field_access_shared_const_field);
    }
    xfer += prot_->writeFieldEnd();
  }
  if (this->__fbthrift_field_access_optional_shared_const_field) {
    constexpr int16_t kPrevFieldId = 4;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_I32, 5, kPrevFieldId>(*prot_, "access_optional_shared_const_field", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, *this->__fbthrift_field_access_optional_shared_const_field);
    xfer += prot_->writeFieldEnd();
  } else {
    previousFieldHasValue = false;
  }
  if (this->__fbthrift_field_access_optional_boxed_field) {
    constexpr int16_t kPrevFieldId = 5;
    xfer += ::apache::thrift::detail::writeFieldBegin<apache::thrift::protocol::T_I32, 6, kPrevFieldId>(*prot_, "access_optional_boxed_field", previousFieldHasValue);
    previousFieldHasValue = true;
    xfer += ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral, ::std::int32_t>::write(*prot_, *this->__fbthrift_field_access_optional_boxed_field);
    xfer += prot_->writeFieldEnd();
  } else {
    previousFieldHasValue = false;
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

extern template void InterceptedFields::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t InterceptedFields::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t InterceptedFields::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t InterceptedFields::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void InterceptedFields::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t InterceptedFields::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t InterceptedFields::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t InterceptedFields::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


}}} // facebook::thrift::test
