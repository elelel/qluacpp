#pragma once

#include "../api/api.hpp"
#include "../api/table/order.hpp"

namespace qlua {
  namespace table {

    template <typename row_t>
    struct table_reader {
      table_reader(const api& q) :
        q_(q) {
      }
        
      std::vector<row_t> read() {
        std::vector<row_t> rslt;
        int sz = q.getNumberOf(table_name);
        rslt.reserve(sz);
        for (int i = 0; i < sz; ++i) {
          rslt.push_back(q.getItem<row_t>(table_name<row_t>(), i));
        }
        return rslt;
      }

      template <row_t>
      static const char* table_name();

      static const char*& table_name<row::order> {
        static const char* n = "orders";
        return n;
      }
    private:
      const qlua::api q_;
    };
  }
}
