#ifndef ENJINCPPSDK_CREATEPLAYER_HPP
#define ENJINCPPSDK_CREATEPLAYER_HPP

#include "enjinsdk/AbstractGraphqlRequest.hpp"
#include <optional>
#include <string>

namespace enjin::sdk::project {

/// \brief Request for creating a player for the project.
class CreatePlayer : graphql::AbstractGraphqlRequest {
public:
    /// \brief Default constructor.
    CreatePlayer();

    ~CreatePlayer() override = default;

    std::string serialize() override;

    /// \brief Sets the ID of the player.
    /// \param id The ID.
    /// \return This request for chaining.
    CreatePlayer& set_id(const std::string& id);

    bool operator==(const CreatePlayer& rhs) const;

    bool operator!=(const CreatePlayer& rhs) const;

private:
    std::optional<std::string> id;
};

}

#endif //ENJINCPPSDK_CREATEPLAYER_HPP