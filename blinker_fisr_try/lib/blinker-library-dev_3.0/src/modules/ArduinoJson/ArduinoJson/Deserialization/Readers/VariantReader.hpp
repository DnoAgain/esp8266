// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2022, Benoit BLANCHON
// MIT License

#pragma once

#include "../../Object/MemberProxy.hpp"
#include "../../Variant/VariantRef.hpp"

namespace ARDUINOJSON_NAMESPACE {

template <typename TArray>
struct Reader<ElementProxy<TArray>, void> : Reader<char*, void> {
  explicit Reader(const ElementProxy<TArray>& x)
      : Reader<char*, void>(x.template as<const char*>()) {}
};

template <typename TObject, typename TStringRef>
struct Reader<MemberProxy<TObject, TStringRef>, void> : Reader<char*, void> {
  explicit Reader(const MemberProxy<TObject, TStringRef>& x)
      : Reader<char*, void>(x.template as<const char*>()) {}
};

template <>
struct Reader<VariantRef, void> : Reader<char*, void> {
  explicit Reader(VariantRef x) : Reader<char*, void>(x.as<const char*>()) {}
};

template <>
struct Reader<VariantConstRef, void> : Reader<char*, void> {
  explicit Reader(VariantConstRef x)
      : Reader<char*, void>(x.as<const char*>()) {}
};
}  // namespace ARDUINOJSON_NAMESPACE
