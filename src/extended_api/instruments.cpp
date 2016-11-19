#include "extended_api.hpp"

#include <cstring>

static std::vector<std::string> comma_string_to_vector(const char* s) {
  std::vector<std::string> rslt;
  std::string cl;
  for (unsigned int i = 0; i < strlen(s); ++i) {
    if (s[i] == ',') {
      if (cl.size() > 0) rslt.push_back(cl);
      cl.clear();
    } else {
      cl.push_back(s[i]);
    }
  }
  if (cl.size() > 0) rslt.push_back(cl);
  return rslt;
}

void qlua::extended_api::getClassesList(std::vector<std::string>& classes_list) {
  classes_list = comma_string_to_vector(getClassesList());
}

void qlua::extended_api::getClassSecurities(const char* class_name, std::vector<std::string>& class_securities) {
  class_securities = comma_string_to_vector(getClassSecurities(class_name));
}
