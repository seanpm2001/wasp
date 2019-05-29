//
// Copyright 2019 WebAssembly Community Group participants
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

#ifndef WASP_BINARY_GLOBAL_H_
#define WASP_BINARY_GLOBAL_H_

#include <functional>

#include "wasp/binary/constant_expression.h"
#include "wasp/binary/global_type.h"

namespace wasp {
namespace binary {

struct Global {
  GlobalType global_type;
  ConstantExpression init;
};

bool operator==(const Global&, const Global&);
bool operator!=(const Global&, const Global&);

}  // namespace binary
}  // namespace wasp

namespace std {

template <>
struct hash<::wasp::binary::Global> {
  size_t operator()(const ::wasp::binary::Global&) const;
};

}  // namespace std

#endif // WASP_BINARY_GLOBAL_H_
