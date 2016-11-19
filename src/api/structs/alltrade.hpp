#pragma once

#include <string>

#include <luacpp>

#include "datetime.hpp"

namespace qlua {
  struct alltrade {
    typedef alltrade type;
    alltrade();

    alltrade(const type& other);
    alltrade(type&& other);
    void swap(type& other);
    type& operator=(const type& other);

    bool is_sell() const;
    bool is_buy() const;
    
    int trade_num{0};
    unsigned int flags{0};
    double price{0.0};
    unsigned int qty{0};
    double value{0.0};
    double accruedint{0.0};
    double yield{0.0};
    std::string settlecode;
    double reporate{0};
    double repovalue{0};
    double repo2value{0};
    unsigned int repoterm{0};
    std::string sec_code;
    std::string class_code;
    ::qlua::datetime datetime;
    unsigned int period{0};
    double open_interest{0.0};
    std::string exchange_code;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::alltrade> {
    inline static qlua::alltrade read(lua::state& l, int idx = -1) {
      qlua::alltrade r;
    
      l.get_field_into("trade_num", r.trade_num);
      l.get_field_into("flags", r.flags);
      l.get_field_into("price", r.price);
      l.get_field_into("qty", r.qty);
      l.get_field_into("value", r.value);
      l.get_field_into("accruedint", r.accruedint);
      l.get_field_into("yield", r.yield);
      l.get_field_into("settlecode", r.settlecode);
      l.get_field_into("reporate", r.reporate);
      l.get_field_into("repovalue", r.repovalue);
      l.get_field_into("repo2value", r.repo2value);
      l.get_field_into("repoterm", r.repoterm);
      l.get_field_into("sec_code", r.sec_code);
      l.get_field_into("class_code", r.class_code);

      l.get_field_into("period", r.period);
      l.get_field_into("open_interest", r.open_interest);
      l.get_field_into("exchange_code", r.exchange_code);

      l.get_field_into("datetime", r.datetime); 
      return r;
    }
  };

}

