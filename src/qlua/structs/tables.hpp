#pragma once

/*
  QLUA tables structures
  Список по "Таблицы, используемые в функциях «getItem», «getNumberOf» и «SearchItems»"
*/
#include <string>

#include <luacpp/luacpp>

#include "datatypes.hpp"

// firms "Фирмы"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(firms)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(firm_name, std::string)
    LUACPP_TABLE_FIELD(status, int)
    LUACPP_TABLE_FIELD(exchange, std::string)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::firms)

// classes "Классы"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(classes)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(name, std::string)
    LUACPP_TABLE_FIELD(code, std::string)
    LUACPP_TABLE_FIELD(npas, std::string)
    LUACPP_TABLE_FIELD(nsecs, std::string)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::classes)

// securities "Инструменты" (ценные бумаги)
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::securities)

// trade_accounts "Торговые счета"
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::trade_accounts)
    
// client_codes "Коды клиентов"
// TODO: (Not really a table, an array of strings)

// all_trades "Обезличенные сделки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(all_trades)
    
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::all_trades)

// account_positions "Денежные позиции"
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::account_positions)
    
// orders "Заявки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(orders)
    LUACPP_TABLE_FIELD(order_num, unsigned int)
    LUACPP_TABLE_FIELD(flags, unsigned int)
    LUACPP_TABLE_FIELD(brokerred, std::string)
    LUACPP_TABLE_FIELD(userid, std::string)
    LUACPP_TABLE_FIELD(firmid, std::string)
    LUACPP_TABLE_FIELD(account, std::string)
    LUACPP_TABLE_FIELD(price, double)
    LUACPP_TABLE_FIELD(qty, unsigned int)
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
    LUACPP_TABLE_FIELD(min_qty, unsigned int)
    LUACPP_TABLE_FIELD(exec_type, unsigned int)
    LUACPP_TABLE_FIELD(acnt_type, unsigned int)
    LUACPP_TABLE_FIELD(capacity, double)
    LUACPP_TABLE_FIELD(passive_only_order, unsigned int)
    LUACPP_TABLE_FIELD(visible, double)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::orders)
    
// futures_client_holding "Позиции по клиентским счетам (фьючерсы)"
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::future_client_holding)
    
// futures_client_limits "Лимиты по фьючерсам"
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::future_client_limits)
    
// money_limits "Лимиты по денежным средствам"
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::money_limits)

// depo_limits "Лимиты по бумагам"
namespace qlua {
  namespace table {
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
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::depo_limits)

// trades "Сделки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(trades)
    LUACPP_TABLE_FIELD(trade_num, unsigned int) // Номер сделки в торговой системе 
    LUACPP_TABLE_FIELD(order_num, unsigned int) // Номер заявки в торговой системе  
    LUACPP_TABLE_FIELD(brokerref, std::string) // Комментарий, обычно: <код клиента>/<номер поручения>  
    LUACPP_TABLE_FIELD(userid, std::string) // Идентификатор трейдера  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор дилера  
    LUACPP_TABLE_FIELD(canceled_uid, unsigned int) // Идентификатор пользователя, отказавшегося от сделки  
    LUACPP_TABLE_FIELD(account, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество бумаг в последней сделке в лотах  
    LUACPP_TABLE_FIELD(value, double) // Объем в денежных средствах  
    LUACPP_TABLE_FIELD(accruedint, double) // Накопленный купонный доход  
    LUACPP_TABLE_FIELD(yield, double) // Доходность  
    LUACPP_TABLE_FIELD(settlecode, std::string) // Код расчетов  
    LUACPP_TABLE_FIELD(cpfirmid, std::string) // Код фирмы партнера  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(price2, double) // Цена выкупа  
    LUACPP_TABLE_FIELD(reporate, double) // Ставка РЕПО (%)  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(accrued2, double) // Доход (%) на дату выкупа  
    LUACPP_TABLE_FIELD(repoterm, double) // Срок РЕПО, в календарных днях  
    LUACPP_TABLE_FIELD(repovalue, double) // Сумма РЕПО  
    LUACPP_TABLE_FIELD(repo2value, double) // Объем выкупа РЕПО  
    LUACPP_TABLE_FIELD(start_discount, double) // Начальный дисконт (%)  
    LUACPP_TABLE_FIELD(lower_discount, double) // Нижний дисконт (%)  
    LUACPP_TABLE_FIELD(upper_discount, double) // Верхний дисконт (%)  
    LUACPP_TABLE_FIELD(block_securities, unsigned int) // Блокировка обеспечения («Да»/«Нет»)  
    LUACPP_TABLE_FIELD(clearing_comission, double) // Клиринговая комиссия (ММВБ)  
    LUACPP_TABLE_FIELD(exchange_comission, double) // Комиссия Фондовой биржи (ММВБ)  
    LUACPP_TABLE_FIELD(tech_center_comission, double) // Комиссия Технического центра (ММВБ)  
    LUACPP_TABLE_FIELD(settle_date, int) // Дата расчетов  
    LUACPP_TABLE_FIELD(settle_currency, std::string) // Валюта расчетов  
    LUACPP_TABLE_FIELD(trade_currency, std::string) // Валюта  
    LUACPP_TABLE_FIELD(exchange_code, std::string) // Код биржи в торговой системе  
    LUACPP_TABLE_FIELD(station_id, std::string) // Идентификатор рабочей станции  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги заявки  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса  
    LUACPP_TABLE_FIELD(datetime, ::qlua::datatype::datetime) // Дата и время  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(broker_comission, double) // Комиссия брокера. Отображается с точностью до 2 двух знаков. Поле зарезервировано для будущего использования.  
    LUACPP_TABLE_FIELD(linked_trade, unsigned int) // Номер витринной сделки в Торговой Системе для сделок РЕПО с ЦК и SWAP  
    LUACPP_TABLE_FIELD(period, unsigned int) /* Период торговой сессии. Возможные значения: 
                                                «0» – Открытие; 
                                                «1» – Нормальный; 
                                                «2» – Закрытие 

                                                LUACPP_TABLE_FIELD(trans_id, NUMBER) // Идентификатор транзакции 
                                                LUACPP_TABLE_FIELD(kind, NUMBER) /* Тип сделки. Возможные значения:
                                                «1» – Обычная; 
                                                «2» – Адресная; 
                                                «3» – Первичное размещение; 
                                                «4» – Перевод денег/бумаг; 
                                                «5» – Адресная сделка первой части РЕПО; 
                                                «6» – Расчетная по операции своп; 
                                                «7» – Расчетная по внебиржевой операции своп; 
                                                «8» – Расчетная сделка бивалютной корзины; 
                                                «9» – Расчетная внебиржевая сделка бивалютной корзины; 
                                                «10» – Сделка по операции РЕПО с ЦК; 
                                                «11» – Первая часть сделки по операции РЕПО с ЦК; 
                                                «12» – Вторая часть сделки по операции РЕПО с ЦК; 
                                                «13» – Адресная сделка по операции РЕПО с ЦК; 
                                                «14» – Первая часть адресной сделки по операции РЕПО с ЦК; 
                                                «15» – Вторая часть адресной сделки по операции РЕПО с ЦК; 
                                                «16» – Техническая сделка по возврату активов РЕПО с ЦК; 
                                                «17» – Сделка по спреду между фьючерсами разных сроков на один актив; 
                                                «18» – Техническая сделка первой части от спреда между фьючерсами; 
                                                «19» – Техническая сделка второй части от спреда между фьючерсами; 
                                                «20» – Адресная сделка первой части РЕПО с корзиной; 
                                                «21» – Адресная сделка второй части РЕПО с корзиной; 
                                                «22» – Перенос позиций срочного рынка */
    LUACPP_TABLE_FIELD(clearing_bank_accid, std::string) // Идентификатор счета в НКЦ (расчетный код) 
    LUACPP_TABLE_FIELD(canceled_datetime, ::qlua::datatype::datetime) // Дата и время снятия сделки 
    LUACPP_TABLE_FIELD(clearing_firmid, std::string) // Идентификатор фирмы - участника клиринга 
    LUACPP_TABLE_FIELD(system_ref, std::string) // Дополнительная информация по сделке, передаваемая торговой системой 
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор пользователя на сервере QUIK
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::trades)

// stop_orders "Стоп-заявки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(stop_orders)
    LUACPP_TABLE_FIELD(order_num, unsigned int) // Регистрационный номер стоп-заявки на сервере QUIK  
    LUACPP_TABLE_FIELD(ordertime, ::qlua::datatype::datetime) // Время выставления  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(brokerref, std::string) // Комментарий, обычно: <код клиента>/<номер поручения> 
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор дилера  
    LUACPP_TABLE_FIELD(account, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(condition, unsigned int) /* Направленность стоп-цены. Возможные значения: 
                                                   «4» – «<=», 
                                                   «5» – «>=» */
    LUACPP_TABLE_FIELD(condition_price, double) // Стоп-цена  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество в лотах  
    LUACPP_TABLE_FIELD(linkedorder, unsigned int) // Номер заявки в торговой системе, зарегистрированной по наступлению условия стоп-цены  
    LUACPP_TABLE_FIELD(expiry, int) // Дата окончания срока действия заявки 
    LUACPP_TABLE_FIELD(trans_id, unsigned int) // Идентификатор транзакции  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(co_order_num, unsigned int) // Связанная заявка  
    LUACPP_TABLE_FIELD(co_order_price, double) // Цена связанной заявки  
    LUACPP_TABLE_FIELD(stop_order_type, unsigned int) /* Вид стоп заявки. Возможные значения: 
                                                         «1» – стоп-лимит; 
                                                         «2» – условие по другому инструменту; 
                                                         «3» – со связанной заявкой; 
                                                         «6» – тейк-профит; 
                                                         «7» – стоп-лимит по исполнению активной заявки; 
                                                         «8» – тейк-профит по исполнению активной заявки; 
                                                         «9» - тейк-профит и стоп-лимит */
    LUACPP_TABLE_FIELD(orderdate, int) // Дата выставления  
    LUACPP_TABLE_FIELD(alltrade_num, unsigned int) // Сделка условия  
    LUACPP_TABLE_FIELD(stopflags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(offset, double) // Отступ от min/max  
    LUACPP_TABLE_FIELD(spread, double) // Защитный спред  
    LUACPP_TABLE_FIELD(balance, double) // Активное количество  
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор пользователя  
    LUACPP_TABLE_FIELD(filled_qty, unsigned int) // Исполненное количество  
    LUACPP_TABLE_FIELD(withdraw_time, int) // Время снятия заявки  
    LUACPP_TABLE_FIELD(condition_price2, double) // Стоп-лимит цена (для заявок типа «Тэйк-профит и стоп-лимит»)  
    LUACPP_TABLE_FIELD(active_from_time, int) // Время начала периода действия заявки типа «Тэйк-профит и стоп-лимит»  
    LUACPP_TABLE_FIELD(active_to_time, int) // Время окончания периода действия заявки типа «Тэйк-профит и стоп-лимит»  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги заявки  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса заявки  
    LUACPP_TABLE_FIELD(condition_sec_code, std::string) // Код бумаги стоп-цены  
    LUACPP_TABLE_FIELD(condition_class_code, std::string) // Код класса стоп-цены  
    LUACPP_TABLE_FIELD(canceled_uid, unsigned int) // Идентификатор пользователя, снявшего стоп-заявку 
    LUACPP_TABLE_FIELD(order_date_time, ::qlua::datatype::datetime) // Время выставления стоп-заявки 
    LUACPP_TABLE_FIELD(withdraw_datetime, ::qlua::datatype::datetime) // Время снятия стоп-заявки 

    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::stop_orders)

// neg_deals "Заявки на внебиржевые сделки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(neg_deals)
    LUACPP_TABLE_FIELD(neg_deal_num, unsigned int) // Номер  
    LUACPP_TABLE_FIELD(neg_deal_time, int) // Время выставления заявки  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(brokerref, std::string) // Комментарий, обычно: <код клиента>/<номер поручения>  
    LUACPP_TABLE_FIELD(userid, std::string) // Трейдер  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор дилера  
    LUACPP_TABLE_FIELD(cpuserid, std::string) // Трейдер партнера  
    LUACPP_TABLE_FIELD(cpfirmid, std::string) // Код фирмы партнера  
    LUACPP_TABLE_FIELD(account, std::string) // Счет  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество  
    LUACPP_TABLE_FIELD(matchref, std::string) // Ссылка  
    LUACPP_TABLE_FIELD(settlecode, std::string) // Код расчетов  
    LUACPP_TABLE_FIELD(yield, double) // Доходность  
    LUACPP_TABLE_FIELD(accruedint, double) // Купонный процент  
    LUACPP_TABLE_FIELD(value, double) // Объем  
    LUACPP_TABLE_FIELD(price2, double) // Цена выкупа  
    LUACPP_TABLE_FIELD(reporate, double) // Ставка РЕПО (%)  
    LUACPP_TABLE_FIELD(refundrate, double) // Ставка возмещения (%)  
    LUACPP_TABLE_FIELD(trans_id, unsigned int) // ID транзакции  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(repoentry, unsigned int) /* Тип ввода заявки РЕПО. Возможные значения: 
                                             «0» – «Не определен»; 
                                             «1» – «Цена1+Ставка»; 
                                             «2» – «Ставка+ Цена2»; 
                                             «3» – «Цена1+Цена2»; 
                                             «4» – «Сумма РЕПО + Количество»; 
                                             «5» – «Сумма РЕПО + Дисконт»; 
                                             «6» – «Количество + Дисконт»; 
                                             «7» – «Сумма РЕПО»; 
                                             «8» – «Количество» */
    LUACPP_TABLE_FIELD(repovalue, double) // Сумма РЕПО  
    LUACPP_TABLE_FIELD(repo2value, double) // Объем выкупа РЕПО  
    LUACPP_TABLE_FIELD(repoterm, double) // Срок РЕПО  
    LUACPP_TABLE_FIELD(start_discount, double) // Начальный дисконт (%) 
    LUACPP_TABLE_FIELD(lower_discount, double) // Нижний дисконт (%)  
    LUACPP_TABLE_FIELD(upper_discount, double) // Верхний дисконт (%)  
    LUACPP_TABLE_FIELD(block_securities, unsigned int) // Блокировка обеспечения («Да»/«Нет»)  
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор пользователя  
    LUACPP_TABLE_FIELD(withdraw_time, int) // Время снятия заявки  
    LUACPP_TABLE_FIELD(neg_deal_date, int) // Дата выставления заявки  
    LUACPP_TABLE_FIELD(balance, double) // Остаток  
    LUACPP_TABLE_FIELD(origin_repovalue, double) // Сумма РЕПО первоначальная  
    LUACPP_TABLE_FIELD(origin_qty, unsigned int) // Количество первоначальное  
    LUACPP_TABLE_FIELD(origin_discount, double) // Процент дисконта первоначальный  
    LUACPP_TABLE_FIELD(neg_deal_activation_date, int) // Дата активации заявки  
    LUACPP_TABLE_FIELD(neg_deal_activation_time, int) // Время активации заявки  
    LUACPP_TABLE_FIELD(quoteno, unsigned int) // Встречная безадресная заявка  
    LUACPP_TABLE_FIELD(settle_currency, std::string) // Валюта расчетов  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(withdraw_date, int) // Дата снятия адресной заявки в формате «ГГГГММДД»  
    LUACPP_TABLE_FIELD(linkedorder, unsigned int) // Номер предыдущей заявки. Отображается с точностью «0»  
    LUACPP_TABLE_FIELD(activation_date_time, ::qlua::datatype::datetime) // Дата и время активации заявки 
    LUACPP_TABLE_FIELD(withdraw_date_time, ::qlua::datatype::datetime) // Дата и время снятия заявки 
    LUACPP_TABLE_FIELD(date_time, ::qlua::datatype::datetime) // Дата и время заявки
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::neg_deals)

// neg_trades "Сделки для исполнения"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(neg_trades)
    LUACPP_TABLE_FIELD(trade_num, unsigned int) // Номер сделки  
    LUACPP_TABLE_FIELD(trade_date, int) // Дата торгов  
    LUACPP_TABLE_FIELD(settle_date, int) // Дата расчетов  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(brokerref, std::string) // Комментарий, обычно: <код клиента>/<номер поручения>  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор дилера  
    LUACPP_TABLE_FIELD(account, std::string) // Счет депо  
    LUACPP_TABLE_FIELD(cpfirmid, std::string) // Код фирмы партнера  
    LUACPP_TABLE_FIELD(cpaccount, std::string) // Счет депо партнера  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество  
    LUACPP_TABLE_FIELD(value, double) // Объем  
    LUACPP_TABLE_FIELD(settlecode, std::string) // Код расчетов  
    LUACPP_TABLE_FIELD(report_num, unsigned int) // Отчет  
    LUACPP_TABLE_FIELD(cpreport_num, unsigned int) // Отчет партнера  
    LUACPP_TABLE_FIELD(accruedint, double) // Купонный процент  
    LUACPP_TABLE_FIELD(repotradeno, double) // Номер сделки 1-ой части РЕПО  
    LUACPP_TABLE_FIELD(price1, double) // Цена 1-ой части РЕПО  
    LUACPP_TABLE_FIELD(reporate, double) // Ставка РЕПО (%)  
    LUACPP_TABLE_FIELD(price2, double) // Цена выкупа  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(ts_comission, double) // Комиссия торговой системы  
    LUACPP_TABLE_FIELD(balance, double) // Остаток  
    LUACPP_TABLE_FIELD(settle_time, int) // Время исполнения  
    LUACPP_TABLE_FIELD(amount, double) // Сумма обязательства  
    LUACPP_TABLE_FIELD(repovalue, double) // Сумма РЕПО  
    LUACPP_TABLE_FIELD(repoterm, double) // Срок РЕПО  
    LUACPP_TABLE_FIELD(repo2value, double) // Объем выкупа РЕПО  
    LUACPP_TABLE_FIELD(return_value, double) // Сумма возврата РЕПО  
    LUACPP_TABLE_FIELD(discount, double) // Дисконт (%)  
    LUACPP_TABLE_FIELD(lower_discount, double) // Нижний дисконт (%)  
    LUACPP_TABLE_FIELD(upper_discount, double) // Верхний дисконт (%)  
    LUACPP_TABLE_FIELD(block_securities, unsigned int) // Блокировать обеспечение («Да»/«Нет»)  
    LUACPP_TABLE_FIELD(urgency_flag, unsigned int) // Исполнить («Да»/«Нет»)  
    LUACPP_TABLE_FIELD(type, unsigned int) /* Тип. Возможные значения: 
                                        «0» – «Внесистемная сделка», 
                                        «1» – «Первая часть сделки РЕПО», 
                                        «2» – «Вторая часть сделки РЕПО», 
                                        «3» – «Компенсационный взнос», 
                                        «4» – «Дефолтер: отложенные обязательства и требования», 
                                        «5» – «Пострадавший: отложенные обязательства и требования». 
                                     */
    LUACPP_TABLE_FIELD(operation_type, unsigned int) /* Направленность. Возможные значения: 
                                                  «1» – «Зачислить», 
                                                  «2» – «Списать». */
 
    LUACPP_TABLE_FIELD(expected_discount, double) // Дисконт после взноса (%)  
    LUACPP_TABLE_FIELD(expected_quantity, double) // Количество после взноса  
    LUACPP_TABLE_FIELD(expected_repovalue, double) // Сумма РЕПО после взноса  
    LUACPP_TABLE_FIELD(expected_repo2value, double) // Стоимость выкупа после взноса  
    LUACPP_TABLE_FIELD(expected_return_value, double) // Сумма возврата после взноса  
    LUACPP_TABLE_FIELD(order_num, unsigned int) // Номер заявки  
    LUACPP_TABLE_FIELD(report_trade_date, int) // Дата заключения  
    LUACPP_TABLE_FIELD(settled, unsigned int) /* Состояние расчетов по сделке. Возможные значения: 
                                           «1» – «Processed», 
                                           «2» – «Not processed», 
                                           «3» – «Is processing». 
                                        */
    LUACPP_TABLE_FIELD(clearing_type, unsigned int) /* Тип клиринга. Возможные значения: 
                                                 «1» – «Not set», 
                                                 «2» – «Simple», 
                                                 «3» – «Multilateral». */
 
    LUACPP_TABLE_FIELD(report_comission, double) // Комиссия за отчет  
    LUACPP_TABLE_FIELD(coupon_payment, double) // Купонная выплата  
    LUACPP_TABLE_FIELD(principal_payment, double) // Выплата по основному долгу  
    LUACPP_TABLE_FIELD(principal_payment_date, int) // Дата выплаты по основному долгу  
    LUACPP_TABLE_FIELD(nextdaysettle, int) // Дата следующего дня расчетов  
    LUACPP_TABLE_FIELD(settle_currency, std::string) // Валюта расчетов  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса  
    LUACPP_TABLE_FIELD(compval, double) // Сумма отступного в валюте сделки 
    LUACPP_TABLE_FIELD(parenttradeno, unsigned int) // Идентификационный номер витринной сделки 
    LUACPP_TABLE_FIELD(bankid, std::string) // Расчетная организация 
    LUACPP_TABLE_FIELD(bankaccid, std::string) // Код позиции 
    LUACPP_TABLE_FIELD(precisebalance, unsigned int) // Количество бумаг к исполнению (в лотах) 
    LUACPP_TABLE_FIELD(confirmtime, int) // Время подтверждения в формате «ЧЧММСС» 
    LUACPP_TABLE_FIELD(ex_flags, unsigned int) /* Расширенные флаги сделки для исполнения. Возможные значения: 
                                            «1» – «Подтверждена контрагентом»; 
                                            «2» – «Подтверждена»  */
    LUACPP_TABLE_FIELD(confirmreport, unsigned int) // Номер поручения 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::neg_trades)

// neg_deal_reports "Отчеты по сделкам для исполнения"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(neg_deal_reports)
    LUACPP_TABLE_FIELD(report_num, unsigned int) // Отчет  
    LUACPP_TABLE_FIELD(report_date, int) // Дата отчета  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(userid, std::string) // Идентификатор пользователя  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(account, std::string) // Счет депо  
    LUACPP_TABLE_FIELD(cpfirmid, std::string) // Код фирмы партнера  
    LUACPP_TABLE_FIELD(cpaccount, std::string) // Код торгового счета партнера  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество бумаг, в лотах  
    LUACPP_TABLE_FIELD(value, double) // Объем сделки, выраженный в рублях  
    LUACPP_TABLE_FIELD(withdraw_time, int) // Время снятия заявки  
    LUACPP_TABLE_FIELD(report_type, unsigned int) // Тип отчета  
    LUACPP_TABLE_FIELD(report_kind, unsigned int) // Вид отчета  
    LUACPP_TABLE_FIELD(commission, double) // Объем комиссии по сделке, выраженный в руб  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги 
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса 
    LUACPP_TABLE_FIELD(report_time, int) // Время отчета 
    LUACPP_TABLE_FIELD(report_date_time, ::qlua::datatype::datetime) // Дата и время отчета
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::neg_deal_reports)

// firm_holding "Текущие позиции по бумагам"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(firm_holding)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги  
    LUACPP_TABLE_FIELD(openbal, double) // Входящий остаток  
    LUACPP_TABLE_FIELD(currentpos, double) // Текущий остаток  
    LUACPP_TABLE_FIELD(plannedposbuy, double) // Объем активных заявок на покупку, в ценных бумагах  
    LUACPP_TABLE_FIELD(plannedpossell, double) // Объем активных заявок на продажу, в ценных бумагах  
    LUACPP_TABLE_FIELD(usqtyb, double) // Куплено  
    LUACPP_TABLE_FIELD(usqtys, double) // Продано
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::firm_holding)

// account_balance "Текущиее позиции по клиентским счетам"    
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(account_balance)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги  
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(depaccid, std::string) // Счет депо  
    LUACPP_TABLE_FIELD(openbal, double) // Входящий остаток  
    LUACPP_TABLE_FIELD(currentpos, double) // Текущий остаток  
    LUACPP_TABLE_FIELD(plannedpossell, double) // Плановая продажа  
    LUACPP_TABLE_FIELD(plannedposbuy, double) // Плановая покупка  
    LUACPP_TABLE_FIELD(planbal, double) // Контрольный остаток простого клиринга, равен входящему остатку минус плановая позиция на продажу, включенная в простой клиринг  
    LUACPP_TABLE_FIELD(usqtyb, unsigned int) // Куплено  
    LUACPP_TABLE_FIELD(usqtys, unsigned int) // Продано  
    LUACPP_TABLE_FIELD(planned, double) // Плановый остаток, равен текущему остатку минус плановая позиция на продажу  
    LUACPP_TABLE_FIELD(settlebal, double) // Плановая позиция после проведения расчетов  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(firmuse, unsigned int) /* Признак счета обеспечения. Возможные значения: 
                                                 «0» – для обычных счетов, 
                                                 «1» – для счета обеспечения. */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::account_balance)
  
// ccp_holdings "Обязательства и требования по активам"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(ccp_holdings)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(depo_account, std::string) // Номер счета депо в Депозитарии (НДЦ)  
    LUACPP_TABLE_FIELD(account, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(settle_date, int) // Дата расчетов  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество ценных бумаг в сделках  
    LUACPP_TABLE_FIELD(qty_buy, unsigned int) // Количество ценных бумаг в заявках на покупку  
    LUACPP_TABLE_FIELD(qty_sell, unsigned int) // Количество ценных бумаг в заявках на продажу  
    LUACPP_TABLE_FIELD(netto, double) // Нетто-позиция  
    LUACPP_TABLE_FIELD(debit, double) // Дебет  
    LUACPP_TABLE_FIELD(credit, double) // Кредит  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги заявки  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса заявки  
    LUACPP_TABLE_FIELD(planned_covered, double) /* Плановая позиция Т+  

firm_use  NUMBER  Тип раздела. Возможные значения: 
«0» – торговый раздел; 
«1» – раздел обеспечения */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::ccp_holdings)

// rm_holdings "Валюта: обящательства и требования по активам"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(rm_holdings)
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса  
    LUACPP_TABLE_FIELD(firmId, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(account, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета в НКЦ  
    LUACPP_TABLE_FIELD(date, int) // Дата расчётов  
    LUACPP_TABLE_FIELD(debit, double) // Размер денежных обязательств  
    LUACPP_TABLE_FIELD(credit, double) // Размер денежных требований  
    LUACPP_TABLE_FIELD(value_buy, double) // Сумма денежных средств в заявках на покупку  
    LUACPP_TABLE_FIELD(value_sell, double) // Сумма денежных средств в заявках на продажу  
    LUACPP_TABLE_FIELD(margin_call, double) // Сумма возврата компенсационного перевода  
    LUACPP_TABLE_FIELD(planned_covered, double) // Плановая позиция Т+  
    LUACPP_TABLE_FIELD(debit_balance, double) // Размер денежных обязательств на начало дня, с точностью до 2 знака после десятичного разделителя  
    LUACPP_TABLE_FIELD(credit_balance, double) // Размер денежных требований на начало дня, с точностью до 2 знака после десятичного разделителя
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::rm_holdings)
