#pragma once

namespace qlua {
  struct account_balance {
    std::string firmid;
    std::string sec_code;
    std::string trdaccid;
    std::string depaccid;
    double openbal;
    double currentpos;
    double plannedpossell;
    double plannedposbuy;
    double planbal;
    double usqtyb;
    double usqtys;
    double planned;
    double settlebal;
    std::string bank_acc_id;
    int firmuse;
  };  
}

namespace lua {
  template <>
  struct stack_reader<qlua::account_balance> {
    inline static qlua::account_balance read(lua::state& l, int idx = -1) {
      qlua::account_balance r;
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("sec_code", r.sec_code);
      l.get_field_into("trdaccid", r.trdaccid);
      l.get_field_into("depaccid", r.depaccid);
      l.get_field_into("openbal", r.openbal);
      l.get_field_into("currentpos", r.currentpos);
      l.get_field_into("plannedpossell", r.plannedpossell);
      l.get_field_into("plannedposbuy", r.plannedposbuy);
      l.get_field_into("planbal", r.planbal);
      l.get_field_into("usqtyb", r.usqtyb);
      l.get_field_into("usqtys", r.usqtys);
      l.get_field_into("planned", r.planned);
      l.get_field_into("settlebal", r.settlebal);
      l.get_field_into("bank_acc_id", r.bank_acc_id);
      l.get_field_into("firmuse", r.firmuse);
      return r;
    }
  };
}
