#include <json/typedef.hpp>

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"

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
