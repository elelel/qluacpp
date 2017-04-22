#pragma once

/*
 QLUA tables structures
 */
#include <string>

#include <luacpp/luacpp>

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
    // all_trades "Обезличенные сделки"
    // account_positions "Денежные позиции"
    // orders "Заявки"
    // futures_client_holding "Позиции по клиентским счетам (фьючерсы)"
    // futures_client_limits "Лимиты по фьючерсам"
    // money_limits "Лимиты по денежным средствам"
    // depo_limits "Лимиты по бумагам"
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
