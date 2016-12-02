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

  struct money_limits_table_row {
    std::string currcode;
    std::string tag;
    std::string firmid;
    std::string client_code;
    double openbal;
    double openlimit;
    double currentbal;
    double currentlim;
    double locked;
    double locked_value_coef;
    double locked_margin_value;
    double leverage;
    int limit_kind;
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

  template <>
  struct stack_reader<qlua::money_limits_table_row> {
    inline static qlua::money_limits_table_row read(lua::state& l, int idx = -1) {
      qlua::money_limits_table_row r;
      l.get_field_into("currcode", r.currcode);
      l.get_field_into("tag", r.tag);
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("client_code", r.client_code);
      l.get_field_into("openbal", r.openbal);
      l.get_field_into("openlimit", r.openlimit);
      l.get_field_into("currentbal", r.currentbal);
      l.get_field_into("currentlim", r.currentlim);
      l.get_field_into("locked", r.locked);
      l.get_field_into("locked_value_coef", r.locked_value_coef);
      l.get_field_into("locked_margin_value", r.locked_margin_value);
      l.get_field_into("leverage", r.leverage);
      l.get_field_into("limit_kind", r.limit_kind);
      return r;
    }
  };
}
