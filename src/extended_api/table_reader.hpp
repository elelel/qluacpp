#pragma once

#include "../api/api.hpp"

namespace qlua {
  namespace table {

    template <typename row_t>
    struct name;

    template <>
    struct name<row::orders> {
      static const char*& get() {
        static const char* n = "orders";
        return n;
      }
    };

    template <>
    struct name<row::depo_limits> {
      static const char*& get() {
        static const char* n = "depo_limits";
        return n;
      }
    };

    template <>
    struct name<row::money_limits> {
      static const char*& get() {
        static const char* n = "money_limits";
        return n;
      }
    };
    
    template <typename row_t>
    struct reader {
      reader(const api& q) :
        q_(q) {
      }
        
      std::vector<row_t> read() const {
        std::vector<row_t> rslt;
        int sz = q_.getNumberOf(name<row_t>::get());
        rslt.reserve(sz);
        for (int i = 0; i < sz; ++i) {
          auto r = q_.getItem<row_t>(name<row_t>::get(), i);
          rslt.push_back(r);
        }
        return rslt;
      }

    private:
      const qlua::api q_;
    };
  }
}
