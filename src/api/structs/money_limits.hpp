#pragma once

#include <luacpp>

namespace qlua {
  struct money_limits {
    double money_open_limit{0.0};
    double money_limit_locked_nonmarginal_value{0.0};
    double money_limit_locked{0.0};
    double money_open_balance{0.0};
    double money_current_limit{0.0};
    double money_current_balance{0.0};
    double money_limit_available{0.0};
  };
  
}

namespace lua {
  template <>
  struct stack_reader<qlua::money_limits> {
    inline static qlua::money_limits read(lua::state& l, int idx = -1) {
      qlua::money_limits r;
      l.get_field_into("money_open_limit", r.money_open_limit);
      l.get_field_into("money_limit_locked_nonmarginal_value", r.money_limit_locked_nonmarginal_value);

      l.get_field_into("money_limit_locked", r.money_limit_locked);
      l.get_field_into("money_open_balance", r.money_open_balance);
      l.get_field_into("money_current_limit", r.money_current_limit);
      l.get_field_into("money_current_balance", r.money_current_balance);
      l.get_field_into("money_limit_available", r.money_limit_available);
      return r;
    }
  };
}
