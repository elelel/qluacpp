#pragma once

unsigned int AddColumn(const unsigned int t_id,
                       const unsigned int iCode,
                       const std::string& name,
                       const bool is_default,
                       const unsigned int par_type,
                       const unsigned int width) const {
  return api::AddColumn(t_id, iCode, name.c_str(), is_default, par_type, width);
}

unsigned int AddColumn(const unsigned int t_id,
                       const unsigned int iCode,
                       const char* name,
                       const bool is_default,
                       const unsigned int par_type,
                       const unsigned int width) const {
  return api::AddColumn(t_id, iCode, name, is_default, par_type, width);
}

bool SetCell(const unsigned int t_id,
             const unsigned int key,
             const unsigned int code,
             const std::string& text) {
  return api::SetCell(t_id, key, code, text.c_str());
}


bool SetCell(const unsigned int t_id,
             const unsigned int key,
             const unsigned int code,
             const char* text) const {
  return api::SetCell(t_id, key, code, text);
}

bool SetCell(const unsigned int t_id,
             const unsigned int key,
             const unsigned int code,
             const std::string& text,
             const double value) const {
  return api::SetCell(t_id, key, code, text.c_str(), value);
}


bool SetCell(const unsigned int t_id,
             const unsigned int key,
             const unsigned int code,
             const char* text,
             const double value) const {
  return api::SetCell(t_id, key, code, text, value);
}

bool SetWindowCaption(const unsigned int t_id,
                      const std::string& str) const {
  return api::SetWindowCaption(t_id, str.c_str());
}

bool SetWindowCaption(const unsigned int t_id,
                      const char* str) const {
  return api::SetWindowCaption(t_id, str);
}

