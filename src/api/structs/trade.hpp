#pragma once

#include <string>

#include <luacpp>

#include "datetime.hpp"

namespace qlua {
  struct trade {
    typedef trade type;
    /*    trade();

    trade(const type& other);
    trade(type&& other);
    void swap(type& other);
    type& operator=(const type& other); 

    bool is_sell() const;
    bool is_buy() const; */
    
    int trade_num{0};
    int order_num{0};
    std::string brokerref;
    std::string userid;
    std::string firmid;
    int canceled_uid;
    std::string account;
    double price{0.0};
    unsigned int qty{0};
    double value{0.0};
    double accruedint{0.0};
    double yield{0.0};
    std::string settlecode;
    std::string cpfirmid;
    int flags;
    double price2;
    double reporate;
    std::string client_code;
    double accrued2;
    unsigned int repoterm{0};
    double repovalue{0};
    double repo2value{0};
    double start_discount{0};
    double lower_discount{0};
    double upper_dicount{0};
    int block_securities{0};
    double clearing_comission{0};
    double exchange_comission{0};
    double tech_center_comission{0};
    int settle_date{0};
    std::string settle_currency;
    std::string trade_currency;
    std::string exchange_code;
    std::string station_id;
    std::string sec_code;
    std::string class_code;
    ::qlua::datetime datetime;
    std::string bank_acc_id;
    double broker_comission{0.0};
    unsigned int linked_trade{0};
    unsigned int period{0};
    unsigned int trans_id{0};
    unsigned int kind{0};
    std::string clearing_bank_accid;
    ::qlua::datetime canceled_datetime;
    std::string clearing_firmid;
    std::string system_ref;
    unsigned int uid{0};
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::trade> {
    inline static qlua::trade read(const lua::state& l, int idx = -1) {
      qlua::trade r;
    
      l.get_field_into("trade_num", r.trade_num);
      l.get_field_into("order_num", r.order_num);
      l.get_field_into("brokerref", r.brokerref);
      l.get_field_into("userid", r.userid);
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("canceled_uid", r.canceled_uid);
      l.get_field_into("account", r.account);
      l.get_field_into("price", r.price);
      l.get_field_into("qty", r.qty);
      l.get_field_into("value", r.value);
      l.get_field_into("accruedint", r.accruedint);
      l.get_field_into("yield", r.yield);
      l.get_field_into("settlecode", r.settlecode);
      l.get_field_into("cpfirmid", r.cpfirmid);
      l.get_field_into("flags", r.flags);
      l.get_field_into("price2", r.price2);
      l.get_field_into("reporate", r.reporate);
      l.get_field_into("client_code", r.client_code);
      l.get_field_into("accrued2", r.accrued2);
      l.get_field_into("repoterm", r.repoterm);
      l.get_field_into("repovalue", r.repovalue);
      l.get_field_into("repo2value", r.repo2value);
      l.get_field_into("start_discount", r.start_discount);
      l.get_field_into("lower_discount", r.lower_discount);
      l.get_field_into("upper_dicount", r.upper_dicount);
      l.get_field_into("block_securities", r.block_securities);
      l.get_field_into("clearing_comission", r.clearing_comission);
      l.get_field_into("exchange_comission", r.exchange_comission);
      l.get_field_into("tech_center_comission", r.tech_center_comission);
      l.get_field_into("settle_date", r.settle_date);
      l.get_field_into("settle_currency", r.settle_currency);
      l.get_field_into("trade_currency", r.trade_currency);
      l.get_field_into("exchange_code", r.exchange_code);
      l.get_field_into("station_id", r.station_id);
      l.get_field_into("sec_code", r.sec_code);
      l.get_field_into("class_code", r.class_code);
      l.get_field_into("datetime", r.datetime);
      l.get_field_into("bank_acc_id", r.bank_acc_id);
      l.get_field_into("broker_comission", r.broker_comission);
      l.get_field_into("linked_trade", r.linked_trade);
      l.get_field_into("period", r.period);
      l.get_field_into("trans_id", r.trans_id);
      l.get_field_into("kind", r.kind);
      l.get_field_into("clearing_bank_accid", r.clearing_bank_accid);
      l.get_field_into("canceled_datetime", r.canceled_datetime);
      l.get_field_into("clearing_firmid", r.clearing_firmid);
      l.get_field_into("system_ref", r.system_ref);
      l.get_field_into("uid", r.uid);

      
      return r;
    }
  };

}

