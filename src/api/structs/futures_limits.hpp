#pragma once

#include <luacpp>

namespace qlua {
  struct futures_limits {
    std::string firmid;
    std::string trdaccid;
    int limit_kind;
    double liquidity_coef;
    double cbp_prev_limit;
    double cbplimit;
    double cbplplanned;
    double varmargin;
    double accruedint;
    double cbplused_for_order;
    double cbplused_for_positions;
    double options_premium;
    double ts_commission;
    double kgo;
    std::string currcode;
    double real_varmargin;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::futures_limits> {
    inline static qlua::futures_limits read(const lua::state& l, int idx = -1) {
      qlua::futures_limits r;
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("trdaccid", r.trdaccid);
      l.get_field_into("limit_kind", r.limit_kind);
      l.get_field_into("liquidity_coef", r.liquidity_coef);
      l.get_field_into("cbp_prev_limit", r.cbp_prev_limit);
      l.get_field_into("cbplimit", r.cbplimit);
      l.get_field_into("cbplplanned", r.cbplplanned);
      l.get_field_into("varmargin", r.varmargin);
      l.get_field_into("accruedint", r.accruedint);
      l.get_field_into("cbplused_for_order", r.cbplused_for_order);
      l.get_field_into("cbplused_for_positions", r.cbplused_for_positions);
      l.get_field_into("options_premium", r.options_premium);
      l.get_field_into("ts_commission", r.ts_commission);
      l.get_field_into("kgo", r.kgo);
      l.get_field_into("currcode", r.currcode);
      l.get_field_into("real_varmargin", r.real_varmargin);
      return r;
    }    
  };
}
