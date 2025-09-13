#pragma once

#ifndef JNOVA_HPP
#define JNOVA_HPP

#include <map>
#include <set>
#include <vector>

#include <exception>
#include <format>
#include <functional>
#include <iostream>
#include <source_location>
#include <string>
#include <variant>

namespace JNOVA {

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




class Error : std::exception {
  std::source_location srcLoc;
  const char *func;
  const char *file;
  uint32_t line;


public:
  inline Error(std::source_location srcLoc)
  : srcLoc(srcLoc)
  {
    auto foo = srcLoc.function_name();
  }

  inline ~Error()
  {
    delete this->func;
    delete this->file;
  }


  inline const char *what() const noexcept override //
  {
    return "An error has occurred";
  }
};
};
#endif