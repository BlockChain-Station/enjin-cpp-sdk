#include "RapidJsonUtils.hpp"

namespace enjin::sdk::utils {

std::string document_to_string(const rapidjson::Document& document) {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    return std::string(buffer.GetString());
}

std::vector<std::string> get_array_as_serialized_vector(const rapidjson::Document& document, const std::string& key) {
    if (key.empty() && document.IsArray()) {
        std::vector<std::string> v;
        for (auto& arr_el : document.GetArray()) {
            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            arr_el.Accept(writer);
            v.emplace_back(buffer.GetString());
        }
        return v;
    } else if (!key.empty() && document[key.c_str()].IsArray()) {
        std::vector<std::string> v;
        for (auto& arr_el : document[key.c_str()].GetArray()) {
            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            arr_el.Accept(writer);
            v.emplace_back(buffer.GetString());
        }
        return v;
    }

    throw std::exception("JSON element is not an array");
}

std::string get_object_as_string(const rapidjson::Document& document, const std::string& key) {
    if (key.empty() && document.IsObject()) {
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        return buffer.GetString();
    } else if (!key.empty() && document[key.c_str()].IsObject()) {
        auto& v_value = document[key.c_str()];
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        v_value.Accept(writer);
        return buffer.GetString();
    }

    throw std::exception("JSON element is not an object");
}

void set_member_assert(const rapidjson::Document& document, const std::string& key) {
    if (!document.IsObject()) {
        throw std::exception("Document is not a Json Object");
    } else if (key.empty()) {
        throw std::exception("Key string is empty");
    }
}

void set_array_member_from_string_vector(rapidjson::Document& document,
                                         const std::string& key,
                                         const std::vector<std::string>& values) {
    set_member_assert(document, key);

    auto& allocator = document.GetAllocator();
    rapidjson::Value v(rapidjson::kArrayType);
    for (auto& e : values) {
        rapidjson::Value e_value;
        e_value.SetString(e.c_str(), allocator);
        v.PushBack(e_value, allocator);
    }

    rapidjson::Value v_key;
    v_key.SetString(key.c_str(), allocator);
    document.AddMember(v_key, v, allocator);
}

void set_integer_member(rapidjson::Document& document, const std::string& key, int value) {
    set_member_assert(document, key);

    auto& allocator = document.GetAllocator();
    rapidjson::Value v_key;
    rapidjson::Value v;
    v_key.SetString(key.c_str(), allocator);
    v.SetInt(value);
    document.AddMember(v_key, v, allocator);
}

void set_string_member(rapidjson::Document& document, const std::string& key, const std::string& value) {
    set_member_assert(document, key);

    auto& allocator = document.GetAllocator();
    rapidjson::Value v_key;
    rapidjson::Value v;
    v_key.SetString(key.c_str(), allocator);
    v.SetString(value.c_str(), allocator);
    document.AddMember(v_key, v, allocator);
}

}
