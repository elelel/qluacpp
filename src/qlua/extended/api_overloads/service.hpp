#pragma once

const char* getInfoParam(const std::string& param_name) const { return api::getInfoParam(param_name.c_str()); }
const char* getInfoParam(const char* param_name) const { return api::getInfoParam(param_name); }
unsigned int message(const std::string& text, const unsigned int icon_type) const { return api::message(text.c_str(), icon_type); }
unsigned int message(const char* text, const unsigned int icon_type) const { return api::message(text, icon_type); }
unsigned int message(const std::string& text) const { return api::message(text.c_str()); }
unsigned int message(const char* text) const { return api::message(text); }
void PrintDbgStr(const std::string& s) const { api::PrintDbgStr(s.c_str()); }
void PrintDbgStr(const char* s) const { api::PrintDbgStr(s); }

