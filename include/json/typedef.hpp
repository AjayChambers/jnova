#pragma once

#ifndef JSON_TYPE_HPP
#define JSON_TYPE_HPP

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

struct Json;

using Num_J    = std::variant<int, double>;
using Str_J    = std::string;
using Bool_J   = bool;
using Null_J   = std::nullptr_t;
using Arr_J    = std::vector<Json>;
using Obj_J    = std::map<std::string, Json>;
using JsonType = std::variant<Num_J, Str_J, Bool_J, Null_J, Arr_J, Obj_J>;

struct Json : JsonType {
    using JsonType::JsonType;

    Json(const Arr_J &arr);
    Json(Arr_J &&arr);
    Json(const Obj_J &obj);
    Json(Obj_J &&obj);
    Json(std::initializer_list<std::pair<const std::string, Json>> init);
};


#endif
