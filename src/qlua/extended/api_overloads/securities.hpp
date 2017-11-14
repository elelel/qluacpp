#pragma once

void getClassInfo(const std::string& class_name,
                  std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::class_info_getClassInfo>>&)> lambda) const {
  api::getClassInfo(class_name.c_str(), lambda);
}

void getClassInfo(const char* class_name,
                  std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::class_info_getClassInfo>>&)> lambda) const {
  api::getClassInfo(class_name, lambda);
}

const char* getClassSecurities(const std::string& class_name) const {
  return api::getClassSecurities(class_name.c_str());
}

const char* getClassSecurities(const char* class_name) const {
  return api::getClassSecurities(class_name);
}
