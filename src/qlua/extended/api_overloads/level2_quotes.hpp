#pragma once

bool Subscribe_Level_II_Quotes(const std::string& class_code,
                               const std::string& sec_code) const {
  return api::Subscribe_Level_II_Quotes(class_code.c_str(), sec_code.c_str());
}

bool Subscribe_Level_II_Quotes(const char* class_code,
                               const char* sec_code) const {
  return api::Subscribe_Level_II_Quotes(class_code, sec_code);
}

bool Unsubscribe_Level_II_Quotes(const std::string& class_code,
                                 const std::string& sec_code) const {
  return api::Unsubscribe_Level_II_Quotes(class_code.c_str(), sec_code.c_str());
}

bool Unsubscribe_Level_II_Quotes(const char* class_code,
                                 const char* sec_code) const {
  return api::Unsubscribe_Level_II_Quotes(class_code, sec_code);
}

bool IsSubscribed_Level_II_Quotes(const std::string& class_code,
                                  const std::string& sec_code) const {
  return api::IsSubscribed_Level_II_Quotes(class_code.c_str(), sec_code.c_str());
}

bool IsSubscribed_Level_II_Quotes(const char* class_code,
                                  const char* sec_code) const {
  return api::IsSubscribed_Level_II_Quotes(class_code, sec_code);
}
