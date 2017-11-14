#pragma once

bool ParamRequest(const std::string& class_code,
                  const std::string& sec_code,
                  const std::string& db_name) const {
  return api::ParamRequest(class_code.c_str(), sec_code.c_str(), db_name.c_str());
}

bool ParamRequest(const char* class_code,
                  const char* sec_code,
                  const char* db_name) const {
  return api::ParamRequest(class_code, sec_code, db_name);
}

bool CancelParamRequest(const std::string& class_code,
                        const std::string& sec_code,
                        const std::string& db_name) const {
  return api::CancelParamRequest(class_code.c_str(), sec_code.c_str(), db_name.c_str());
}

bool CancelParamRequest(const char* class_code,
                        const char* sec_code,
                        const char* db_name) const {
  return api::CancelParamRequest(class_code, sec_code, db_name);
}

