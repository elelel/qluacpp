#pragma once

void getParamEx(const std::string& class_code,
                const std::string& sec_code,
                const std::string& param_name,
                std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::current_trades_getParamEx>>&)> lambda) const {
  api::getParamEx(class_code.c_str(), sec_code.c_str(), param_name.c_str(), lambda);
}

void getParamEx(const char* class_code,
                const char* sec_code,
                const char* param_name,
                std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::current_trades_getParamEx>>&)> lambda) const {
  api::getParamEx(class_code, sec_code, param_name, lambda);
}

void getParamEx2(const std::string& class_code,
                 const std::string& sec_code,
                 const std::string& param_name,
                 std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::current_trades_getParamEx>>&)> lambda) const {
  api::getParamEx2(class_code.c_str(), sec_code.c_str(), param_name.c_str(), lambda);
}


void getParamEx2(const char* class_code,
                 const char* sec_code,
                 const char* param_name,
                 std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::current_trades_getParamEx>>&)> lambda) const {
  api::getParamEx2(class_code, sec_code, param_name, lambda);
}
