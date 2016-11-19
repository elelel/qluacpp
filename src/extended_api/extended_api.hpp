#pragma once

#include "../api/api.hpp"

#include "structs/classcode.hpp"

namespace qlua {
  struct extended_api : public api {
    extended_api(lua::state& l) :
      api(l) {
    }
    
    // Service
    using api::getInfoParam;
    const char* getInfoParam(const std::string& param_name);

    using api::message;
    enum class message_icon {
      info = 1,
      exclamation,
      error
    };
    void message(const char* text, const message_icon i);
    void message(const std::string& text, const message_icon i);
    void message(const std::string& text);
    using api::PrintDbgStr;
    void PrintDbgStr(const std::string& s);

    // Instrument info (so called "parameters")
    using api::getClassesList;
    void getClassesList(std::vector<std::string>& classes_list);
    using api::getClassSecurities;
    void getClassSecurities(const char* class_name, std::vector<std::string>& class_securities);

    // Workplace
    using api::getQuoteLevel2;
    template <typename class_code_t>
    quote_level_2 getQuoteLevel2(const char* sec_code) {
      return getQuoteLevel2(class_code_t::name().c_str(), sec_code);
    }

    template <typename class_code_t, typename param_t>
    void ParamRequest(const char* sec_code) {
      auto rslt = ParamRequest(class_code_t::name().c_str(), sec_code, param_t::name().c_str());
      if (!rslt) {
        throw error::ParamRequest_failed();
      }
    }
  };
}
