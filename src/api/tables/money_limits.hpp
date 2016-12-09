#pragma once

namespace qlua {
  namespace table {
    namespace row {
      struct money_limits {
        std::string currcode;
        std::string tag;
        std::string firmid;
        std::string client_code;
        double openbal;
        double openlimit;
        double currentbal;
        double currentlimit;
        double locked;
        double locked_value_coef;
        double locked_margin_value;
        double leverage;
        int limit_kind;
      };
    }
  }
}

namespace lua {
  template <>
  struct stack_reader<qlua::table::row::money_limits> {
    inline static qlua::table::row::money_limits read(const lua::state& l, int idx = -1) {
      qlua::table::row::money_limits r;
      l.get_field_into("currcode", r.currcode);
      l.get_field_into("tag", r.tag);
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("client_code", r.client_code);
      l.get_field_into("openbal", r.openbal);
      l.get_field_into("openlimit", r.openlimit);
      l.get_field_into("currentbal", r.currentbal);
      l.get_field_into("currentlimit", r.currentlimit);
      l.get_field_into("locked", r.locked);
      l.get_field_into("locked_value_coef", r.locked_value_coef);
      l.get_field_into("locked_margin_value", r.locked_margin_value);
      l.get_field_into("leverage", r.leverage);
      l.get_field_into("limit_kind", r.limit_kind);
      return r;
    }
  };
}
