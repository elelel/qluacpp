#include "api.hpp"

auto qlua::api::getOrderByNumber(const char* class_code, unsigned int order_id) -> std::tuple<order, unsigned int> {
  const char api_name[] = "getOrderByNumber";
  typedef std::tuple<order, unsigned int> return_type;
  auto params = std::make_tuple(class_code, order_id);
  auto result = lua_.pcall<return_type>(api_name, params);
  return result;
}

unsigned int qlua::api::getNumberOf(const char* table_name) {
  const char api_name[] = "getNumberOf";
  typedef std::tuple<unsigned int> return_type;
  auto params = std::make_tuple(table_name);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}



