#pragma once

namespace qlua {
  struct account_position {
    std::string firmid;
    std::string curcode;
    std::string tag;
    std::string description;
    double openbal;
    double currentpos;
    double plannedpos;
    double limit1;
    double limit2;
    double orderbuy;
    double ordersell;
    double netto;
    double plannedbal;
    double debit;
    double credit;
    std::string bank_acc_id;
    double margincall;
    double settlebal;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::account_position> {
    inline static qlua::account_position read(lua::state& l, int idx = -1) {
      qlua::account_position r;
      
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("curcode", r.curcode);
      l.get_field_into("tag", r.tag);
      l.get_field_into("description", r.description);
      l.get_field_into("openbal", r.openbal);
      l.get_field_into("currentpos", r.currentpos);
      l.get_field_into("plannedpos", r.plannedpos);
      l.get_field_into("limit1", r.limit1);
      l.get_field_into("limit2", r.limit2);
      l.get_field_into("orderbuy", r.orderbuy);
      l.get_field_into("ordersell", r.ordersell);
      l.get_field_into("netto", r.netto);
      l.get_field_into("plannedbal", r.plannedbal);
      l.get_field_into("debit", r.debit);
      l.get_field_into("credit", r.credit);
      l.get_field_into("bank_acc_id", r.bank_acc_id);
      l.get_field_into("margincall", r.margincall);
      l.get_field_into("settlebal", r.settlebal);
      
      return r;
    }
  };
}
