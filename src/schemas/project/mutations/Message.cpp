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

#include "enjinsdk/project/Message.hpp"

#include "enjinsdk/JsonUtils.hpp"

using namespace enjin::sdk::graphql;
using namespace enjin::sdk::json;
using namespace enjin::sdk::project;
using namespace enjin::sdk::utils;

Message::Message() : AbstractGraphqlRequest("enjin.sdk.project.Message"),
                     TransactionRequestArguments<Message>() {
}

std::string Message::serialize() const {
    return to_json().to_string();
}

Message& Message::set_message(std::string message) {
    message_opt = std::move(message);
    return *this;
}

JsonValue Message::to_json() const {
    JsonValue json = JsonValue::create_object();

    JsonUtils::join_object(json, TransactionRequestArguments<Message>::to_json());
    JsonUtils::try_set_field(json, "message", message_opt);

    return json;
}

bool Message::operator==(const Message& rhs) const {
    return static_cast<const AbstractGraphqlRequest&>(*this) == rhs
           && static_cast<const TransactionRequestArguments<Message>&>(*this) == rhs
           && message_opt == rhs.message_opt;
}

bool Message::operator!=(const Message& rhs) const {
    return !(*this == rhs);
}
