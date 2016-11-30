#include "api.hpp"

auto qlua::api::getMoney(const char* client_code,
                         const char* firmid,
                         const char* tag,
                         const char* currcode) -> money_limits {
  const char api_name[] = "getMoney";
  typedef std::tuple<money_limits> return_type;
  auto params = std::make_tuple(client_code, firmid, tag, currcode);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result); 
}

auto qlua::api::getMoneyEx(const char* firm_id, const char* client_code,
                           const char* tag, const char* curr_code,
                           unsigned int limit_kind) -> money_limits {
  const char api_name[] = "getMoneyEx";
  typedef std::tuple<money_limits> return_type;
  auto params = std::make_tuple(firm_id, client_code, tag, curr_code, limit_kind);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);   
}

auto qlua::api::getDepo(const char* client_code, const char* firmid,
             const char* sec_code, const char * account) -> depo_limits {
  const char api_name[] = "getDepo";
  typedef std::tuple<depo_limits> return_type;
  auto params = std::make_tuple(client_code, firmid, sec_code, account);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);   
}

auto qlua::api::getDepoEx(const char* firm_id, const char* client_code,
                      const char* sec_code, const char* acc_id,
                      unsigned int limit_kind) -> depo_limits {
  const char api_name[] = "getDepoEx";
  typedef std::tuple<depo_limits> return_type;
  auto params = std::make_tuple(firm_id, client_code, sec_code, acc_id, limit_kind);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);   
}

auto qlua::api::getFuturesLimit(const char* firm_id, const char* acc_id,
                          unsigned int limit_type, const char* curr_code) -> futures_limits {
  const char api_name[] = "getFuturesLimit";
  typedef std::tuple<futures_limits> return_type;
  auto params = std::make_tuple(firm_id, acc_id, limit_type, curr_code);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);   
}

auto qlua::api::getFuturesHolding(const char* firm_id, const char* acc_id,
                                  const char* sec_code, unsigned int pos_type) -> futures_holdings {
  const char api_name[] = "getFuturesHolding";
  typedef std::tuple<futures_holdings> return_type;
  auto params = std::make_tuple(firm_id, acc_id, sec_code, pos_type);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);   
}

auto qlua::api::getSecurityInfo(const char* class_code, const char* sec_code) -> instrument {
  const char api_name[] = "getSecurityInfo";
  typedef std::tuple<instrument> return_type;
  auto params = std::make_tuple(class_code, sec_code);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}

auto qlua::api::getTradeDate() -> date_table {
  const char api_name[] = "getTradeDate";
  typedef std::tuple<date_table> return_type;
  auto result = lua_.pcall<return_type>(api_name, std::tuple<>());
  return std::get<0>(result);
}

auto qlua::api::getQuoteLevel2(const char* class_code, const char* sec_code) -> quote_level_2 {
  const char api_name[] = "getQuoteLevel2";
  typedef std::tuple<quote_level_2> return_type;
  auto params = std::make_tuple(class_code, sec_code);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}

auto qlua::api::getParamEx(const char* class_code, const char* sec_code, const char* param_name) -> param {
  const char api_name[] = "getParamEx";
  typedef std::tuple<param> return_type;
  auto params = std::make_tuple(class_code, sec_code, param_name);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);
}


