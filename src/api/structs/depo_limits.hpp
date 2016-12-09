#pragma once

#include <luacpp>

namespace qlua {
  // Used in getDepo/getDepoEx API
  struct depo_limits {
    double depo_limit_locked_buy_value;
    double depo_current_balance;
    double depo_limit_locked_buy;
    double depo_limit_locked;
    double depo_limit_available;
    double depo_current_limit;
    double depo_open_balance;
    double depo_open_limit;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::depo_limits> {
    inline static qlua::depo_limits read(const lua::state& l, int idx = -1) {
      qlua::depo_limits r;
      l.get_field_into("depo_limit_locked_buy_value", r.depo_limit_locked_buy_value);
      l.get_field_into("depo_current_balance", r.depo_current_balance);
      l.get_field_into("depo_limit_locked_buy", r.depo_limit_locked_buy);
      l.get_field_into("depo_limit_locked", r.depo_limit_locked);
      l.get_field_into("depo_limit_available", r.depo_limit_available);
      l.get_field_into("depo_current_limit", r.depo_current_limit);
      l.get_field_into("depo_open_balance", r.depo_open_balance);
      l.get_field_into("depo_open_limit", r.depo_open_limit);
      return r;
    }
  };

}
