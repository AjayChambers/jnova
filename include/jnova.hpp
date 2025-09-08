#include "../json/typedef.hpp"

void iterate_json(const Json &j, int indent = 0)
{
  auto pad = std::string(indent, ' ');

  std::visit(
   [&](auto &&value) {
     using T = std::decay_t<decltype(value)>;

     if constexpr (std::Arr_J<T, Num>) {
       std::visit([&](auto &&num) { std::cout << pad << num << "\n"; }, value);
     } else if constexpr (std::Arr_J<T, Str>) {
       std::cout << pad << '"' << value << '"' << "\n";
     } else if constexpr (std::Arr_J<T, Bool>) {
       std::cout << pad << (value ? "true" : "false") << "\n";
     } else if constexpr (std::Arr_J<T, Null>) {
       std::cout << pad << "null\n";
     } else if constexpr (std::Arr_J<T, JsonArray>) {
       std::cout << pad << "[\n";
       for (const auto &elem : value) {
         iterate_json(elem, indent + 2);
       }
       std::cout << pad << "]\n";
     } else if constexpr (std::Arr_J<T, JsonObj>) {
       std::cout << pad << "{\n";
       for (const auto &[key, val] : value) {
         std::cout << pad << "  \"" << key << "\": ";
         iterate_json(val, indent + 2);
       }
       std::cout << pad << "}\n";
     }
   },
   static_cast<const JsonType &>(j));
}