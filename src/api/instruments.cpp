#include "api.hpp"

const char* qlua::api::getClassesList() {
  const char api_name[] = "getClassesList";
  typedef std::tuple<const char*> return_type;
  auto result = lua_.pcall<return_type>(api_name, std::tuple<>{});
  return std::get<0>(result);
}

auto qlua::api::getClassInfo(const char* class_name) -> class_info {
  const char api_name[] = "getClassInfo";
  typedef std::tuple<class_info> return_type;
  auto params = std::make_tuple(class_name);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}

const char* qlua::api::getClassSecurities(const char* class_name) {
  const char api_name[] = "getClassSecurities";
  typedef std::tuple<const char*> return_type;
  auto params = std::make_tuple(class_name);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}
