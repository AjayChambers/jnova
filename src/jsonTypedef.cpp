#include <json/typedef.hpp>

using namespace std;



Json::Json(const Arr_J &arr)
: JsonType(arr)
{}



Json::Json(Arr_J &&arr)
: JsonType(std::move(arr))
{}



Json::Json(const Obj_J &obj)
: JsonType(obj)
{}



Json::Json(Obj_J &&obj)
: JsonType(std::move(obj))
{}



Json::Json(std::initializer_list<std::pair<const std::string, Json>> init)
: JsonType(Obj_J(init))
{}










/*







*-------------------------------------------*
    <> COMPILER ERROR CHECKING SANDBOX <>
*-------------------------------------------*

void iterate_json(const Json &j, int indent = 0)
{
  auto pad = string(indent, ' ');

  visit(
   [&](auto &&value) {

   },
   static_cast<const JsonType &>(j));
}


Json j = {
  {"a", "b"},
  {"true", nullptr},
  {"newObject",
  Obj_J(
    {{"fig", "watermelon"},
    {"lime", "raspberry"},
    {"pear", "apricot"},
    {"apple", "orange"},
    {"grape", "cherry"},
    {"peach", "avocado"},
    {"Numbers", Arr_J({2, 4, 8, 16, "HelloWorld", 32, 64, 128})},
    {"Booleans", Arr_J({false, 4, nullptr, true, true, true})},
    {"nulls", Arr_J({nullptr, nullptr})}})}};

    JsonType jsonType = Arr_J{1, 2};

*/