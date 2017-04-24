#pragma once

/*
  QLUA tables structures
*/
#include <string>

#include <luacpp/luacpp>

#include "datatype.hpp"

namespace qlua {

  namespace table {
    // firms "Фирмы"
    LUACPP_STATIC_TABLE_BEGIN(firms)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(firm_name, std::string)
    LUACPP_TABLE_FIELD(status, int)
    LUACPP_TABLE_FIELD(exchange, std::string)
    LUACPP_STATIC_TABLE_END()

    // classes "Классы"
    LUACPP_STATIC_TABLE_BEGIN(classes)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(name, std::string)
    LUACPP_TABLE_FIELD(code, std::string)
    LUACPP_TABLE_FIELD(npas, std::string)
    LUACPP_TABLE_FIELD(nsecs, std::string)
    LUACPP_STATIC_TABLE_END()

    // securities "Инструменты" (ценные бумаги)
    LUACPP_STATIC_TABLE_BEGIN(securities)
    LUACPP_TABLE_FIELD(code, std::string)
    LUACPP_TABLE_FIELD(name, std::string)
    LUACPP_TABLE_FIELD(short_name, std::string)
    LUACPP_TABLE_FIELD(class_code, std::string)
    LUACPP_TABLE_FIELD(class_name, std::string)
    LUACPP_TABLE_FIELD(face_value, double)
    LUACPP_TABLE_FIELD(face_unit, std::string)
    LUACPP_TABLE_FIELD(scale, unsigned int)
    LUACPP_TABLE_FIELD(mat_date, unsigned int)
    LUACPP_TABLE_FIELD(lot_size, unsigned int)
    LUACPP_TABLE_FIELD(isin, std::string)
    LUACPP_TABLE_FIELD(min_price_step, double)
    LUACPP_STATIC_TABLE_END()

    // trade_accounts "Торговые счета"
    LUACPP_STATIC_TABLE_BEGIN(trade_accounts)
    LUACPP_TABLE_FIELD(class_codes, std::string)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(trdaccid, std::string)
    LUACPP_TABLE_FIELD(description, std::string)
    LUACPP_TABLE_FIELD(fullcoveredsell, unsigned int)
    LUACPP_TABLE_FIELD(main_trdaccid, unsigned int)
    LUACPP_TABLE_FIELD(bankid_t0, std::string)
    LUACPP_TABLE_FIELD(bankid_tplus, std::string)
    LUACPP_TABLE_FIELD(trdacc_type, unsigned int)
    LUACPP_TABLE_FIELD(depunitid, std::string)
    LUACPP_TABLE_FIELD(status, unsigned int)
    LUACPP_TABLE_FIELD(firmuse, unsigned int)
    LUACPP_TABLE_FIELD(depaccid, std::string)
    LUACPP_TABLE_FIELD(bank_acc_id, std::string)
    LUACPP_STATIC_TABLE_END()
    
    // client_codes "Коды клиентов"
    // TODO: (Not really a table, an array of strings)

    // all_trades "Обезличенные сделки"
    LUACPP_STATIC_TABLE_BEGIN(client_codes)
    
    LUACPP_STATIC_TABLE_END()
    
    // account_positions "Денежные позиции"
    LUACPP_STATIC_TABLE_BEGIN(account_positions)
    LUACPP_TABLE_FIELD(trade_num, int)
    LUACPP_TABLE_FIELD(flags, unsigned int)
    LUACPP_TABLE_FIELD(price, double)
    LUACPP_TABLE_FIELD(qty, unsigned int)
    LUACPP_TABLE_FIELD(value, double)
    LUACPP_TABLE_FIELD(accruedint, double)
    LUACPP_TABLE_FIELD(yield, double)
    LUACPP_TABLE_FIELD(settlecode, std::string)
    LUACPP_TABLE_FIELD(reporate, double)
    LUACPP_TABLE_FIELD(repovalue, double)
    LUACPP_TABLE_FIELD(repo2value, double)
    LUACPP_TABLE_FIELD(repoterm, unsigned int)
    LUACPP_TABLE_FIELD(sec_code, std::string)
    LUACPP_TABLE_FIELD(class_code, std::string)
    LUACPP_TABLE_FIELD(datetime, ::qlua::datatype::datetime)
    LUACPP_TABLE_FIELD(period, unsigned int)
    LUACPP_TABLE_FIELD(open_interest, double)
    LUACPP_TABLE_FIELD(exchange_code, std::string)
    LUACPP_STATIC_TABLE_END()
    
    // orders "Заявки"
    LUACPP_STATIC_TABLE_BEGIN(orders)
    LUACPP_TABLE_FIELD(order_num, unsigned int)
    LUACPP_TABLE_FIELD(flags, unsigned int)
    LUACPP_TABLE_FIELD(brokerred, std::string)
    LUACPP_TABLE_FIELD(userid, std::string)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(account, std::string)
    LUACPP_TABLE_FIELD(price, double)
    LUACPP_TABLE_FIELD(qty, double)
    LUACPP_TABLE_FIELD(balance, double)
    LUACPP_TABLE_FIELD(vlaue, double)
    LUACPP_TABLE_FIELD(accruedint, double)
    LUACPP_TABLE_FIELD(yield, double)
    LUACPP_TABLE_FIELD(trans_id, unsigned int)
    LUACPP_TABLE_FIELD(client_code, std::string)
    LUACPP_TABLE_FIELD(price2, double)
    LUACPP_TABLE_FIELD(settlecode, std::string)
    LUACPP_TABLE_FIELD(uid, unsigned int)
    LUACPP_TABLE_FIELD(exchange_code, std::string)
    LUACPP_TABLE_FIELD(activation_time, double)
    LUACPP_TABLE_FIELD(linkedorder, unsigned int)
    LUACPP_TABLE_FIELD(expiry, double)
    LUACPP_TABLE_FIELD(sec_code, std::string)
    LUACPP_TABLE_FIELD(class_code, std::string)
    LUACPP_TABLE_FIELD(datetime, ::qlua::datatype::datetime)
    LUACPP_TABLE_FIELD(bank_acc_id, std::string)
    LUACPP_TABLE_FIELD(value_entry_type, unsigned int)
    LUACPP_TABLE_FIELD(repoterm, unsigned int)
    LUACPP_TABLE_FIELD(repovalue, double)
    LUACPP_TABLE_FIELD(repo2value, double)
    LUACPP_TABLE_FIELD(repo_value_balance, double)
    LUACPP_TABLE_FIELD(start_discount, double)
    LUACPP_TABLE_FIELD(reject_reason, std::string)
    LUACPP_TABLE_FIELD(ext_order_flags, unsigned int)
    LUACPP_TABLE_FIELD(min_qty, double)
    LUACPP_TABLE_FIELD(exec_type, unsigned int)
    LUACPP_TABLE_FIELD(acnt_type, unsigned int)
    LUACPP_TABLE_FIELD(capacity, double)
    LUACPP_TABLE_FIELD(passive_only_order, unsigned int)
    LUACPP_TABLE_FIELD(visible, double)
    LUACPP_STATIC_TABLE_END()
    
    // futures_client_holding "Позиции по клиентским счетам (фьючерсы)"
    LUACPP_STATIC_TABLE_BEGIN(future_client_holding)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(trdaccid, std::string)
    LUACPP_TABLE_FIELD(sec_code, std::string)
    LUACPP_TABLE_FIELD(type, unsigned int)
    LUACPP_TABLE_FIELD(startbuy, double)
    LUACPP_TABLE_FIELD(startsell, double)
    LUACPP_TABLE_FIELD(startnet, double)
    LUACPP_TABLE_FIELD(todaybuy, double)
    LUACPP_TABLE_FIELD(todaysell, double)
    LUACPP_TABLE_FIELD(totalnet, double)
    LUACPP_TABLE_FIELD(openbuys, double)
    LUACPP_TABLE_FIELD(opensells, double)
    LUACPP_TABLE_FIELD(cbplused, double)
    LUACPP_TABLE_FIELD(cbplplanned, double)
    LUACPP_TABLE_FIELD(varmargin, double)
    LUACPP_TABLE_FIELD(avrposnprice, double)
    LUACPP_TABLE_FIELD(positionvalue, double)
    LUACPP_TABLE_FIELD(real_varmargin, double)
    LUACPP_TABLE_FIELD(total_varmargin, double)
    LUACPP_TABLE_FIELD(session_status, unsigned int)
    LUACPP_STATIC_TABLE_END()
    
    // futures_client_limits "Лимиты по фьючерсам"
    LUACPP_STATIC_TABLE_BEGIN(future_client_limits)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(trdaccid, std::string)
    LUACPP_TABLE_FIELD(limit_kind, int)
    LUACPP_TABLE_FIELD(liquidity_coef, double)
    LUACPP_TABLE_FIELD(cbp_prev_limit, double)
    LUACPP_TABLE_FIELD(cbplimit, double)
    LUACPP_TABLE_FIELD(cbplplanned, double)
    LUACPP_TABLE_FIELD(varmargin, double)
    LUACPP_TABLE_FIELD(accruedint, double)
    LUACPP_TABLE_FIELD(cbplused_for_order, double)
    LUACPP_TABLE_FIELD(cbplused_for_positions, double)
    LUACPP_TABLE_FIELD(options_premium, double)
    LUACPP_TABLE_FIELD(ts_commission, double)
    LUACPP_TABLE_FIELD(kgo, double)
    LUACPP_TABLE_FIELD(currcode, std::string)
    LUACPP_TABLE_FIELD(real_varmargin, double)
    LUACPP_STATIC_TABLE_END()
    
    // money_limits "Лимиты по денежным средствам"
    LUACPP_STATIC_TABLE_BEGIN(money_limits)
    LUACPP_TABLE_FIELD(currcode, std::string)
    LUACPP_TABLE_FIELD(tag, std::string)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(client_code, std::string)
    LUACPP_TABLE_FIELD(openbal, double)
    LUACPP_TABLE_FIELD(openlimit, double)
    LUACPP_TABLE_FIELD(currentbal, double)
    LUACPP_TABLE_FIELD(currentlimit, double)
    LUACPP_TABLE_FIELD(locked, double)
    LUACPP_TABLE_FIELD(locked_value_coef, double)
    LUACPP_TABLE_FIELD(locked_margin_value, double)
    LUACPP_TABLE_FIELD(leverage, double)
    LUACPP_TABLE_FIELD(limit_kind, int)
    LUACPP_STATIC_TABLE_END()

    
    // depo_limits "Лимиты по бумагам"
    LUACPP_STATIC_TABLE_BEGIN(depo_limits)
    LUACPP_TABLE_FIELD(sec_code, std::string)
    LUACPP_TABLE_FIELD(trdaccid, std::string)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(client_code, std::string)
    LUACPP_TABLE_FIELD(openbal, double)
    LUACPP_TABLE_FIELD(currentbal, double)
    LUACPP_TABLE_FIELD(openlimit, double)
    LUACPP_TABLE_FIELD(currentlimit, double)
    LUACPP_TABLE_FIELD(locked_sell, double)
    LUACPP_TABLE_FIELD(locked_buy, double)
    LUACPP_TABLE_FIELD(locked_buy_value, double)
    LUACPP_TABLE_FIELD(locked_sell_value, double)
    LUACPP_TABLE_FIELD(awg_position_price, double)
    LUACPP_TABLE_FIELD(limit_kind, int)
    LUACPP_STATIC_TABLE_END()
    // trades "Сделки"
    // stop_orders "Стоп-заявки"
    // neg_deals "Заявки на внебиржевые сделки"
    // neg_trades "Сделки для исполнения"
    // neg_deal_reports "Отчеты по сделкам для исполнения"
    // firm_holding "Текущие позиции по бумагам"
    // account_balance "Текущиее позиции по клиентским счетам"
    // ccp_holdings "Обязательства и требования по активам"
    // rm_holdings "Валюта: обящательства и требования по активам"
  }
}
