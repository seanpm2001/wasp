//
// Copyright 2018 WebAssembly Community Group participants
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef WASP_BASE_FORMATTERS_H_
#define WASP_BASE_FORMATTERS_H_

#include <vector>

#include "wasp/base/at.h"
#include "wasp/base/features.h"
#include "wasp/base/format.h"
#include "wasp/base/formatter_macros.h"
#include "wasp/base/optional.h"
#include "wasp/base/span.h"
#include "wasp/base/string_view.h"
#include "wasp/base/v128.h"
#include "wasp/base/variant.h"
#include "wasp/base/wasm_types.h"

namespace fmt {

// Convert from a fmt::basic_memory_buffer to a fmt::string_view. Not sure why
// this conversion was omitted from the fmt library.
template <typename T, std::size_t SIZE, typename Allocator>
string_view to_string_view(const basic_memory_buffer<T, SIZE, Allocator>&);

// At<T>
template <typename T>
struct formatter<::wasp::At<T>> : formatter<T> {
  template <typename Ctx>
  typename Ctx::iterator format(const ::wasp::At<T>&, Ctx&);
};

// span<const T>
template <typename T>
struct formatter<::wasp::span<const T>> : formatter<string_view> {
  template <typename Ctx>
  typename Ctx::iterator format(::wasp::span<const T>, Ctx&);
};

// std::vector<T>
template <typename T>
struct formatter<std::vector<T>> : formatter<::wasp::span<const T>> {
  template <typename Ctx>
  typename Ctx::iterator format(const std::vector<T>&, Ctx&);
};

// variant<Ts...>
template <typename... Ts>
struct formatter<::wasp::variant<Ts...>> : formatter<string_view> {
  template <typename Ctx>
  typename Ctx::iterator format(const ::wasp::variant<Ts...>&, Ctx&);
};

// optional<T>
template <typename T>
struct formatter<::wasp::optional<T>> : formatter<string_view> {
  template <typename Ctx>
  typename Ctx::iterator format(const ::wasp::optional<T>&, Ctx&);
};

WASP_DECLARE_FORMATTER(string_view)
WASP_DECLARE_FORMATTER(SpanU8)
WASP_DECLARE_FORMATTER(v128);
WASP_DECLARE_FORMATTER(Opcode);
WASP_DECLARE_FORMATTER(ValueType);
WASP_DECLARE_FORMATTER(ElementType);
WASP_DECLARE_FORMATTER(ExternalKind);
WASP_DECLARE_FORMATTER(EventAttribute);
WASP_DECLARE_FORMATTER(Mutability);
WASP_DECLARE_FORMATTER(SegmentType);
WASP_DECLARE_FORMATTER(Shared);
WASP_DECLARE_FORMATTER(Limits);
WASP_DECLARE_FORMATTER(Features);
WASP_DECLARE_FORMATTER(monostate);

}  // namespace fmt

namespace wasp {

template <typename T>
struct VariantName { const char* GetName() const; };

#define WASP_DEFINE_VARIANT_NAME(Type, Name)     \
  template <>                                    \
  struct VariantName<Type> {                     \
    const char* GetName() const { return Name; } \
  };

WASP_DEFINE_VARIANT_NAME(u8, "u8")
WASP_DEFINE_VARIANT_NAME(u16, "u16")
WASP_DEFINE_VARIANT_NAME(u32, "u32")
WASP_DEFINE_VARIANT_NAME(u64, "u64")
WASP_DEFINE_VARIANT_NAME(s8, "s8")
WASP_DEFINE_VARIANT_NAME(s16, "s16")
WASP_DEFINE_VARIANT_NAME(s32, "s32")
WASP_DEFINE_VARIANT_NAME(s64, "s64")
WASP_DEFINE_VARIANT_NAME(f32, "f32")
WASP_DEFINE_VARIANT_NAME(f64, "f64")

WASP_DEFINE_VARIANT_NAME(ValueType, "value_type")

// TODO: More base types.

}  // namespace wasp

#include "wasp/base/formatters-inl.h"

#endif // WASP_BASE_FORMATTERS_H_
