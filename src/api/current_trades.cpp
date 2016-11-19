#include "api.hpp"

bool qlua::api::ParamRequest(const char* class_code, const char* sec_code, const char* db_name) {
  const char api_name[] = "ParamRequest";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(class_code, sec_code, db_name);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result) == 1;
}
