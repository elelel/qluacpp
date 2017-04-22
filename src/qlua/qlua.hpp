#pragma once

#include <luacpp/luacpp>

#include "tables.hpp"

namespace qlua {
  struct api {
    typedef api type;
    api(const lua::state& l);
    api(const type& other);
    api(type&& other);
    void swap(type& other);
    type& operator=(const type& other);

    // Service "Сервисные функции"
    unsigned int isConnected() const;
    const char* getScriptPath() const;
    const char* getInfoParam(const char* param_name) const;
    void message(const char* text, const unsigned int icon) const;
    void message(const char* text) const;
    void sleep(const int ms) const;
    const char* getWorkingFolder() const;
    void PrintDbgStr(const char* s) const;
    
  private:
    lua::state l_;
  };
}
