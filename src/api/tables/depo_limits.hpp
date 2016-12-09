#pragma once

namespace qlua {
  namespace table {
    namespace row {
      struct depo_limits {
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
  }
}

namespace lua {
  template <>
  struct stack_reader<qlua::table::row::depo_limits> {
    inline static qlua::table::row::depo_limits read(const lua::state& l, int idx = -1) {
      qlua::table::row::depo_limits r;
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
