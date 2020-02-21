#pragma once

/*
  QLUA tables structures
  Список по "Таблицы, используемые в функциях «getItem», «getNumberOf» и «SearchItems»"; по таблицам, возвращаемым коллбеками
*/
#include <string>

#include <luacpp/luacpp>

#include "datetime.hpp"

// Regex:   *\(.*?\) +\(.*?\) +\(.*\)$LUACPP_TABLE_FIELD(\1, \2) // \3

// firms "Фирмы"
// Object names in qlua.chm: firm
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(firms)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы 
    LUACPP_TABLE_FIELD(firm_name, std::string) // Название класса  
    LUACPP_TABLE_FIELD(status, unsigned int) // Статус  
    LUACPP_TABLE_FIELD(exchange, std::string) // Торговая площадка  
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::firms)

// classes "Классы"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(classes)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы 
    LUACPP_TABLE_FIELD(name, std::string) // Название класса 
    LUACPP_TABLE_FIELD(code, std::string) // Код класса 
    LUACPP_TABLE_FIELD(npars, unsigned int) // Количество параметров в классе 
    LUACPP_TABLE_FIELD(nsecs, unsigned int) // Количество бумаг в классе
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::classes)

// securities "Инструменты" (ценные бумаги)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(securities)
    LUACPP_TABLE_FIELD(code, std::string) // Код инструмента  
    LUACPP_TABLE_FIELD(name, std::string) // Наименование инструмента  
    LUACPP_TABLE_FIELD(short_name, std::string) // Короткое наименование инструмента  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса инструментов  
    LUACPP_TABLE_FIELD(class_name, std::string) // Наименование класса инструментов  
    LUACPP_TABLE_FIELD(face_value, double) // Номинал  
    LUACPP_TABLE_FIELD(face_unit, std::string) // Валюта номинала  
    LUACPP_TABLE_FIELD(scale, unsigned int) // Точность (количество значащих цифр после запятой)  
    LUACPP_TABLE_FIELD(mat_date, unsigned int) // Дата погашения  
    LUACPP_TABLE_FIELD(lot_size, double) // Размер лота  
    LUACPP_TABLE_FIELD(isin_code, std::string) // ISIN  
    LUACPP_TABLE_FIELD(min_price_step, double) // Минимальный шаг цены
    LUACPP_TABLE_FIELD(bsid, std::string) // Bloomberg ID  
    LUACPP_TABLE_FIELD(cusip_code, std::string) // CUSIP  
    LUACPP_TABLE_FIELD(stock_code, std::string) // StockCode  
    LUACPP_TABLE_FIELD(couponvalue, double) // Размер купона  
    LUACPP_TABLE_FIELD(sell_leg_classcode, std::string) // Код класса инструмента ноги на продажу  
    LUACPP_TABLE_FIELD(sell_leg_seccode, std::string) // Код инструмента ноги на продажу  
    LUACPP_TABLE_FIELD(first_currcode, std::string) // Код котируемой валюты в паре  
    LUACPP_TABLE_FIELD(second_currcode, std::string) // Код базовой валюты в паре  
    LUACPP_TABLE_FIELD(buy_leg_classcode, std::string) // Код класса инструмента ноги на покупку  
    LUACPP_TABLE_FIELD(buy_leg_seccode, std::string) // Код инструмента ноги на покупку  
    LUACPP_TABLE_FIELD(base_active_classcode, std::string) // Код класса базового актива  
    LUACPP_TABLE_FIELD(base_active_seccode, std::string) // Базовый актив  
    LUACPP_TABLE_FIELD(buy_mat_date, int) // Дата расчетов сделки на покупку  
    LUACPP_TABLE_FIELD(sell_mat_date, int) // Дата расчетов сделки на продажу  
    LUACPP_TABLE_FIELD(option_strike, double) // Страйк опциона  
    LUACPP_TABLE_FIELD(qty_multiplier, unsigned int) // Кратность при вводе количества  
    LUACPP_TABLE_FIELD(step_price_currency, std::string) // Валюта шага цены  
    LUACPP_TABLE_FIELD(sedol_code, std::string) // SEDOL  
    LUACPP_TABLE_FIELD(cfi_code, std::string) // CFI  
    LUACPP_TABLE_FIELD(ric_code, std::string) // RIC  
    LUACPP_TABLE_FIELD(buybackdate, int) // Дата оферты  
    LUACPP_TABLE_FIELD(buybackprice, int) // Цена оферты  
    LUACPP_TABLE_FIELD(list_level, int) // Уровень листинга  
    LUACPP_TABLE_FIELD(qty_scale, double) // Точность количества  
    LUACPP_TABLE_FIELD(yieldatprevwaprice, double) // Доходность по предыдущей оценке  
    LUACPP_TABLE_FIELD(regnumber, std::string) // Регистрационный номер  
    LUACPP_TABLE_FIELD(trade_currency, std::string) // Валюта торгов  
    LUACPP_TABLE_FIELD(second_curr_qty_scale, double) // Точность количества котируемой валюты  
    LUACPP_TABLE_FIELD(first_curr_qty_scale, double) // Точность количества базовой валюты  
    LUACPP_TABLE_FIELD(accruedint, double) // Накопленный купонный доход 
    LUACPP_TABLE_FIELD(stock_name, std::string) // Код деривативного контракта в формате QUIK  
    LUACPP_TABLE_FIELD(nextcoupon, int) // Дата выплаты купона  
    LUACPP_TABLE_FIELD(couponperiod, int) // Длительность купона  
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::securities)

// trade_accounts "Торговые счета"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(trade_accounts)
    LUACPP_TABLE_FIELD(class_codes, std::string) // Список кодов классов, разделенных символом «|» 
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы 
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Код торгового счета 
    LUACPP_TABLE_FIELD(description, std::string) // Описание 
    LUACPP_TABLE_FIELD(fullcoveredsell, unsigned int) /* Запрет необеспеченных продаж. Возможные значения: 
                                                         «0» – Нет; 
                                                         «1» – Да */
    LUACPP_TABLE_FIELD(main_trdaccid, std::string) // Номер основного торгового счета 
    LUACPP_TABLE_FIELD(bankid_t0, std::string) // Расчетная организация по «Т0» 
    LUACPP_TABLE_FIELD(bankid_tplus, std::string) // Расчетная организация по «Т+» 
    LUACPP_TABLE_FIELD(trdacc_type, unsigned int) // Тип торгового счета 
    LUACPP_TABLE_FIELD(depunitid, std::string) // Раздел счета Депо 
    LUACPP_TABLE_FIELD(status, unsigned int) /* Статус торгового счета. Возможные значения: 
                                                «0» – операции разрешены; 
                                                «1» – операции запрещены
                                             */
    LUACPP_TABLE_FIELD(firmuse, unsigned int) /* Тип раздела. Возможные значения: 
                                                 «0» – раздел обеспечения; 
                                                 иначе – для торговых разделов */
    LUACPP_TABLE_FIELD(depaccid, std::string) // Номер счета депо в депозитарии 
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Код дополнительной позиции по денежным средствам
    // Quik 8.1: Exists in qlua.chm help file, doesn't really exist in terminal
    //LUACPP_TABLE_FIELD(exec_market, std::string) // Идентификатор биржевой площадки 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::trade_accounts)
    
// client_codes "Коды клиентов"
// (Not really a table, an array of strings)
namespace qlua {
  namespace table {
    using client_codes = std::string;
  }
}

// account_positions "Денежные позиции"
// Object names in qlua.chm: acc_pos
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(account_positions)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(currcode, std::string) // Код валюты  
    LUACPP_TABLE_FIELD(tag, std::string) // Тег расчетов  
    LUACPP_TABLE_FIELD(description, std::string) // Описание  
    LUACPP_TABLE_FIELD(openbal, double) // Входящий остаток  
    LUACPP_TABLE_FIELD(currentpos, double) // Текущий остаток  
    LUACPP_TABLE_FIELD(plannedpos, double) // Плановый остаток  
    LUACPP_TABLE_FIELD(limit1, double) // Внешнее ограничение по деньгам  
    LUACPP_TABLE_FIELD(limit2, double) // Внутреннее (собственное) ограничение по деньгам  
    LUACPP_TABLE_FIELD(orderbuy, double) // В заявках на продажу  
    LUACPP_TABLE_FIELD(ordersell, double) // В заявках на покупку  
    LUACPP_TABLE_FIELD(netto, double) // Нетто-позиция  
    LUACPP_TABLE_FIELD(plannedbal, double) // Плановая позиция  
    LUACPP_TABLE_FIELD(debit, double) // Дебет  
    LUACPP_TABLE_FIELD(credit, double) // Кредит  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор счета  
    LUACPP_TABLE_FIELD(margincall, double) // Маржинальное требование на начало торгов  
    LUACPP_TABLE_FIELD(settlebal, double) // Плановая позиция после проведения расчетов  
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::account_positions)
    
// orders "Заявки"
// Object names in qlua.chm: order "Таблица с параметрами заявки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(orders)
    LUACPP_TABLE_FIELD(order_num, std::string) // Номер заявки в торговой системе  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов 
    LUACPP_TABLE_FIELD(brokerref, std::string) // Комментарий, обычно: <код клиента>/<номер поручения>  
    LUACPP_TABLE_FIELD(userid, std::string) // Идентификатор трейдера  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(account, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество в лотах  
    LUACPP_TABLE_FIELD(balance, unsigned int) // Остаток  
    LUACPP_TABLE_FIELD(value, double) // Объем в денежных средствах  
    LUACPP_TABLE_FIELD(accruedint, double) // Накопленный купонный доход  
    LUACPP_TABLE_FIELD(yield, double) // Доходность  
    LUACPP_TABLE_FIELD(trans_id, unsigned int) // Идентификатор транзакции  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(price2, double) // Цена выкупа  
    LUACPP_TABLE_FIELD(settlecode, std::string) // Код расчетов  
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор пользователя  
    LUACPP_TABLE_FIELD(canceled_uid, unsigned int) // Идентификатор пользователя, снявшего заявку  
    LUACPP_TABLE_FIELD(exchange_code, std::string) // Код биржи в торговой системе  
    LUACPP_TABLE_FIELD(activation_time, int) // Время активации  
    LUACPP_TABLE_FIELD(linkedorder, unsigned int) // Номер заявки в торговой системе  
    LUACPP_TABLE_FIELD(expiry, int) // Дата окончания срока действия заявки  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги заявки  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса заявки
    QLUACPP_DATETIME_TABLE_FIELD(datetime) // Дата и время 
    QLUACPP_DATETIME_TABLE_FIELD(withdraw_datetime) // Дата и время снятия заявки  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(value_entry_type, unsigned int) /* Способ указания объема заявки. Возможные значения:

«0» – по количеству, 
«1» – по объему */
    LUACPP_TABLE_FIELD(repoterm, double) // Срок РЕПО, в календарных днях  
    LUACPP_TABLE_FIELD(repovalue, double) // Сумма РЕПО на текущую дату. Отображается с точностью 2 знака  
    LUACPP_TABLE_FIELD(repo2value, double) // Объём сделки выкупа РЕПО. Отображается с точностью 2 знака  
    LUACPP_TABLE_FIELD(repo_value_balance, double) // Остаток суммы РЕПО за вычетом суммы привлеченных или предоставленных по сделке РЕПО денежных средств в неисполненной части заявки, по состоянию на текущую дату. Отображается с точностью 2 знака  
    LUACPP_TABLE_FIELD(start_discount, double) // Начальный дисконт, в %  
    LUACPP_TABLE_FIELD(reject_reason, std::string) // Причина отклонения заявки брокером  
    LUACPP_TABLE_FIELD(ext_order_flags, unsigned int) // Битовое поле для получения специфических параметров с западных площадок  
    LUACPP_TABLE_FIELD(min_qty, unsigned int) // Минимально допустимое количество, которое можно указать в заявке по данному инструменту. Если имеет значение «0», значит ограничение по количеству не задано  
    LUACPP_TABLE_FIELD(exec_type, unsigned int) // Тип исполнения заявки. Если имеет значение «0», значит значение не задано  
    LUACPP_TABLE_FIELD(side_qualifier, unsigned int) // Поле для получения параметров по западным площадкам. Если имеет значение «0», значит значение не задано  
    LUACPP_TABLE_FIELD(acnt_type, unsigned int) // Поле для получения параметров по западным площадкам. Если имеет значение «0», значит значение не задано  
    LUACPP_TABLE_FIELD(capacity, double) // Поле для получения параметров по западным площадкам. Если имеет значение «0», значит значение не задано  
    LUACPP_TABLE_FIELD(passive_only_order, unsigned int) // Поле для получения параметров по западным площадкам. Если имеет значение «0», значит значение не задано  
    LUACPP_TABLE_FIELD(visible, unsigned int) // Видимое количество. Параметр айсберг-заявок, для обычных заявок выводится значение: «0»

    LUACPP_TABLE_FIELD(awg_price, double) // Средняя цена приобретения. Актуально, когда заявка выполнилась частями 
    LUACPP_TABLE_FIELD(expiry_time, int) // Время окончания срока действия заявки в формате <ЧЧММСС DESIGNTIMESP=19552>. Для GTT-заявок, используется вместе со сроком истечения заявки (Expiry)  
    LUACPP_TABLE_FIELD(revision_number, unsigned int) // Номер ревизии заявки. Используется, если заявка была заменена с сохранением номера 
    LUACPP_TABLE_FIELD(price_currency, std::string) // Валюта цены заявки 
    LUACPP_TABLE_FIELD(ext_order_status, unsigned int) /* Расширенный статус заявки. Возможные значения: 
                                                          «0» (по умолчанию) – не определено; 
                                                          «1» – заявка активна; 
                                                          «2» – заявка частично исполнена; 
                                                          «3» – заявка исполнена; 
                                                          «4» – заявка отменена; 
                                                          «5» – заявка заменена; 
                                                          «6» – заявка в состоянии отмены; 
                                                          «7» – заявка отвергнута; 
                                                          «8» – приостановлено исполнение заявки; 
                                                          «9» – заявка в состоянии регистрации; 
                                                          «10» – заявка снята по времени действия; 
                                                          «11» – заявка в состоянии замены 
                                                       */
 
    LUACPP_TABLE_FIELD(accepted_uid, unsigned int) // UID пользователя-менеджера, подтвердившего заявку при работе в режиме с подтверждениями 
    LUACPP_TABLE_FIELD(filled_value, double) // Исполненный объем заявки в валюте цены для частично или полностью исполненных заявок 
    LUACPP_TABLE_FIELD(extref, std::string) // Внешняя ссылка, используется для обратной связи с внешними системами  
    LUACPP_TABLE_FIELD(settle_currency, std::string) // Валюта расчетов по заявке 
    LUACPP_TABLE_FIELD(on_behalf_of_uid, unsigned int) // UID пользователя, от имени которого выставлена заявка 
    LUACPP_TABLE_FIELD(client_qualifier, unsigned int) /* Квалификатор клиента, от имени которого выставлена заявка. Возможные значения: 
                                                          «0» – не определено; 
                                                          «1» – Natural Person; 
                                                          «3» – Legal Entity
                                                       */
 
    LUACPP_TABLE_FIELD(client_short_code, unsigned int) // Краткий идентификатор клиента, от имени которого выставлена заявка 
    LUACPP_TABLE_FIELD(investment_decision_maker_qualifier, unsigned int) /* Квалификатор принявшего решение о выставлении заявки. Возможные значения: 
                                                                             «0» – не определено; 
                                                                             «1» – Natural Person; 
                                                                             «2» – Algorithm
                                                                          */
 
    LUACPP_TABLE_FIELD(investment_decision_maker_short_code, unsigned int) // Краткий идентификатор принявшего решение о выставлении заявки 
    LUACPP_TABLE_FIELD(executing_trader_qualifier, unsigned int) /* Квалификатор трейдера, исполнившего заявку. Возможные значения: 
                                                                    «0» – не определено; 
                                                                    «1» – Natural Person; 
                                                                    «2» – Algorithm
                                                                 */
 
    LUACPP_TABLE_FIELD(executing_trader_short_code, unsigned int) // Краткий идентификатор трейдера, исполнившего заявку 

    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::orders)
    
// futures_client_holding "Позиции по клиентским счетам (фьючерсы)"
// Object names in qlua.chm: fut_pos "Таблица с описанием позиции по срочному рынку"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(futures_client_holding)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код фьючерсного контракта  
    LUACPP_TABLE_FIELD(type, double) /* Тип лимита. Возможные значения: 
                                        «0» – не определён; 
                                        «1» – основной счет; 
                                        «2» – клиентские и дополнительные счета; 
                                        «4» – все счета торг. членов */
    LUACPP_TABLE_FIELD(startbuy, double) // Входящие длинные позиции  
    LUACPP_TABLE_FIELD(startsell, double) // Входящие короткие позиции  
    LUACPP_TABLE_FIELD(startnet, double) // Входящие чистые позиции  
    LUACPP_TABLE_FIELD(todaybuy, double) // Текущие длинные позиции  
    LUACPP_TABLE_FIELD(todaysell, double) // Текущие короткие позиции  
    LUACPP_TABLE_FIELD(totalnet, double) // Текущие чистые позиции  
    LUACPP_TABLE_FIELD(openbuys, double) // Активные на покупку  
    LUACPP_TABLE_FIELD(opensells, double) // Активные на продажу  
    LUACPP_TABLE_FIELD(cbplused, double) // Оценка текущих чистых позиций  
    LUACPP_TABLE_FIELD(cbplplanned, double) // Плановые чистые позиции  
    LUACPP_TABLE_FIELD(varmargin, double) // Вариационная маржа  
    LUACPP_TABLE_FIELD(avrposnprice, double) // Эффективная цена позиций  
    LUACPP_TABLE_FIELD(positionvalue, double) // Стоимость позиций  
    LUACPP_TABLE_FIELD(real_varmargin, double) // Реально начисленная в ходе клиринга вариационная маржа. Отображается с точностью до 2 двух знаков. При этом, в поле «varmargin» транслируется вариационная маржа, рассчитанная с учетом установленных границ изменения цены  
    LUACPP_TABLE_FIELD(total_varmargin, double) // Суммарная вариационная маржа по итогам основного клиринга начисленная по всем позициям. Отображается с точностью до 2 двух знаков  
    LUACPP_TABLE_FIELD(session_status, unsigned int) /* Актуальный статус торговой сессии. Возможные значения: 
                                                        «0» – не определено; 
                                                        «1» – основная сессия; 
                                                        «2» – начался промклиринг; 
                                                        «3» – завершился промклиринг; 
                                                        «4» – начался основной клиринг; 
                                                        «5» – основной клиринг: новая сессия назначена; 
                                                        «6» – завершился основной клиринг; 
                                                        «7» – завершилась вечерняя сессия */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::futures_client_holding)
    
// futures_client_limits "Лимиты по фьючерсам"
// Object name in qlua.chm: fut_limit "Таблица с текущими значениями лимита по срочному рынку"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(futures_client_limits)
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(limit_type, unsigned int) /* Тип лимита. Возможные значения: 
                                                    «0» – «Денежные средства»; 
                                                    «1» – «Залоговые денежные средства»; 
                                                    «2» – «По совокупным средствам»; 
                                                    «3» – «Клиринговые денежные средства»; 
                                                    «4» – «Клиринговые залоговые денежные средства»; 
                                                    «5» – «Лимит открытых позиций на спот-рынке»; 
                                                    «6» – «Суммарные залоговые средства в иностранной валюте (в рублях)»; 
                                                    «7» – «Залоговые средства в иностранной валюте» */
 
    LUACPP_TABLE_FIELD(liquidity_coef, double) // Коэффициент ликвидности  
    LUACPP_TABLE_FIELD(cbp_prev_limit, double) // Предыдущий лимит открытых позиций на спот-рынке» 
    LUACPP_TABLE_FIELD(cbplimit, double) // Лимит открытых позиций  
    LUACPP_TABLE_FIELD(cbplused, double) // Текущие чистые позиции  
    LUACPP_TABLE_FIELD(cbplplanned, double) // Плановые чистые позиции  
    LUACPP_TABLE_FIELD(varmargin, double) // Вариационная маржа  
    LUACPP_TABLE_FIELD(accruedint, double) // Накопленный доход   
    LUACPP_TABLE_FIELD(cbplused_for_orders, double) // Текущие чистые позиции (под заявки)  
    LUACPP_TABLE_FIELD(cbplused_for_positions, double) // Текущие чистые позиции (под открытые позиции)  
    LUACPP_TABLE_FIELD(options_premium, double) // Премия по опционам  
    LUACPP_TABLE_FIELD(ts_comission, double) // Биржевые сборы  
    LUACPP_TABLE_FIELD(kgo, double) // Коэффициент клиентского гарантийного обеспечения  
    LUACPP_TABLE_FIELD(currcode, std::string) // Валюта, в которой транслируется ограничение  
    LUACPP_TABLE_FIELD(real_varmargin, double) // Реально начисленная в ходе клиринга вариационная маржа. Отображается с точностью до 2 двух знаков. При этом в поле «varmargin» транслируется вариационная маржа, рассчитанная с учетом установленных границ изменения цены  
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::futures_client_limits)

// all_trades "Обезличенные сделки"
// Object names in qlua.chm: alltrade
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(all_trades)

    LUACPP_TABLE_FIELD(trade_num, std::string) // Номер сделки в торговой системе 
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество бумаг в последней сделке в лотах  
    LUACPP_TABLE_FIELD(value, double) // Объем в денежных средствах  
    LUACPP_TABLE_FIELD(accruedint, double) // Накопленный купонный доход  
    LUACPP_TABLE_FIELD(yield, double) // Доходность  
    LUACPP_TABLE_FIELD(settlecode, std::string) // Код расчетов  
    LUACPP_TABLE_FIELD(reporate, double) // Ставка РЕПО (%)  
    LUACPP_TABLE_FIELD(repovalue, double) // Сумма РЕПО  
    LUACPP_TABLE_FIELD(repo2value, double) // Объем выкупа РЕПО  
    LUACPP_TABLE_FIELD(repoterm, double) // Срок РЕПО в днях  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги заявки  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса
    QLUACPP_DATETIME_TABLE_FIELD(datetime) // Дата и время 
    LUACPP_TABLE_FIELD(period, unsigned int) /* Период торговой сессии. Возможные значения:
    
    «0» – Открытие; 
    «1» – Нормальный; 
    «2» – Закрытие 
                                             */
    LUACPP_TABLE_FIELD(open_interest, double) // Открытый интерес 
    LUACPP_TABLE_FIELD(exchange_code, std::string) // Код биржи в торговой системе 
    LUACPP_TABLE_FIELD(exec_market, std::string) // Площадка исполнения 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::all_trades)


// futures_limit_delete "Таблица с параметрами удаляемого лимита по срочному рынку" (callback)
// Object names in qlua.chm: lim_del
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(futures_limit_delete)
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Код торгового счета  
    LUACPP_TABLE_FIELD(limit_type, unsigned int) /* Тип лимита. Возможные значения: 
                                                    «0» – «Денежные средства», 
                                                    «1» – «Залоговые денежные средства», 
                                                    «2» – «По совокупным средствам»; 
                                                    «3» – «Клиринговые денежные средства»; 
                                                    «4» – «Клиринговые залоговые денежные средства»; 
                                                    «5» – «Лимит открытых позиций на спот-рынке»; 
                                                    «6» – «Суммарные залоговые средства в иностранной валюте (в рублях)»; 
                                                    «7» – «Залоговые средства в иностранной валюте» */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::futures_limit_delete)
    
// money_limits "Позиции по деньгам"
//   Old:
//     "Лимиты по денежным средствам"
// Object names in qlua.chm: mlimit
//     "Таблица «Позиции по деньгам»"
//   Old:
//     "Таблица с текущими значениями денежного лимита"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(money_limits)
    LUACPP_TABLE_FIELD(currcode, std::string) // Код валюты  
    LUACPP_TABLE_FIELD(tag, std::string) // Код позиции  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(openbal, double) // Входящий остаток  
    LUACPP_TABLE_FIELD(openlimit, double) // Входящий лимит  
    LUACPP_TABLE_FIELD(currentbal, double) // Текущий остаток   
    LUACPP_TABLE_FIELD(currentlimit, double) // Текущий лимит  
    LUACPP_TABLE_FIELD(locked, double) // Заблокировано. Сумма средств, заблокированных под исполнение заявок клиента  
    LUACPP_TABLE_FIELD(locked_value_coef, double) // Стоимость активов в заявках на покупку немаржинальных инструментов 
    LUACPP_TABLE_FIELD(locked_margin_value, double) // Стоимость активов в заявках на покупку маржинальных инструментов 
    LUACPP_TABLE_FIELD(leverage, double) // Плечо 
    LUACPP_TABLE_FIELD(limit_kind, int) /* Срок расчётов. Возможные значения: 
                                           положительные целые числа, начиная с «0», соответствующие срокам расчётов из таблицы «Позиции по деньгам»: «0» – T0, «1» – T1, «2» – T2 и т.д.; 
                                           отрицательные целые числа – технологические лимиты (используются для внутренней работы системы QUIK) */
 
    LUACPP_TABLE_FIELD(wa_position_price, double) // Средневзвешенная цена приобретения позиции 
    LUACPP_TABLE_FIELD(orders_collateral, double) // Гарантийное обеспечение заявок  
    LUACPP_TABLE_FIELD(positions_collateral, double) // Гарантийное обеспечение позиций  
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::money_limits)

// money_limit_delete "Таблица с параметрами удаляемого денежного лимита" (callback)
// Object names in qlua.chm: mlimit_del
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(money_limit_delete)
    LUACPP_TABLE_FIELD(currcode, std::string) // Код валюты  
    LUACPP_TABLE_FIELD(tag, std::string) // Тег расчетов  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(limit_kind, int) /* Вид лимита. Возможные значения: 
                                           положительные целые числа, начиная с «0», соответствующие видам лимитов из таблицы «Лимиты по денежным средствам»: «0» – T0, «1» – T1, «2» – T2 и т.д.; 
                                           отрицательные целые числа – технологические лимиты (используются для внутренней работы системы QUIK)  */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::money_limit_delete)

// depo_limits "Лимиты по бумагам"
// Object names in qlua.chm: dlimit
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(depo_limits)
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код бумаги  
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Счет депо  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(openbal, double) // Входящий остаток по бумагам  
    LUACPP_TABLE_FIELD(openlimit, double) // Входящий лимит по бумагам  
    LUACPP_TABLE_FIELD(currentbal, double) // Текущий остаток по бумагам  
    LUACPP_TABLE_FIELD(currentlimit, double) // Текущий лимит по бумагам  
    LUACPP_TABLE_FIELD(locked_sell, double) // Заблокировано на продажу количества лотов  
    LUACPP_TABLE_FIELD(locked_buy, double) // Заблокировано на покупку количества лотов 
    LUACPP_TABLE_FIELD(locked_buy_value, double) // Стоимость ценных бумаг, заблокированных под покупку 
    LUACPP_TABLE_FIELD(locked_sell_value, double) // Стоимость ценных бумаг, заблокированных под продажу  
    LUACPP_TABLE_FIELD(wa_position_price, double) // Цена приобретения  
    LUACPP_TABLE_FIELD(limit_kind, int) /* Вид лимита. Возможные значения: 
                                           числа, начиная с «0», соответствующие видам лимитов из таблицы «Лимиты по бумагам»: «0» – T0, «1» – T1, «2» – T2 и т.д.; 
                                           числа – технологические лимиты (используются для внутренней работы системы QUIK)*/
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::depo_limits)

// depo_limit_delete "Таблица с параметрами удаляемого лимита по бумагам" (callback)
// Object names in qlua.chm: dlimit_del
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(depo_limit_delete)
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код инструмента  
    LUACPP_TABLE_FIELD(trdaccid, std::string) // Код торгового счета  
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор фирмы  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(limit_kind, int) /* Вид лимита. Возможные значения: 
                                           положительные целые числа, начиная с «0», соответствующие видам лимитов из таблицы «Лимиты по бумагам»: «0» – T0, «1» – T1, «2» – T2 и т.д.; 
                                           отрицательные целые числа – технологические лимиты (используются для внутренней работы системы QUIK)  */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::depo_limit_delete)

// trades "Сделки"
// Object names in qlua.chm: trade "Таблица с параметрами сделки"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(trades)
    LUACPP_TABLE_FIELD(trade_num, std::string) // Номер сделки в торговой системе 
    LUACPP_TABLE_FIELD(order_num, std::string) // Номер заявки в торговой системе  
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
    QLUACPP_DATETIME_TABLE_FIELD(datetime) // Дата и время  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(broker_comission, double) // Комиссия брокера. Отображается с точностью до 2 двух знаков. Поле зарезервировано для будущего использования.  
    LUACPP_TABLE_FIELD(linked_trade, unsigned int) // Номер витринной сделки в Торговой Системе для сделок РЕПО с ЦК и SWAP  
    LUACPP_TABLE_FIELD(period, unsigned int) /* Период торговой сессии. Возможные значения: 
                                                «0» – Открытие; 
                                                «1» – Нормальный; 
                                                «2» – Закрытие */

    LUACPP_TABLE_FIELD(trans_id, unsigned int) // Идентификатор транзакции 
    LUACPP_TABLE_FIELD(kind, unsigned int) /* Тип сделки. Возможные значения:
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
    QLUACPP_DATETIME_TABLE_FIELD(canceled_datetime) // Дата и время снятия сделки 
    LUACPP_TABLE_FIELD(clearing_firmid, std::string) // Идентификатор фирмы - участника клиринга 
    LUACPP_TABLE_FIELD(system_ref, std::string) // Дополнительная информация по сделке, передаваемая торговой системой 
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор пользователя на сервере QUIK

    LUACPP_TABLE_FIELD(lseccode, std::string) // Приоритетное обеспечение 
    LUACPP_TABLE_FIELD(order_revision_number, unsigned int) // Номер ревизии заявки, по которой была совершена сделка 
    LUACPP_TABLE_FIELD(order_qty, unsigned int) // Количество в заявке на момент совершения сделки, в лотах 
    LUACPP_TABLE_FIELD(order_price, double) // Цена в заявке на момент совершения сделки 
    LUACPP_TABLE_FIELD(order_exchange_code, std::string) // Биржевой номер заявки 
    LUACPP_TABLE_FIELD(exec_market, std::string) // Площадка исполнения 
    LUACPP_TABLE_FIELD(liquidity_indicator, unsigned int) /* Индикатор ликвидности. Возможные значения: 
                                                             «0» – не определено; 
                                                             «1» – по заявке мейкера; 
                                                             «2» – по заявке тейкера; 
                                                             «3» – вывод ликвидности; 
                                                             «4» – по заявке в период аукциона 
                                                          */
 
    LUACPP_TABLE_FIELD(extref, std::string) // Внешняя ссылка, используется для обратной связи с внешними системами 
    LUACPP_TABLE_FIELD(ext_trade_flags, unsigned int) // Расширенные флаги, полученные от шлюза напрямую, без вмешательства сервера QUIK. Поле не заполняется 
    LUACPP_TABLE_FIELD(on_behalf_of_uid, unsigned int) // UID пользователя, от имени которого совершена сделка 
    LUACPP_TABLE_FIELD(client_qualifier, unsigned int) /* Квалификатор клиента, от имени которого совершена сделка. Возможные значения: 
                                                          «0» – не определено; 
                                                          «1» – Natural Person; 
                                                          «3» – Legal Entity 
                                                       */
 
    LUACPP_TABLE_FIELD(client_short_code, unsigned int) // Краткий идентификатор клиента, от имени которого совершена сделка 
    LUACPP_TABLE_FIELD(investment_decision_maker_qualifier, unsigned int) /* Квалификатор принявшего решение о совершении сделки. Возможные значения: 
                                                                             «0» – не определено; 
                                                                             «1» – Natural Person; 
                                                                             «3» – Algorithm 
                                                                          */
 
    LUACPP_TABLE_FIELD(investment_decision_maker_short_code, unsigned int) // Краткий идентификатор принявшего решение о совершении сделки 
    LUACPP_TABLE_FIELD(executing_trader_qualifier, unsigned int) /* Квалификатор трейдера, исполнившего заявку, по которой совершена сделка.Возможные значения: 
                                                                    «0» – не определено; 
                                                                    «1» – Natural Person; 
                                                                    «3» – Algorithm 
                                                                 */
 
    LUACPP_TABLE_FIELD(executing_trader_short_code, unsigned int) // Краткий идентификатор трейдера, исполнившего заявку, по которой совершена сделка 
    LUACPP_TABLE_FIELD(waiver_flag, unsigned int) /* Признак того, что транзакция совершена по правилам пре-трейда. Возможные значения битовых флагов: 
                                                     бит 0 (0x1) – RFPT; 
                                                     бит 1 (0x2) – NLIQ; 
                                                     бит 2 (0x4) – OILQ; 
                                                     бит 3 (0x8) – PRC; 
                                                     бит 4 (0x10)– SIZE; 
                                                     бит 5 (0x20) – ILQD 
                                                  */
 
    LUACPP_TABLE_FIELD(mleg_base_sid, unsigned int) // Идентификатор базового инструмента на сервере для multileg-инструментов  
    LUACPP_TABLE_FIELD(side_qualifier, unsigned int) /* Квалификатор операции. Возможные значения: 
                                                        «0» – не определено; 
                                                        «1» – Buy; 
                                                        «2» – Sell; 
                                                        «3» – Sell short; 
                                                        «4» – Sell short exempt; 
                                                        «5» – Sell undiclosed 
                                                     */
 
    LUACPP_TABLE_FIELD(otc_post_trade_indicator, unsigned int) /* OTC post-trade индикатор. Возможные значения битовых флагов: 
                                                                  бит 0 (0x1) – Benchmark; 
                                                                  бит 1 (0x2) – Agency cross; 
                                                                  бит 2 (0x4) – Large in scale; 
                                                                  бит 3 (0x8) – Illiquid instrument; 
                                                                  бит 4 (0x10) – Above specified size; 
                                                                  бит 5 (0x20) – Cancellations; 
                                                                  бит 6 (0x40) – Amendments; 
                                                                  бит 7 (0x80) – Special dividend; 
                                                                  бит 8 (0x100) – Price improvement; 
                                                                  бит 9 (0x200) – Duplicative; 
                                                                  бит 10 (0x400) – Not contributing to the price discovery process; 
                                                                  бит 11 (0x800) – Package; 
                                                                  бит 12 (0x1000) – Exchange for Physical 
                                                               */
 
    LUACPP_TABLE_FIELD(capacity, unsigned int) /* Роль в исполнении заявки. Возможные значения: 
                                                  «0» – не определено; 
                                                  «1» – Agent; 
                                                  «2» – Principal; 
                                                  «3» – Riskless principal; 
                                                  «4» – CFG give up; 
                                                  «5» – Cross as agent; 
                                                  «6» – Matched principal; 
                                                  «7» – Proprietary; 
                                                  «8» – Individual; 
                                                  «9» – Agent for other member; 
                                                  «10» – Mixed; 
                                                  «11» – Market maker
                                               */
 
    LUACPP_TABLE_FIELD(cross_rate, double) // Кросс-курс валюты цены сделки к валюте расчетов по сделке 

    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::trades)

// stop_orders "Стоп-заявки"
// Object name in qlua.chm: stop_order "Таблица с параметрами стоп-заявки"
//
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(stop_orders)

    LUACPP_TABLE_FIELD(order_num, std::string) // Регистрационный номер стоп-заявки на сервере QUIK
    LUACPP_TABLE_FIELD(ordertime, unsigned int) // Время выставления  
    LUACPP_TABLE_FIELD(flags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(brokerref, std::string) // Комментарий, обычно: <код клиента>/<номер поручения> 
    LUACPP_TABLE_FIELD(firmid, std::string) // Идентификатор дилера  
    LUACPP_TABLE_FIELD(account, std::string) // Торговый счет  
    LUACPP_TABLE_FIELD(condition, unsigned int) /* Направленность стоп-цены. Возможные значения: 
                                                   «4» – «<=», 
                                                   «5» – «>=» 
                                                */
 
    LUACPP_TABLE_FIELD(condition_price, double) // Стоп-цена  
    LUACPP_TABLE_FIELD(price, double) // Цена  
    LUACPP_TABLE_FIELD(qty, unsigned int) // Количество в лотах  
    LUACPP_TABLE_FIELD(linkedorder, unsigned int) // Номер заявки в торговой системе, зарегистрированной по наступлению условия стоп-цены  
    LUACPP_TABLE_FIELD(expiry, int) // Дата окончания срока действия заявки 
    LUACPP_TABLE_FIELD(trans_id, unsigned int) // Идентификатор транзакции  
    LUACPP_TABLE_FIELD(client_code, std::string) // Код клиента  
    LUACPP_TABLE_FIELD(co_order_num, std::string) // Связанная заявка  
    LUACPP_TABLE_FIELD(co_order_price, double) // Цена связанной заявки  
    LUACPP_TABLE_FIELD(stop_order_type, unsigned int) /* Вид стоп заявки. Возможные значения: 
                                                         «1» – стоп-лимит; 
                                                         «2» – условие по другому инструменту; 
                                                         «3» – со связанной заявкой; 
                                                         «6» – тейк-профит; 
                                                         «7» – стоп-лимит по исполнению активной заявки; 
                                                         «8» – тейк-профит по исполнению активной заявки; 
                                                         «9» - тейк-профит и стоп-лимит 
                                                      */
 
    LUACPP_TABLE_FIELD(orderdate, int) // Дата выставления  
    LUACPP_TABLE_FIELD(alltrade_num, std::string) // Сделка условия  
    LUACPP_TABLE_FIELD(stopflags, unsigned int) // Набор битовых флагов  
    LUACPP_TABLE_FIELD(offset, double) // Отступ от min/max  
    LUACPP_TABLE_FIELD(spread, double) // Защитный спред  
    LUACPP_TABLE_FIELD(balance, unsigned int) // Активное количество  
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор пользователя  
    LUACPP_TABLE_FIELD(filled_qty, unsigned int) // Исполненное количество  
    LUACPP_TABLE_FIELD(withdraw_time, int) // Время снятия заявки  
    LUACPP_TABLE_FIELD(condition_price2, double) // Стоп-лимит цена (для заявок типа «Тэйк-профит и стоп-лимит»)  
    LUACPP_TABLE_FIELD(active_from_time, int) // Время начала периода действия заявки типа «Тэйк-профит и стоп-лимит»  
    LUACPP_TABLE_FIELD(active_to_time, int) // Время окончания периода действия заявки типа «Тэйк-профит и стоп-лимит»  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код инструмента заявки  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса заявки  
    LUACPP_TABLE_FIELD(condition_sec_code, std::string) // Код инструмента стоп-цены  
    LUACPP_TABLE_FIELD(condition_class_code, std::string) // Код класса стоп-цены  
    LUACPP_TABLE_FIELD(canceled_uid, unsigned int) // Идентификатор пользователя, снявшего стоп-заявку 
    QLUACPP_DATETIME_TABLE_FIELD(order_date_time) // Время выставления стоп-заявки
    QLUACPP_DATETIME_TABLE_FIELD(withdraw_datetime) // Время снятия стоп-заявки
    QLUACPP_DATETIME_TABLE_FIELD(activation_date_time) // Дата и время активации стоп-заявки 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::stop_orders)

// neg_deals "Заявки на внебиржевые сделки"
// Object names in qlua.chm: "Таблица с параметрами заявки на внебиржевые сделки"
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
                                                   «8» – «Количество» 
                                                */

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
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код инструмента  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса  
    LUACPP_TABLE_FIELD(bank_acc_id, std::string) // Идентификатор расчетного счета/кода в клиринговой организации  
    LUACPP_TABLE_FIELD(withdraw_date, int) // Дата снятия адресной заявки в формате «ГГГГММДД»  
    LUACPP_TABLE_FIELD(linkedorder, unsigned int) // Номер предыдущей заявки. Отображается с точностью «0»  
    QLUACPP_DATETIME_TABLE_FIELD(activation_date_time) // Дата и время активации заявки 
    QLUACPP_DATETIME_TABLE_FIELD(withdraw_date_time) // Дата и время снятия заявки 
    QLUACPP_DATETIME_TABLE_FIELD(date_time) // Дата и время заявки
    LUACPP_TABLE_FIELD(lseccode, std::string) // Приоритетное обеспечение 
    LUACPP_TABLE_FIELD(canceled_uid, unsigned int) // UID снявшего заявку 
    LUACPP_TABLE_FIELD(system_ref, std::string) // Системная ссылка 
    LUACPP_TABLE_FIELD(price_currency, std::string) // Валюта, в которой указана цена заявки 
    LUACPP_TABLE_FIELD(order_exchange_code, std::string) // Биржевой номер заявки 
    LUACPP_TABLE_FIELD(extref, std::string) // Внешняя ссылка, используется для обратной связи с внешними системами 
    LUACPP_TABLE_FIELD(period, unsigned int) // Период торговой сессии, в которую была подана заявка 
    LUACPP_TABLE_FIELD(client_qualifier, unsigned int) /* Квалификатор клиента, от имени которого выставлена заявка. Возможные значения: 
                                                          «0» – не определено; 
                                                          «1» – Natural Person; 
                                                          «3» – Legal Entity 
                                                       */
 
    LUACPP_TABLE_FIELD(client_short_code, unsigned int) // Краткий идентификатор клиента, от имени которого выставлена заявка 
    LUACPP_TABLE_FIELD(investment_decision_maker_qualifier, unsigned int) /* Квалификатор принявшего решение о выставлении заявки. Возможные значения: 
                                                                             «0» – не определено; 
                                                                             «1» – Natural Person; 
                                                                             «3» – Algorithm 
                                                                          */
    LUACPP_TABLE_FIELD(investment_decision_maker_short_code, unsigned int) // Краткий идентификатор принявшего решение о выставлении заявки 
    LUACPP_TABLE_FIELD(executing_trader_qualifier, unsigned int) /* Квалификатор трейдера, исполнившего заявку. Возможные значения: 
                                                                    «0» – не определено; 
                                                                    «1» – Natural Person; 
                                                                    «3» – Algorithm 
                                                                 */
    LUACPP_TABLE_FIELD(executing_trader_short_code, unsigned int) // Краткий идентификатор трейдера, исполнившего заявку 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::neg_deals)

// neg_trades "Сделки для исполнения"
// Object names in qlua.chm "Таблица с параметрами сделки для исполнения"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(neg_trades)
    LUACPP_TABLE_FIELD(trade_num, std::string) // Номер сделки  
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
                                                        «2» – «Списать». 
                                                     */
 
    LUACPP_TABLE_FIELD(expected_discount, double) // Дисконт после взноса (%)  
    LUACPP_TABLE_FIELD(expected_quantity, unsigned int) // Количество после взноса  
    LUACPP_TABLE_FIELD(expected_repovalue, double) // Сумма РЕПО после взноса  
    LUACPP_TABLE_FIELD(expected_repo2value, double) // Стоимость выкупа после взноса  
    LUACPP_TABLE_FIELD(expected_return_value, double) // Сумма возврата после взноса  
    LUACPP_TABLE_FIELD(order_num, std::string) // Номер заявки  
    LUACPP_TABLE_FIELD(report_trade_date, int) // Дата заключения  
    LUACPP_TABLE_FIELD(settled, unsigned int) /* Состояние расчетов по сделке. Возможные значения: 
                                                 «1» – «Processed», 
                                                 «2» – «Not processed», 
                                                 «3» – «Is processing». 
                                              */
 
    LUACPP_TABLE_FIELD(clearing_type, unsigned int) /* Тип клиринга. Возможные значения: 
                                                       «1» – «Not set», 
                                                       «2» – «Simple», 
                                                       «3» – «Multilateral». 
                                                    */
 
    LUACPP_TABLE_FIELD(report_comission, double) // Комиссия за отчет  
    LUACPP_TABLE_FIELD(coupon_payment, double) // Купонная выплата  
    LUACPP_TABLE_FIELD(principal_payment, double) // Выплата по основному долгу  
    LUACPP_TABLE_FIELD(principal_payment_date, int) // Дата выплаты по основному долгу  
    LUACPP_TABLE_FIELD(nextdaysettle, int) // Дата следующего дня расчетов  
    LUACPP_TABLE_FIELD(settle_currency, std::string) // Валюта расчетов  
    LUACPP_TABLE_FIELD(sec_code, std::string) // Код инструмента  
    LUACPP_TABLE_FIELD(class_code, std::string) // Код класса  
    LUACPP_TABLE_FIELD(compval, double) // Сумма отступного в валюте сделки 
    LUACPP_TABLE_FIELD(parenttradeno, unsigned int) // Идентификационный номер витринной сделки 
    LUACPP_TABLE_FIELD(bankid, std::string) // Расчетная организация 
    LUACPP_TABLE_FIELD(bankaccid, std::string) // Код позиции 
    LUACPP_TABLE_FIELD(precisebalance, unsigned int) // Количество инструментов к исполнению (в лотах) 
    LUACPP_TABLE_FIELD(confirmtime, int) // Время подтверждения в формате «ЧЧММСС» 
    LUACPP_TABLE_FIELD(ex_flags, unsigned int) /* Расширенные флаги сделки для исполнения. Возможные значения: 
                                                  «1» – «Подтверждена контрагентом»; 
                                                  «2» – «Подтверждена» 
                                               */
    LUACPP_TABLE_FIELD(confirmreport, unsigned int) // Номер поручения 
    LUACPP_TABLE_FIELD(extref, std::string) // Внешняя ссылка, используется для обратной связи с внешними системами 
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
    QLUACPP_DATETIME_TABLE_FIELD(report_date_time) // Дата и время отчета
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
// Объект фигурирует в qlua.chm как acc_bal
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
    LUACPP_TABLE_FIELD(planned_covered, double) // Плановая позиция Т+  
    LUACPP_TABLE_FIELD(firm_use, double) /*  Тип раздела. Возможные значения: 
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

// trans_reply "Таблица с описанием транзакций" (callback)
// Object names in qlua.chm: trans_reply
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(trans_reply)
    LUACPP_TABLE_FIELD(trans_id, unsigned int) // Пользовательский идентификатор транзакции 
    LUACPP_TABLE_FIELD(status, unsigned int) /* Статус транзакции. Возможные значения: 
                                                «0» – транзакция отправлена серверу; 
                                                «1» – транзакция получена на сервер QUIK от клиента; 
                                                «2» – ошибка при передаче транзакции в торговую систему. Так как отсутствует подключение шлюза Московской Биржи, повторно транзакция не отправляется; 
                                                «3» – транзакция выполнена; 
                                                «4» – транзакция не выполнена торговой системой. Более подробное описание ошибки отражается в поле «Сообщение»; 
                                                «5» – транзакция не прошла проверку сервера QUIK по каким-либо критериям. Например, проверку на наличие прав у пользователя на отправку транзакции данного типа; 
                                                «6» – транзакция не прошла проверку лимитов сервера QUIK; 
                                                «10» – транзакция не поддерживается торговой системой; 
                                                «11» – транзакция не прошла проверку правильности электронной цифровой подписи; 
                                                «12» – не удалось дождаться ответа на транзакцию, т.к. истек таймаут ожидания. Может возникнуть при подаче транзакций из QPILE; 
                                                «13» – транзакция отвергнута, так как ее выполнение могло привести к кросс-сделке (т.е. сделке с тем же самым клиентским счетом); 
                                                «14» – транзакция не прошла контроль дополнительных ограничений; 
                                                «15» – транзакция принята после нарушения дополнительных ограничений; 
                                                «16» – транзакция отменена пользователем в ходе проверки дополнительных ограничений */
 
    LUACPP_TABLE_FIELD(result_msg, std::string) // Сообщение
    QLUACPP_DATETIME_TABLE_FIELD(date_time) // Дата и время 
    LUACPP_TABLE_FIELD(uid, unsigned int) // Идентификатор 
    LUACPP_TABLE_FIELD(flags, unsigned int) // Флаги транзакции (временно не используется) 
    LUACPP_TABLE_FIELD(server_trans_id, unsigned int) // Идентификатор транзакции на сервере 
    LUACPP_TABLE_FIELD(order_num, std::optional<std::string>) // Номер заявки *
    LUACPP_TABLE_FIELD(price, std::optional<double>) // Цена *
    LUACPP_TABLE_FIELD(quantity, std::optional<unsigned int>) // Количество *
    LUACPP_TABLE_FIELD(balance, std::optional<unsigned int>) // Остаток *
    LUACPP_TABLE_FIELD(firm_id, std::optional<std::string>) // Идентификатор фирмы *
    LUACPP_TABLE_FIELD(account, std::optional<std::string>) // Торговый счет *
    LUACPP_TABLE_FIELD(client_code, std::optional<std::string>) // Код клиента * 
    LUACPP_TABLE_FIELD(brokerref, std::optional<std::string>) // Поручение *
    LUACPP_TABLE_FIELD(class_code, std::optional<std::string>) // Код класса *
    LUACPP_TABLE_FIELD(sec_code, std::optional<std::string>) // Код бумаги *
    LUACPP_TABLE_FIELD(exchange_code, std::optional<std::string>) /* Биржевой номер заявки *
                                                                   * - параметр может иметь значение nil
                                                                   */
    LUACPP_TABLE_FIELD(error_code, int) // Числовой код ошибки. Значение равно «0», если транзакция выполнена успешно 
    LUACPP_TABLE_FIELD(error_source, unsigned int) /* Источник сообщения. Возможные значения: 
                                                      «1» – Торговая система; 
                                                      «2» – Сервер QUIK; 
                                                      «3» – Библиотека расчёта лимитов; 
                                                      «4» – Шлюз торговой системы */
    
    LUACPP_TABLE_FIELD(first_ordernum, double) // Номер первой заявки, которая выставлялась при автоматической замене кода клиента. Используется, если на сервере QUIK настроена замена кода клиента для кросс-сделки
    QLUACPP_DATETIME_TABLE_FIELD(gate_reply_time) // Дата и время получения шлюзом ответа на транзакцию
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::trans_reply)

namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(candle)
    LUACPP_TABLE_FIELD(open, double) // Цена открытия  
    LUACPP_TABLE_FIELD(close, double) // Цена закрытия  
    LUACPP_TABLE_FIELD(high, double) // Максимальная цена сделки  
    LUACPP_TABLE_FIELD(low, double) // Минимальная цена сделки  
    LUACPP_TABLE_FIELD(volume, double) // Объем последней сделки
    QLUACPP_DATETIME_TABLE_FIELD(datetime) // Формат даты и времени  
    LUACPP_TABLE_FIELD(doesExist, unsigned int) /* Признак расчета индикатора при наличии свечки. Возможные значения:
                                                   «0» – индикатор не рассчитан,
                                                   «1» – индикатор рассчитан */
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::candle)

#define QLUACPP_DETAIL_TABLE_NAME(NAME)                 \
  template <>                                           \
  struct name_for_type<::qlua::table::NAME> {           \
    static const char* value() { return ""#NAME; }      \
  };                                                    \
  
namespace qlua {
  namespace table {
    namespace detail {
      template <typename Table>
      struct name_for_type;


      QLUACPP_DETAIL_TABLE_NAME(firms);
      QLUACPP_DETAIL_TABLE_NAME(classes);
      QLUACPP_DETAIL_TABLE_NAME(securities);
      QLUACPP_DETAIL_TABLE_NAME(trade_accounts);
      QLUACPP_DETAIL_TABLE_NAME(client_codes);
      QLUACPP_DETAIL_TABLE_NAME(account_positions);
      QLUACPP_DETAIL_TABLE_NAME(orders);
      QLUACPP_DETAIL_TABLE_NAME(futures_client_holding);
      QLUACPP_DETAIL_TABLE_NAME(futures_client_limits);
      QLUACPP_DETAIL_TABLE_NAME(all_trades);
      QLUACPP_DETAIL_TABLE_NAME(money_limits);
      QLUACPP_DETAIL_TABLE_NAME(depo_limits);
      QLUACPP_DETAIL_TABLE_NAME(trades);
      QLUACPP_DETAIL_TABLE_NAME(stop_orders);
      QLUACPP_DETAIL_TABLE_NAME(neg_deals);
      QLUACPP_DETAIL_TABLE_NAME(neg_trades);
      QLUACPP_DETAIL_TABLE_NAME(neg_deal_reports);
      QLUACPP_DETAIL_TABLE_NAME(firm_holding);
      QLUACPP_DETAIL_TABLE_NAME(account_balance);
      QLUACPP_DETAIL_TABLE_NAME(ccp_holdings);
      QLUACPP_DETAIL_TABLE_NAME(rm_holdings);
    }
  }
}

#undef QLUACPP_DETAIL_TABLE_NAME
