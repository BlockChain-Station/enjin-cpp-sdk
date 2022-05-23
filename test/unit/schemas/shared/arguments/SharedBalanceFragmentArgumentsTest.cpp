/* Copyright 2021 Enjin Pte. Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gtest/gtest.h"
#include "BalanceFragmentArgumentsTestSuite.hpp"
#include "JsonTestSuite.hpp"
#include "TestableSharedBalanceFragmentArguments.hpp"
#include <string>

using namespace enjin::test::suites;
using namespace enjin::test::utils;

class SharedBalanceFragmentArgumentsTest
        : public BalanceFragmentArgumentsTestSuite<TestableSharedBalanceFragmentArguments>,
          public JsonTestSuite,
          public testing::Test {
public:
    TestableSharedBalanceFragmentArguments class_under_test;

    static TestableSharedBalanceFragmentArguments create_default_arguments() {
        TestableSharedBalanceFragmentArguments arguments;
        set_balance_fragment_arguments(arguments);
        return arguments;
    }
};

TEST_F(SharedBalanceFragmentArgumentsTest, SerializeNoSetFieldsReturnsEmptyJson) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(SharedBalanceFragmentArgumentsTest, SerializeSetBalanceFragmentFieldsReturnsExpectedJson) {
    // Arrange
    const std::string expected(BalanceFragmentJson);
    set_balance_fragment_arguments(class_under_test);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(SharedBalanceFragmentArgumentsTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    TestableSharedBalanceFragmentArguments lhs;
    TestableSharedBalanceFragmentArguments rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(SharedBalanceFragmentArgumentsTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    TestableSharedBalanceFragmentArguments lhs = create_default_arguments();
    TestableSharedBalanceFragmentArguments rhs = create_default_arguments();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(SharedBalanceFragmentArgumentsTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    TestableSharedBalanceFragmentArguments lhs = create_default_arguments();
    TestableSharedBalanceFragmentArguments rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(SharedBalanceFragmentArgumentsTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    TestableSharedBalanceFragmentArguments lhs;
    TestableSharedBalanceFragmentArguments rhs = create_default_arguments();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
