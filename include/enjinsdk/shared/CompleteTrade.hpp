#ifndef ENJINCPPSDK_COMPLETETRADE_HPP
#define ENJINCPPSDK_COMPLETETRADE_HPP

#include "enjinsdk/AbstractGraphqlRequest.hpp"
#include "enjinsdk/shared/TransactionRequestArgumentsTemplate.hpp"
#include <optional>
#include <string>

namespace enjin::sdk::shared {

/// \brief Request for completing a trade between two wallets.
class CompleteTrade : public graphql::AbstractGraphqlRequest,
                      public TransactionRequestArgumentsTemplate<CompleteTrade> {
public:
    /// \brief Default constructor.
    CompleteTrade();

    ~CompleteTrade() override = default;

    std::string serialize() override;

    /// \brief Sets the trade ID.
    /// \param id The ID.
    /// \return This request for chaining.
    CompleteTrade& set_trade_id(const std::string& id);

    bool operator==(const CompleteTrade& rhs) const;

    bool operator!=(const CompleteTrade& rhs) const;

private:
    std::optional<std::string> trade_id;
};

}

#endif //ENJINCPPSDK_COMPLETETRADE_HPP