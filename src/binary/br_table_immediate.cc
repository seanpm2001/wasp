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

#include "wasp/binary/br_table_immediate.h"

#include "src/base/operator_eq_ne_macros.h"
#include "wasp/base/hash.h"

namespace wasp {
namespace binary {

WASP_OPERATOR_EQ_NE_2(BrTableImmediate, targets, default_target)

}  // namespace binary
}  // namespace wasp

namespace std {
size_t hash<::wasp::binary::BrTableImmediate>::operator()(
    const ::wasp::binary::BrTableImmediate& v) const {
  return ::wasp::HashState::combine(0, ::wasp::HashContainer(v.targets),
                                    v.default_target);
}
}  // namespace std
