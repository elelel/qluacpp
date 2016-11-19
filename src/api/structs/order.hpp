#pragma once

#include <string>

#include "datetime.hpp"

namespace qlua {
  struct order {
    unsigned int order_num;
    unsigned int flags;
    std::string brokerred;
    std::string userid;
    std::string firmid;
    std::string account;
    double price;
    double qty;
    double balance;
    double vlaue;
    double accruedint;
    double yield;
    unsigned int trans_id;
    std::string client_code;
    double price2;
    std::string settlecode;
    unsigned int uid;
    std::string exchange_code;
    double activation_time;
    unsigned int linkedorder;
    double expiry;
    std::string sec_code;
    std::string class_code;
    ::qlua::datetime datetime;
    std::string bank_acc_id;
    unsigned int value_entry_type;
    unsigned int repoterm;
    double repovalue;
    double repo2value;
    double repo_value_balance;
    double start_discount;
    std::string reject_reason;
    unsigned int ext_order_flags;
    double min_qty;
    unsigned int exec_type;
    unsigned int acnt_type;
    double capacity;
    unsigned int passive_only_order;
    double visible;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::order> {
    inline static qlua::order read(lua::state& l, int idx = -1) {
      qlua::order r;
      
      l.get_field_into("order_num", r.order_num);
      l.get_field_into("flags", r.flags);
      l.get_field_into("brokerred", r.brokerred);
      l.get_field_into("userid", r.userid);
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("account", r.account);
      l.get_field_into("price", r.price);
      l.get_field_into("qty", r.qty);
      l.get_field_into("balance", r.balance);
      l.get_field_into("vlaue", r.vlaue);
      l.get_field_into("accruedint", r.accruedint);
      l.get_field_into("yield", r.yield);
      l.get_field_into("trans_id", r.trans_id);
      l.get_field_into("client_code", r.client_code);
      l.get_field_into("price2", r.price2);
      l.get_field_into("settlecode", r.settlecode);
      l.get_field_into("uid", r.uid);
      l.get_field_into("exchange_code", r.exchange_code);
      l.get_field_into("activation_time", r.activation_time);
      l.get_field_into("linkedorder", r.linkedorder);
      l.get_field_into("expiry", r.expiry);
      l.get_field_into("sec_code", r.sec_code);
      l.get_field_into("class_code", r.class_code);
      l.get_field_into("datetime", r.datetime);
      l.get_field_into("bank_acc_id", r.bank_acc_id);
      l.get_field_into("value_entry_type", r.value_entry_type);
      l.get_field_into("repoterm", r.repoterm);
      l.get_field_into("repovalue", r.repovalue);
      l.get_field_into("repo2value", r.repo2value);
      l.get_field_into("repo_value_balance", r.repo_value_balance);
      l.get_field_into("start_discount", r.start_discount);
      l.get_field_into("reject_reason", r.reject_reason);
      l.get_field_into("ext_order_flags", r.ext_order_flags);
      l.get_field_into("min_qty", r.min_qty);
      l.get_field_into("exec_type", r.exec_type);
      l.get_field_into("acnt_type", r.acnt_type);
      l.get_field_into("capacity", r.capacity);
      l.get_field_into("passive_only_order", r.passive_only_order);
      l.get_field_into("visible", r.visible);

      return r;
    }
  };
}
