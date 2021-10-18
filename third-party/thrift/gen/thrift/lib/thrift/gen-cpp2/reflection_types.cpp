/**
 * Autogenerated by Thrift for reflection.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "reflection_types.h"
#include "reflection_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "reflection_data.h"


namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::apache::thrift::reflection::Type>::size;
folly::Range<::apache::thrift::reflection::Type const*> const TEnumTraits<::apache::thrift::reflection::Type>::values = folly::range(TEnumDataStorage<::apache::thrift::reflection::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::apache::thrift::reflection::Type>::names = folly::range(TEnumDataStorage<::apache::thrift::reflection::Type>::names);

char const* TEnumTraits<::apache::thrift::reflection::Type>::findName(type value) {
  using factory = ::apache::thrift::reflection::_Type_EnumMapFactory;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::apache::thrift::reflection::Type>::findValue(char const* name, type* out) {
  using factory = ::apache::thrift::reflection::_Type_EnumMapFactory;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}

}} // apache::thrift

namespace apache { namespace thrift { namespace reflection {
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Wdeprecated-declarations")
const _Type_EnumMapFactory::ValuesToNamesMapType _Type_VALUES_TO_NAMES = _Type_EnumMapFactory::makeValuesToNamesMap();
const _Type_EnumMapFactory::NamesToValuesMapType _Type_NAMES_TO_VALUES = _Type_EnumMapFactory::makeNamesToValuesMap();
FOLLY_POP_WARNING

}}} // apache::thrift::reflection

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::reflection::StructField>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::reflection::StructField>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift { namespace reflection {

StructField::StructField(const StructField&) = default;
StructField& StructField::operator=(const StructField&) = default;
StructField::StructField() :
      isRequired(0),
      type(0),
      order(0) {
}


StructField::~StructField() {}

StructField::StructField(StructField&& other) noexcept  :
    isRequired(std::move(other.isRequired)),
    type(std::move(other.type)),
    name(std::move(other.name)),
    annotations(std::move(other.annotations)),
    order(std::move(other.order)),
    __isset(other.__isset) {}
StructField& StructField::operator=(FOLLY_MAYBE_UNUSED StructField&& other) noexcept {
    this->isRequired = std::move(other.isRequired);
    this->type = std::move(other.type);
    this->name = std::move(other.name);
    this->annotations = std::move(other.annotations);
    this->order = std::move(other.order);
    __isset = other.__isset;
    return *this;
}


StructField::StructField(apache::thrift::FragileConstructor, bool isRequired__arg, ::std::int64_t type__arg, ::std::string name__arg, std::unordered_map<::std::string, ::std::string> annotations__arg, ::std::int16_t order__arg) :
    isRequired(std::move(isRequired__arg)),
    type(std::move(type__arg)),
    name(std::move(name__arg)),
    annotations(std::move(annotations__arg)),
    order(std::move(order__arg)) {
  __isset.isRequired = true;
  __isset.type = true;
  __isset.name = true;
  __isset.annotations = true;
  __isset.order = true;
}

void StructField::__clear() {
  // clear all fields
  this->isRequired = 0;
  this->type = 0;
  this->name = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->annotations.clear();
  this->order = 0;
  __isset = {};
}

bool StructField::operator==(const StructField& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.isRequired == rhs.isRequired)) {
    return false;
  }
  if (!(lhs.type == rhs.type)) {
    return false;
  }
  if (!(lhs.name == rhs.name)) {
    return false;
  }
  if (lhs.annotations_ref() != rhs.annotations_ref()) {
    return false;
  }
  if (!(lhs.order == rhs.order)) {
    return false;
  }
  return true;
}

const std::unordered_map<::std::string, ::std::string>* StructField::get_annotations() const& {
  return annotations_ref().has_value() ? std::addressof(annotations) : nullptr;
}

std::unordered_map<::std::string, ::std::string>* StructField::get_annotations() & {
  return annotations_ref().has_value() ? std::addressof(annotations) : nullptr;
}


void swap(StructField& a, StructField& b) {
  using ::std::swap;
  swap(a.isRequired_ref().value(), b.isRequired_ref().value());
  swap(a.type_ref().value(), b.type_ref().value());
  swap(a.name_ref().value(), b.name_ref().value());
  swap(a.annotations_ref().value_unchecked(), b.annotations_ref().value_unchecked());
  swap(a.order_ref().value(), b.order_ref().value());
  swap(a.__isset, b.__isset);
}

template void StructField::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t StructField::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t StructField::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t StructField::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void StructField::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t StructField::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t StructField::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t StructField::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



}}} // apache::thrift::reflection

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::reflection::DataType>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::reflection::DataType>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift { namespace reflection {

DataType::DataType(const DataType&) = default;
DataType& DataType::operator=(const DataType&) = default;
DataType::DataType() :
      mapKeyType(0),
      valueType(0) {
}


DataType::~DataType() {}

DataType::DataType(DataType&& other) noexcept  :
    name(std::move(other.name)),
    fields(std::move(other.fields)),
    mapKeyType(std::move(other.mapKeyType)),
    valueType(std::move(other.valueType)),
    enumValues(std::move(other.enumValues)),
    __isset(other.__isset) {}
DataType& DataType::operator=(FOLLY_MAYBE_UNUSED DataType&& other) noexcept {
    this->name = std::move(other.name);
    this->fields = std::move(other.fields);
    this->mapKeyType = std::move(other.mapKeyType);
    this->valueType = std::move(other.valueType);
    this->enumValues = std::move(other.enumValues);
    __isset = other.__isset;
    return *this;
}


DataType::DataType(apache::thrift::FragileConstructor, ::std::string name__arg, std::unordered_map<::std::int16_t, ::apache::thrift::reflection::StructField> fields__arg, ::std::int64_t mapKeyType__arg, ::std::int64_t valueType__arg, std::unordered_map<::std::string, ::std::int32_t> enumValues__arg) :
    name(std::move(name__arg)),
    fields(std::move(fields__arg)),
    mapKeyType(std::move(mapKeyType__arg)),
    valueType(std::move(valueType__arg)),
    enumValues(std::move(enumValues__arg)) {
  __isset.name = true;
  __isset.fields = true;
  __isset.mapKeyType = true;
  __isset.valueType = true;
  __isset.enumValues = true;
}

void DataType::__clear() {
  // clear all fields
  this->name = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->fields.clear();
  this->mapKeyType = 0;
  this->valueType = 0;
  this->enumValues.clear();
  __isset = {};
}

bool DataType::operator==(const DataType& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name == rhs.name)) {
    return false;
  }
  if (lhs.fields_ref() != rhs.fields_ref()) {
    return false;
  }
  if (lhs.mapKeyType_ref() != rhs.mapKeyType_ref()) {
    return false;
  }
  if (lhs.valueType_ref() != rhs.valueType_ref()) {
    return false;
  }
  if (lhs.enumValues_ref() != rhs.enumValues_ref()) {
    return false;
  }
  return true;
}

const std::unordered_map<::std::int16_t, ::apache::thrift::reflection::StructField>* DataType::get_fields() const& {
  return fields_ref().has_value() ? std::addressof(fields) : nullptr;
}

std::unordered_map<::std::int16_t, ::apache::thrift::reflection::StructField>* DataType::get_fields() & {
  return fields_ref().has_value() ? std::addressof(fields) : nullptr;
}

const std::unordered_map<::std::string, ::std::int32_t>* DataType::get_enumValues() const& {
  return enumValues_ref().has_value() ? std::addressof(enumValues) : nullptr;
}

std::unordered_map<::std::string, ::std::int32_t>* DataType::get_enumValues() & {
  return enumValues_ref().has_value() ? std::addressof(enumValues) : nullptr;
}


void swap(DataType& a, DataType& b) {
  using ::std::swap;
  swap(a.name_ref().value(), b.name_ref().value());
  swap(a.fields_ref().value_unchecked(), b.fields_ref().value_unchecked());
  swap(a.mapKeyType_ref().value_unchecked(), b.mapKeyType_ref().value_unchecked());
  swap(a.valueType_ref().value_unchecked(), b.valueType_ref().value_unchecked());
  swap(a.enumValues_ref().value_unchecked(), b.enumValues_ref().value_unchecked());
  swap(a.__isset, b.__isset);
}

template void DataType::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t DataType::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t DataType::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t DataType::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void DataType::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t DataType::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t DataType::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t DataType::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        DataType,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>,
        std::unordered_map<::std::int16_t, ::apache::thrift::reflection::StructField>>,
    "inconsistent use of json option");

static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        DataType,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>,
        std::unordered_map<::std::int16_t, ::apache::thrift::reflection::StructField>>,
    "inconsistent use of nimble option");

}}} // apache::thrift::reflection

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::apache::thrift::reflection::Schema>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::apache::thrift::reflection::Schema>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift { namespace reflection {

Schema::Schema(const Schema&) = default;
Schema& Schema::operator=(const Schema&) = default;
Schema::Schema(Schema&& other) noexcept  :
    dataTypes(std::move(other.dataTypes)),
    names(std::move(other.names)),
    __isset(other.__isset) {}
Schema& Schema::operator=(FOLLY_MAYBE_UNUSED Schema&& other) noexcept {
    this->dataTypes = std::move(other.dataTypes);
    this->names = std::move(other.names);
    __isset = other.__isset;
    return *this;
}


Schema::Schema(apache::thrift::FragileConstructor, std::unordered_map<::std::int64_t, ::apache::thrift::reflection::DataType> dataTypes__arg, std::unordered_map<::std::string, ::std::int64_t> names__arg) :
    dataTypes(std::move(dataTypes__arg)),
    names(std::move(names__arg)) {
  __isset.dataTypes = true;
  __isset.names = true;
}

void Schema::__clear() {
  // clear all fields
  this->dataTypes.clear();
  this->names.clear();
  __isset = {};
}

bool Schema::operator==(const Schema& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.dataTypes == rhs.dataTypes)) {
    return false;
  }
  if (!(lhs.names == rhs.names)) {
    return false;
  }
  return true;
}

const std::unordered_map<::std::int64_t, ::apache::thrift::reflection::DataType>& Schema::get_dataTypes() const& {
  return dataTypes;
}

std::unordered_map<::std::int64_t, ::apache::thrift::reflection::DataType> Schema::get_dataTypes() && {
  return std::move(dataTypes);
}

const std::unordered_map<::std::string, ::std::int64_t>& Schema::get_names() const& {
  return names;
}

std::unordered_map<::std::string, ::std::int64_t> Schema::get_names() && {
  return std::move(names);
}


void swap(Schema& a, Schema& b) {
  using ::std::swap;
  swap(a.dataTypes_ref().value(), b.dataTypes_ref().value());
  swap(a.names_ref().value(), b.names_ref().value());
  swap(a.__isset, b.__isset);
}

template void Schema::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Schema::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Schema::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Schema::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Schema::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Schema::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Schema::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Schema::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        Schema,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>,
        std::unordered_map<::std::int64_t, ::apache::thrift::reflection::DataType>>,
    "inconsistent use of json option");

static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        Schema,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>,
        std::unordered_map<::std::int64_t, ::apache::thrift::reflection::DataType>>,
    "inconsistent use of nimble option");

}}} // apache::thrift::reflection
