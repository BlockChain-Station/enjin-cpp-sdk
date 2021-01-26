#ifndef ENJINCPPSDK_SETTRANSFERFEE_HPP
#define ENJINCPPSDK_SETTRANSFERFEE_HPP

#include "enjinsdk/AbstractGraphqlRequest.hpp"
#include "enjinsdk/shared/TransactionRequestArgumentsTemplate.hpp"
#include <optional>
#include <string>

namespace enjin::sdk::project {

/// \brief Request for setting the transfer fee of a item.
class SetTransferFee : public graphql::AbstractGraphqlRequest,
                       public shared::TransactionRequestArgumentsTemplate<SetTransferFee> {
public:
    /// \brief Default constructor.
    SetTransferFee();

    ~SetTransferFee() override = default;

    std::string serialize() override;

    /// \brief Sets the token ID.
    /// \param token_id The ID.
    /// \return This request for chaining.
    SetTransferFee& set_token_id(const std::string& token_id);

    /// \brief Sets the index for non-fungible items.
    /// \param token_index The index.
    /// \return This request for chaining.
    SetTransferFee& set_token_index(const std::string& token_index);

    /// \brief Sets the new transfer fee value in Wei.
    /// \param transfer_fee The new transfer fee.
    /// \return This request for chaining.
    SetTransferFee& set_transfer_fee(const std::string& transfer_fee);

    bool operator==(const SetTransferFee& rhs) const;

    bool operator!=(const SetTransferFee& rhs) const;

private:
    std::optional<std::string> token_id;
    std::optional<std::string> token_index;
    std::optional<std::string> transfer_fee;
};

}

#endif //ENJINCPPSDK_SETTRANSFERFEE_HPP
