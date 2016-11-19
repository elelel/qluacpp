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

  struct depo_limits_table_row {
    std::string sec_code;
    std::string trdaccid;
    std::string firmid;
    std::string client_code;
    double openbal;
    double currentbal;
    double openlimit;
    double currentlimit;
    double locked_sell;
    double locked_buy;
    double locked_buy_value;
    double locked_sell_value;
    double awg_position_price;
    int limit_kind;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::depo_limits> {
    inline static qlua::depo_limits read(lua::state& l, int idx = -1) {
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

  template <>
  struct stack_reader<qlua::depo_limits_table_row> {
    inline static qlua::depo_limits_table_row read(lua::state& l, int idx = -1){
      qlua::depo_limits_table_row r;
      l.get_field_into("sec_code", r.sec_code);
      l.get_field_into("trdaccid", r.trdaccid);
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("client_code", r.client_code);
      l.get_field_into("openbal", r.openbal);
      l.get_field_into("currentbal", r.currentbal);
      l.get_field_into("openlimit", r.openlimit);
      l.get_field_into("currentlimit", r.currentlimit);
      l.get_field_into("locked_sell", r.locked_sell);
      l.get_field_into("locked_buy", r.locked_buy);
      l.get_field_into("locked_buy_value", r.locked_buy_value);
      l.get_field_into("locked_sell_value", r.locked_sell_value);
      l.get_field_into("awg_position_price", r.awg_position_price);
      l.get_field_into("limit_kind", r.limit_kind);
      return r;
    }
  };
}
