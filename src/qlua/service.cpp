#include "qlua.hpp"

#include <string>

namespace qlua {
  unsigned int api::isConnected() const {
    const char api_name[] = "isConnected";
    typedef std::tuple<unsigned int> return_type;
    auto rslt = l_.pcall<return_type>(api_name, std::tuple<>{});
    return std::get<0>(rslt) == 1;
  }

  const char* api::getScriptPath() const {
    const char api_name[] = "getScriptPath";
    typedef std::tuple<const char*> return_type;
    auto rslt = l_.pcall<return_type>(api_name, std::tuple<>{});
    return std::get<0>(rslt);
  }

  const char* api::getInfoParam(const char* param_name) const {
    const char api_name[] = "getInfoParam";
    typedef std::tuple<const char*> return_type;
    auto params = std::make_tuple(param_name);
    auto result = l_.pcall<return_type>(api_name, params);
    return std::get<0>(result);
  }

  void api::message(const char* text, const unsigned int icon) const {
    const char api_name[] = "message";
    typedef std::tuple<int> return_type;
    auto params = std::make_tuple(text, icon);
    l_.pcall<return_type>(api_name, params);
  }

  void api::message(const char* text) const {
    message(text, 1);
  }

  void api::sleep(int ms) const {
    const char api_name[] = "sleep";
    typedef std::tuple<int> return_type;
    auto params = std::make_tuple(ms);
    auto result = l_.pcall<return_type>(api_name, params);
    if (std::get<0>(result) != ms) {
      throw std::runtime_error("QLUA API failed: sleep(" + std::to_string(ms) + ") returned " + std::to_string(std::get<0>(result)));
    }
  }

  const char* api::getWorkingFolder() const {
    const char api_name[] = "getWorkingFolder";
    typedef std::tuple<const char*> return_type;
    auto result = l_.pcall<return_type>(api_name, std::tuple<>());
    return std::get<0>(result);
  }

  void api::PrintDbgStr(const char* s) const {
    const char api_name[] = "PrintDbgStr";
    typedef std::tuple<> return_type;
    auto params = std::make_tuple(s);
    l_.pcall<return_type>(api_name, params);
  }
  
}
