#pragma once

#include <map>

namespace qlua {
  //  Map of parameter/value pairs, see info.chm "Формат .tri-файла с параметрами транзакций" 
  typedef std::map<std::string, std::string> transaction_import;

  struct transaction_reply {
    unsigned int trans_id;
    unsigned int status;
    std::string result_msg;
    unsigned int time;
    unsigned int uid;
    unsigned int flags;
    unsigned int server_trans_id;
    unsigned int order_num{0};
    double price{0.0};
    double quantity{0.0};
    double balance{0.0};
    std::string firm_id;
    std::string account;
    std::string client_code;
    std::string brokerref;
    std::string class_code;
    std::string sec_code;
    std::string exchange_code;
  };
}

namespace lua {
  template <>
  struct stack_pusher<qlua::transaction_import> {
    inline static void push(lua::state& l, const qlua::transaction_import& tri) {
      l.createtable(0, tri.size());
      for (const auto& r : tri) {
        l.pushstring(r.second.c_str());
        l.setfield(-2, r.first.c_str());
      }
    }

    const std::string name = "stack_pusher<qlua::transaction_import>";
  };

  template <>
  struct stack_reader<qlua::transaction_reply> {
    inline static qlua::transaction_reply read(lua::state& l, int idx = -1) {
      qlua::transaction_reply r;
      l.get_field_into("trans_id", r.trans_id);
      l.get_field_into("status", r.status);
      l.get_field_into("result_msg", r.result_msg);
      l.get_field_into("time", r.time);
      l.get_field_into("uid", r.uid);
      l.get_field_into("flags", r.flags);
      l.get_field_into("server_trans_id", r.server_trans_id);
      l.get_field_into("order_num", r.order_num);

      l.getfield(-1, "price");
      if (!l.isnil()) l.get_value_into(r.price, -1);
      l.pop(1);

      l.getfield("quantity");
      if (!l.isnil()) l.get_value_into(r.quantity, -1);
      l.pop(1);

      l.getfield("balance");
      if (!l.isnil()) l.get_value_into(r.balance, -1);
      l.pop(1);

      l.getfield("firm_id");
      if (!l.isnil()) l.get_value_into(r.firm_id, -1);
      l.pop(1);

      l.getfield("account");
      if (!l.isnil()) l.get_value_into(r.account, -1);
      l.pop(1);

      l.getfield("client_code");
      if (!l.isnil()) l.get_value_into(r.client_code, -1);
      l.pop(1);

      l.getfield("brokerref");
      if (!l.isnil()) l.get_value_into(r.brokerref, -1);
      l.pop(1);

      l.getfield("class_code");
      if (!l.isnil()) l.get_value_into(r.class_code, -1);
      l.pop(1);

      l.getfield("sec_code");
      if (!l.isnil()) l.get_value_into(r.sec_code, -1);
      l.pop(1);

      l.getfield("exchange_code");
      if (!l.isnil()) l.get_value_into(r.exchange_code, -1);
      l.pop(1);
      return r;
    }

    const std::string name = "stack_reader<qlua::transaction_reply>";
  };
}
