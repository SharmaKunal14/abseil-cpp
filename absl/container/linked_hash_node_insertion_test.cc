// Copyright 2026 The Abseil Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <utility>

#include "gtest/gtest.h"
#include "absl/container/linked_hash_map.h"
#include "absl/container/linked_hash_set.h"

namespace {

TEST(LinkedHashNodeInsertionTest, EmptySetNodeReturnsEndWithoutMutation) {
  absl::linked_hash_set<int> values = {7};
  absl::linked_hash_set<int>::node_type empty;
  EXPECT_EQ(values.insert(values.begin(), std::move(empty)), values.end());
  EXPECT_TRUE(empty.empty());
  ASSERT_EQ(values.size(), 1);
  EXPECT_EQ(*values.begin(), 7);
}

TEST(LinkedHashNodeInsertionTest, EmptyMapNodeReturnsEndWithoutMutation) {
  absl::linked_hash_map<int, int> values = {{7, 11}};
  absl::linked_hash_map<int, int>::node_type empty;
  EXPECT_EQ(values.insert(values.begin(), std::move(empty)), values.end());
  EXPECT_TRUE(empty.empty());
  ASSERT_EQ(values.size(), 1);
  EXPECT_EQ(values.begin()->first, 7);
  EXPECT_EQ(values.begin()->second, 11);
}

}  // namespace
