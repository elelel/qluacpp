#include "api.hpp"

#include "../exceptions.hpp"

// Service
bool qlua::api::isConnected() {
  const char api_name[] = "isConnected";
  typedef std::tuple<int> return_type;
  auto rslt = lua_.pcall<return_type>(api_name, std::tuple<>{});
  return std::get<0>(rslt) == 1;
}

const char* qlua::api::getScriptPath() {
  const char api_name[] = "getScriptPath";
  typedef std::tuple<const char*> return_type;
  auto rslt = lua_.pcall<return_type>(api_name, std::tuple<>{});
  return std::get<0>(rslt);
}

const char* qlua::api::getInfoParam(const char* param_name) {
  const char api_name[] = "getInfoParam";
  typedef std::tuple<const char*> return_type;
  auto params = std::make_tuple(param_name);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}

void qlua::api::message(const char* text, const unsigned int icon) {
  const char api_name[] = "message";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(text, icon);
  lua_.pcall<return_type>(api_name, params);
}

void qlua::api::message(const char* text) {
  message(text, 1);
}

void qlua::api::sleep(int ms) {
  const char api_name[] = "sleep";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(ms);
  auto result = lua_.pcall<return_type>(api_name, params);
  if (std::get<0>(result) != ms) {
    throw error::sleep_failed(ms, std::get<0>(result));
  }
}

const char* qlua::api::getWorkingFolder() {
  const char api_name[] = "getWorkingFolder";
  typedef std::tuple<const char*> return_type;
  auto result = lua_.pcall<return_type>(api_name, std::tuple<>());
  return std::get<0>(result);
}

void qlua::api::PrintDbgStr(const char* s) {
  const char api_name[] = "PrintDbgStr";
  typedef std::tuple<> return_type;
  auto params = std::make_tuple(s);
  lua_.pcall<return_type>(api_name, params);
}
