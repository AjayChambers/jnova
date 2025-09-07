#pragma once

#ifndef JSON_TYPE_HPP
#define JSON_TYPE_HPP

#include <map>
#include <string>
#include <variant>
#include <vector>

struct Json; // forward declare

using Num       = std::variant<int, double>;
using Str       = std::string;
using Bool      = bool;
using Null      = std::nullptr_t;
using JsonArray = std::vector<Json>;
using JsonObj   = std::map<std::string, Json>;

using JsonType = std::variant<Num, Str, Bool, Null, JsonArray, JsonObj>;

struct Json : JsonType {
  using JsonType::JsonType;

  Json(const JsonArray &arr)
  : JsonType(arr)
  {}

  Json(JsonArray &&arr)
  : JsonType(std::move(arr))
  {}

  Json(const JsonObj &obj)
  : JsonType(obj)
  {}

  Json(JsonObj &&obj)
  : JsonType(std::move(obj))
  {}

  Json(std::initializer_list<std::pair<const std::string, Json>> init)
  : JsonType(JsonObj(init))
  {}
};


#endif
