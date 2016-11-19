#include "api.hpp"

bool qlua::api::Subscribe_Level_II_Quotes(const char* class_code, const char* sec_code) {
  const char api_name[] = "Subscribe_Level_II_Quotes";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(class_code, sec_code);
  auto rslt = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(rslt) == 1;
}

bool qlua::api::Unsubscribe_Level_II_Quotes(const char* class_code, const char* sec_code) {
  const char api_name[] = "Unsubscribe_Level_II_Quotes";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(class_code, sec_code);
  auto rslt = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(rslt) == 1;
}
  
bool qlua::api::IsSubscribed_Level_II_Quotes(const char* class_code, const char* sec_code) {
  const char api_name[] = "IsSubscribed_Level_II_Quotes";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(class_code, sec_code);
  auto rslt = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(rslt) == 1;
}
