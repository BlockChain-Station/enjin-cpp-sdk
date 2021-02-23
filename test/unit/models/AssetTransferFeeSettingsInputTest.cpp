#include "enjinsdk/models/AssetTransferFeeSettings.hpp"
#include "../../suites/JsonTestSuite.hpp"
#include <string>

using namespace enjin::sdk::models;

class AssetTransferFeeSettingsInputTest : public JsonTestSuite {
public:
    AssetTransferFeeSettingsInput class_under_test;

    constexpr static char POPULATED_JSON_OBJECT[] =
            R"({"type":"NONE","assetId":"1","value":"1"})";

    static AssetTransferFeeSettingsInput create_default_transfer_fee_settings_input() {
        return AssetTransferFeeSettingsInput().set_type(AssetTransferFeeType::NONE)
                                              .set_asset_id("1")
                                              .set_value("1");
    }
};

TEST_F(AssetTransferFeeSettingsInputTest, SerializeNoSetFieldsReturnsEmptyJsonObject) {
    // Arrange
    const std::string expected(EMPTY_JSON_OBJECT);

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(AssetTransferFeeSettingsInputTest, SerializeSetFieldsReturnsExpectedJsonObject) {
    // Arrange
    const std::string expected(POPULATED_JSON_OBJECT);
    class_under_test.set_type(AssetTransferFeeType::NONE)
                    .set_asset_id("1")
                    .set_value("1");

    // Act
    std::string actual = class_under_test.serialize();

    // Assert
    ASSERT_EQ(expected, actual);
}

TEST_F(AssetTransferFeeSettingsInputTest, EqualityNeitherSideIsPopulatedReturnsTrue) {
    // Arrange
    AssetTransferFeeSettingsInput lhs;
    AssetTransferFeeSettingsInput rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(AssetTransferFeeSettingsInputTest, EqualityBothSidesArePopulatedReturnsTrue) {
    // Arrange
    AssetTransferFeeSettingsInput lhs = create_default_transfer_fee_settings_input();
    AssetTransferFeeSettingsInput rhs = create_default_transfer_fee_settings_input();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_TRUE(actual);
}

TEST_F(AssetTransferFeeSettingsInputTest, EqualityLeftSideIsPopulatedReturnsFalse) {
    // Arrange
    AssetTransferFeeSettingsInput lhs = create_default_transfer_fee_settings_input();
    AssetTransferFeeSettingsInput rhs;

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}

TEST_F(AssetTransferFeeSettingsInputTest, EqualityRightSideIsPopulatedReturnsFalse) {
    // Arrange
    AssetTransferFeeSettingsInput lhs;
    AssetTransferFeeSettingsInput rhs = create_default_transfer_fee_settings_input();

    // Act
    bool actual = lhs == rhs;

    // Assert
    ASSERT_FALSE(actual);
}