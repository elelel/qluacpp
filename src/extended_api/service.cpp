#include "extended_api.hpp"

const char* qlua::extended_api::getInfoParam(const std::string& param_name) {
  return getInfoParam(param_name.c_str());
}

void qlua::extended_api::message(const char* text, const message_icon i) {
  message(text, static_cast<int>(i));
}

void qlua::extended_api::message(const std::string& text, const message_icon i) {
  message(text.c_str(), i);
}

void qlua::extended_api::message(const std::string& text) {
  message(text.c_str(), message_icon::info);
}

void qlua::extended_api::PrintDbgStr(const std::string& s) {
  PrintDbgStr(s.c_str());
}
