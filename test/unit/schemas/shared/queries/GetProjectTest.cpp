#include "enjinsdk/shared/GetProject.hpp"
#include "../../../../suites/JsonTestSuite.hpp"
#include <string>

using namespace enjin::sdk::shared;

class GetProjectTest : public JsonTestSuite {
public:
    GetProject class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"id":1,"name":"1"})";

    static GetProject create_default_request() {
        return GetProject().set_id(1)
                           .set_name("1");
    }
};

TEST_F(GetProjectTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetProjectTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_id(1)
                    .set_name("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(GetProjectTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    GetProject lhs;
    GetProject rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetProjectTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    GetProject lhs = create_default_request();
    GetProject rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(GetProjectTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    GetProject lhs = create_default_request();
    GetProject rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(GetProjectTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    GetProject lhs;
    GetProject rhs = create_default_request();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}
