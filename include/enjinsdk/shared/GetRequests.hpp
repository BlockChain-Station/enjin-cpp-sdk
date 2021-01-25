#ifndef ENJINCPPSDK_GETREQUESTS_HPP
#define ENJINCPPSDK_GETREQUESTS_HPP

#include "enjinsdk/AbstractGraphqlRequest.hpp"
#include "enjinsdk/models/TransactionFilter.hpp"
#include "enjinsdk/models/TransactionSort.hpp"
#include "enjinsdk/shared/PaginationArgumentsTemplate.hpp"
#include "enjinsdk/shared/TransactionFragmentArgumentsTemplate.hpp"
#include <optional>

namespace enjin::sdk::shared {

/// \brief Request for getting transactions on the platform.
class GetRequests : public graphql::AbstractGraphqlRequest,
                    public TransactionFragmentArgumentsTemplate<GetRequests>,
                    public PaginationArgumentsTemplate<GetRequests> {
public:
    /// \brief Default constructor.
    GetRequests();

    ~GetRequests() override = default;

    std::string serialize() override;

    /// \brief Sets the filter the request will use.
    /// \param filter The filter.
    /// \return This request for chaining.
    GetRequests& set_filter(const models::TransactionFilter& filter);

    /// Sets the request to sort the results by the specified options.
    /// \param sort The sort options.
    /// \return This request for chaining.
    GetRequests& set_sort(const models::TransactionSort& sort);

    bool operator==(const GetRequests& rhs) const;

    bool operator!=(const GetRequests& rhs) const;

private:
    std::optional<models::TransactionFilter> filter;
    std::optional<models::TransactionSort> sort;
};

}

#endif //ENJINCPPSDK_GETREQUESTS_HPP