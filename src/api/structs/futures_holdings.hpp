#pragma once

namespace qlua {
  struct futures_holdings {
    std::string firmid;
    std::string trdaccid;
    std::string sec_code;
    unsigned int type;
    double startbuy;
    double startsell;
    double startnet;
    double todaybuy;
    double todaysell;
    double totalnet;
    double openbuys;
    double opensells;
    double cbplused;
    double cbplplanned;
    double varmargin;
    double avrposnprice;
    double positionvalue;
    double real_varmargin;
    double total_varmargin;
    unsigned int session_status;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::futures_holdings> {
    inline static qlua::futures_holdings read(const lua::state& l, int idx = -1) {
      qlua::futures_holdings r;
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("trdaccid", r.trdaccid);
      l.get_field_into("sec_code", r.sec_code);
      l.get_field_into("type", r.type);
      l.get_field_into("startbuy", r.startbuy);
      l.get_field_into("startsell", r.startsell);
      l.get_field_into("startnet", r.startnet);
      l.get_field_into("todaybuy", r.todaybuy);
      l.get_field_into("todaysell", r.todaysell);
      l.get_field_into("totalnet", r.totalnet);
      l.get_field_into("openbuys", r.openbuys);
      l.get_field_into("opensells", r.opensells);
      l.get_field_into("cbplused", r.cbplused);
      l.get_field_into("cbplplanned", r.cbplplanned);
      l.get_field_into("varmargin", r.varmargin);
      l.get_field_into("avrposnprice", r.avrposnprice);
      l.get_field_into("positionvalue", r.positionvalue);
      l.get_field_into("real_varmargin", r.real_varmargin);
      l.get_field_into("total_varmargin", r.total_varmargin);
      l.get_field_into("session_status", r.session_status);
      return r;
    }
  };
}
