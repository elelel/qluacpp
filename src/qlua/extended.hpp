#pragma once

#include "api.hpp"

#include <string>

namespace qlua {
  struct extended : api {
    using api::api;

    void swap(type& other) {
      api::swap(other);
    }
    
    type& operator=(const type& other) {
      return api::operator=(other);
    }

    template <typename Constant>
    Constant constant(const std::string& name) const {
      return api::constant<Constant>(name.c_str());
    }

    // Convinience overloads, mostly for std::string in arguments
    #include "extended/api_overloads/service.hpp"
    #include "extended/api_overloads/table_data.hpp"
    #include "extended/api_overloads/table.hpp"
    #include "extended/api_overloads/securities.hpp"
    #include "extended/api_overloads/workplace.hpp"

  };
}
