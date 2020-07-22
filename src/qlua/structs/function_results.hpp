#pragma once

// depo_limits_getDepo (table returned from getDepo API)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(depo_limits_getDepo)
    LUACPP_TABLE_FIELD(depo_limit_locked_buy_value, double) // Стоимость ценных бумаг, заблокированных на покупку 
    LUACPP_TABLE_FIELD(depo_current_balance, double) // Текущий остаток по бумагам 
    LUACPP_TABLE_FIELD(depo_limit_locked_buy, double) // Количество лотов ценных бумаг, заблокированных на покупку 
    LUACPP_TABLE_FIELD(depo_limit_locked, double) // Заблокированное Количество лотов ценных бумаг 
    LUACPP_TABLE_FIELD(depo_limit_available, double) // Доступное количество ценных бумаг 
    LUACPP_TABLE_FIELD(depo_current_limit, double) // Текущий лимит по бумагам 
    LUACPP_TABLE_FIELD(depo_open_balance, double) // Входящий остаток по бумагам 
    LUACPP_TABLE_FIELD(depo_open_limit, double) // Входящий лимит по бумагам 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::depo_limits_getDepo)

// money_limits_getMoney (table returned from getMoney API)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(money_limits_getMoney)
    LUACPP_TABLE_FIELD(money_open_limit, double) // Входящий лимит по денежным средствам 
    LUACPP_TABLE_FIELD(money_limit_locked_nonmarginal_value, double) // Стоимость немаржинальных бумаг в заявках на покупку 
    LUACPP_TABLE_FIELD(money_limit_locked, double) // Заблокированное в заявках на покупку количество денежных средств 
    LUACPP_TABLE_FIELD(money_open_balance, double) // Входящий остаток по денежным средствам 
    LUACPP_TABLE_FIELD(money_current_limit, double) // Текущий лимит по денежным средствам
    LUACPP_TABLE_FIELD(money_current_balance, double) // Текущий остаток по денежным средствам
    LUACPP_TABLE_FIELD(money_limit_available, double) // Доступное количество денежных средств
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::money_limits_getMoney)

/*
// level2_quotes_record
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(level2_quotes_record)
    LUACPP_TABLE_FIELD(price, std::string)
    LUACPP_TABLE_FIELD(quantity, std::string)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::level2_quotes_record)

// level2_quotes (table returned from getQuoteLevel2)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(level2_quotes)
    LUACPP_TABLE_FIELD(bid_count, std::string) // Количество котировок покупки. При отсутствии спроса возвращается значение «0» 
    LUACPP_TABLE_FIELD(offer_count, std::string) // Количество котировок продажи. При отсутствии предложения возвращается значение «0» 
    LUACPP_TABLE_FIELD(bid, ::std::vector<level2_quotes_record>) // Котировки спроса (покупки). При отсутствии спроса возвращается пустая строка 
    LUACPP_TABLE_FIELD(offer, ::std::vector<level2_quotes_record>) // Котировки предложений (продажи). При отсутствии предложения возвращается пустая строка 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::level2_quotes)
*/
// portfolio_info_getPortfolioInfo (table returned from getPortfolioInfo)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(portfolio_info_getPortfolioInfo)
    LUACPP_TABLE_FIELD(is_leverage, std::string) /*Признак использования схемы кредитования с контролем текущей стоимости активов. Возможные значения: 
                                                   «МЛ» – используется схема ведения позиции «по плечу», «плечо» рассчитано по значению Входящего лимита, 
                                                   «МП» – используется схема ведения позиции «по плечу», «плечо» указано явным образом, 
                                                   «МОП» – используется схема ведения позиции «лимит на открытую позицию»; 
                                                   «МД» – используется схема ведения позиции «по дисконтам»; 
                                                   «C» – используется схема ведения позиций «срочный рынок». Для клиентов срочного рынка без единой денежной позиции; 
                                                   <пусто> – используется схема ведения позиции «по лимитам» 
                                                   Тип клиента */
    LUACPP_TABLE_FIELD(in_assets, std::string) // Оценка собственных средств клиента до начала торгов Вход. активы 
    LUACPP_TABLE_FIELD(leverage, std::string) // Плечо. Если не задано явно, то отношение Входящего лимита к Входящим активам Плечо 
    LUACPP_TABLE_FIELD(open_limit, std::string) // Оценка максимальной величины заемных средств до начала торгов Вход. лимит 
    LUACPP_TABLE_FIELD(val_short, std::string) // Оценка стоимости коротких позиций. Значение всегда отрицательное Шорты 
    LUACPP_TABLE_FIELD(val_long, std::string) // Оценка стоимости длинных позиций Лонги 
    LUACPP_TABLE_FIELD(val_long_margin, std::string) // Оценка стоимости длинных позиций по маржинальным бумагам, принимаемым в обеспечение Лонги МО 
    LUACPP_TABLE_FIELD(val_long_asset, std::string) // Оценка стоимости длинных позиций по немаржинальным бумагам, принимаемым в обеспечение Лонги О 
    LUACPP_TABLE_FIELD(assets, std::string) // Оценка собственных средств клиента по текущим позициям и ценам Тек. активы 
    LUACPP_TABLE_FIELD(cur_leverage, std::string) // Текущее плечо Тек.плечо 
      LUACPP_TABLE_FIELD(margin, std::string) // Уровень маржи, в процентах Ур. маржи 
      LUACPP_TABLE_FIELD(lim_all, std::string) // Текущая оценка максимальной величины заемных средств Тек. лимит 
      LUACPP_TABLE_FIELD(av_lim_all, std::string) // Оценка величины заемных средств, доступных для дальнейшего открытия позиций ДостТекЛимит 
      LUACPP_TABLE_FIELD(locked_buy, std::string) // Оценка стоимости активов в заявках на покупку Блок. покупка 
      LUACPP_TABLE_FIELD(locked_buy_margin, std::string) // Оценка стоимости активов в заявках на покупку маржинальных бумаг, принимаемых в обеспечение Блок. пок. маржин. 
      LUACPP_TABLE_FIELD(locked_buy_asset, std::string) // Оценка стоимости активов в заявках на покупку немаржинальных бумаг, принимаемых в обеспечение Блок.пок. обесп. 
    LUACPP_TABLE_FIELD(locked_sell, std::string) // Оценка стоимости активов в заявках на продажу маржинальных бумаг Блок. продажа 
    LUACPP_TABLE_FIELD(locked_value_coef, std::string) // Оценка стоимости активов в заявках на покупку немаржинальных бумаг Блок. пок. немарж. 
    LUACPP_TABLE_FIELD(in_all_assets, std::string) // Оценка стоимости всех позиций клиента в ценах закрытия предыдущей торговой сессии, включая позиции по немаржинальным бумагам ВходСредства 
    LUACPP_TABLE_FIELD(all_assets, std::string) // Текущая оценка стоимости всех позиций клиента ТекСредства 
    LUACPP_TABLE_FIELD(profit_loss, std::string) // Абсолютная величина изменения стоимости всех позиций клиента Прибыль/убытки 
      LUACPP_TABLE_FIELD(rate_change, std::string) // Относительная величина изменения стоимости всех позиций клиента ПроцИзмен 
    LUACPP_TABLE_FIELD(lim_buy, std::string) // Оценка денежных средств, доступных для покупки маржинальных бумаг На покупку 
    LUACPP_TABLE_FIELD(lim_sell, std::string) // Оценка стоимости маржинальных бумаг, доступных для продажи На продажу 
    LUACPP_TABLE_FIELD(lim_non_margin, std::string) // Оценка денежных средств, доступных для покупки немаржинальных бумаг НаПокупНеМаржин 
    LUACPP_TABLE_FIELD(lim_buy_asset, std::string) // Оценка денежных средств, доступных для покупки бумаг, принимаемых в обеспечение НаПокупОбесп 
      LUACPP_TABLE_FIELD(val_short_net, std::string) // Оценка стоимости коротких позиций. При расчете не используется коэффициент дисконтирования ** Шорты (нетто) 
    LUACPP_TABLE_FIELD(val_long_net, std::string) // Оценка стоимости длинных позиций. При расчете не используется коэффициент дисконтирования ** Лонги (нетто) 
      LUACPP_TABLE_FIELD(total_money_bal, std::string) // Сумма остатков по денежным средствам по всем лимитам, без учета средств, заблокированных под исполнение обязательств, выраженная в выбранной валюте расчета Сумма ден. остатков 
    LUACPP_TABLE_FIELD(total_locked_money, std::string) // Cумма заблокированных средств со всех денежных лимитов клиента, пересчитанная в валюту расчетов через кросс-курсы на сервере Суммарно заблок. 
    LUACPP_TABLE_FIELD(haircuts, std::string) // Сумма дисконтов стоимости длинных (только по бумагам обеспечения) и коротких бумажных позиций, дисконтов корреляции между инструментами, а также дисконтов на задолженности по валютам, не покрытые бумажным обеспечением в этих же валютах Сумма дисконтов 
    LUACPP_TABLE_FIELD(assets_without_hc, std::string) // Суммарная величина денежных остатков, стоимости длинных позиций по бумагам обеспечения и стоимости коротких позиций, без учета дисконтирующих коэффициентов, без учета неттинга стоимости бумаг в рамках объединенной бумажной позиции и без учета корреляции между инструментами ТекАктБезДиск 
    LUACPP_TABLE_FIELD(status_coef, std::string) // Отношение суммы дисконтов к текущим активам без учета дисконтов Статус счета 
    LUACPP_TABLE_FIELD(varmargin, std::string) // Текущая вариационная маржа по позициям клиента, по всем инструментам Вариац. маржа 
    LUACPP_TABLE_FIELD(go_for_positions, std::string) // Размер денежных средств, уплаченных под все открытые позиции на срочном рынке ГО поз. 
      LUACPP_TABLE_FIELD(go_for_orders, std::string) // Оценка стоимости активов в заявках на срочном рынке ГО заяв. 
      LUACPP_TABLE_FIELD(rate_futures, std::string) // Отношение ликвидационной стоимости портфеля к ГО по срочному рынку Активы/ГО 
      LUACPP_TABLE_FIELD(is_qual_client, std::string) // Признак «квалифицированного» клиента, которому разрешено кредитование заемными средствами с плечом 1:3. Возможные значения: «ПовышУрРиска» – квалифицированный, <пусто> – нет ПовышУрРиска 
      LUACPP_TABLE_FIELD(is_futures, std::string) // Счет клиента на FORTS, в случае наличия объединенной позиции, иначе поле остается пустым Сроч. счет 
      LUACPP_TABLE_FIELD(curr_tag, std::string) // Актуальные текущие параметры расчета для данной строки в формате «<Валюта>-<Тег расчётов>». Пример: «SUR-EQTV» Парам
    LUACPP_STATIC_TABLE_END()
      }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::portfolio_info_getPortfolioInfo)

// portfolio_info_getPortfolioInfoEx (table returned from getPortfolioInfoEx)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(portfolio_info_getPortfolioInfoEx)
    LUACPP_TABLE_FIELD(is_leverage, std::string) /*Признак использования схемы кредитования с контролем текущей стоимости активов. Возможные значения: 
                                                   «МЛ» – используется схема ведения позиции «по плечу», «плечо» рассчитано по значению Входящего лимита, 
                                                   «МП» – используется схема ведения позиции «по плечу», «плечо» указано явным образом, 
                                                   «МОП» – используется схема ведения позиции «лимит на открытую позицию»; 
                                                   «МД» – используется схема ведения позиции «по дисконтам»; 
                                                   «C» – используется схема ведения позиций «срочный рынок». Для клиентов срочного рынка без единой денежной позиции; 
                                                   <пусто> – используется схема ведения позиции «по лимитам» 
                                                   Тип клиента */
    LUACPP_TABLE_FIELD(in_assets, std::string) // Оценка собственных средств клиента до начала торгов Вход. активы 
    LUACPP_TABLE_FIELD(leverage, std::string) // Плечо. Если не задано явно, то отношение Входящего лимита к Входящим активам Плечо 
    LUACPP_TABLE_FIELD(open_limit, std::string) // Оценка максимальной величины заемных средств до начала торгов Вход. лимит 
    LUACPP_TABLE_FIELD(val_short, std::string) // Оценка стоимости коротких позиций. Значение всегда отрицательное Шорты 
    LUACPP_TABLE_FIELD(val_long, std::string) // Оценка стоимости длинных позиций Лонги 
    LUACPP_TABLE_FIELD(val_long_margin, std::string) // Оценка стоимости длинных позиций по маржинальным бумагам, принимаемым в обеспечение Лонги МО 
    LUACPP_TABLE_FIELD(val_long_asset, std::string) // Оценка стоимости длинных позиций по немаржинальным бумагам, принимаемым в обеспечение Лонги О 
    LUACPP_TABLE_FIELD(assets, std::string) // Оценка собственных средств клиента по текущим позициям и ценам Тек. активы 
    LUACPP_TABLE_FIELD(cur_leverage, std::string) // Текущее плечо Тек.плечо 
    LUACPP_TABLE_FIELD(margin, std::string) // Уровень маржи, в процентах Ур. маржи 
      LUACPP_TABLE_FIELD(lim_all, std::string) // Текущая оценка максимальной величины заемных средств Тек. лимит 
      LUACPP_TABLE_FIELD(av_lim_all, std::string) // Оценка величины заемных средств, доступных для дальнейшего открытия позиций ДостТекЛимит 
      LUACPP_TABLE_FIELD(locked_buy, std::string) // Оценка стоимости активов в заявках на покупку Блок. покупка 
      LUACPP_TABLE_FIELD(locked_buy_margin, std::string) // Оценка стоимости активов в заявках на покупку маржинальных бумаг, принимаемых в обеспечение Блок. пок. маржин. 
      LUACPP_TABLE_FIELD(locked_buy_asset, std::string) // Оценка стоимости активов в заявках на покупку немаржинальных бумаг, принимаемых в обеспечение Блок.пок. обесп. 
    LUACPP_TABLE_FIELD(locked_sell, std::string) // Оценка стоимости активов в заявках на продажу маржинальных бумаг Блок. продажа 
    LUACPP_TABLE_FIELD(locked_value_coef, std::string) // Оценка стоимости активов в заявках на покупку немаржинальных бумаг Блок. пок. немарж. 
    LUACPP_TABLE_FIELD(in_all_assets, std::string) // Оценка стоимости всех позиций клиента в ценах закрытия предыдущей торговой сессии, включая позиции по немаржинальным бумагам ВходСредства 
    LUACPP_TABLE_FIELD(all_assets, std::string) // Текущая оценка стоимости всех позиций клиента ТекСредства 
    LUACPP_TABLE_FIELD(profit_loss, std::string) // Абсолютная величина изменения стоимости всех позиций клиента Прибыль/убытки 
      LUACPP_TABLE_FIELD(rate_change, std::string) // Относительная величина изменения стоимости всех позиций клиента ПроцИзмен 
    LUACPP_TABLE_FIELD(lim_buy, std::string) // Оценка денежных средств, доступных для покупки маржинальных бумаг На покупку 
    LUACPP_TABLE_FIELD(lim_sell, std::string) // Оценка стоимости маржинальных бумаг, доступных для продажи На продажу 
    LUACPP_TABLE_FIELD(lim_non_margin, std::string) // Оценка денежных средств, доступных для покупки немаржинальных бумаг НаПокупНеМаржин 
    LUACPP_TABLE_FIELD(lim_buy_asset, std::string) // Оценка денежных средств, доступных для покупки бумаг, принимаемых в обеспечение НаПокупОбесп 
      LUACPP_TABLE_FIELD(val_short_net, std::string) // Оценка стоимости коротких позиций. При расчете не используется коэффициент дисконтирования ** Шорты (нетто) 
    LUACPP_TABLE_FIELD(val_long_net, std::string) // Оценка стоимости длинных позиций. При расчете не используется коэффициент дисконтирования ** Лонги (нетто) 
      LUACPP_TABLE_FIELD(total_money_bal, std::string) // Сумма остатков по денежным средствам по всем лимитам, без учета средств, заблокированных под исполнение обязательств, выраженная в выбранной валюте расчета Сумма ден. остатков 
    LUACPP_TABLE_FIELD(total_locked_money, std::string) // Cумма заблокированных средств со всех денежных лимитов клиента, пересчитанная в валюту расчетов через кросс-курсы на сервере Суммарно заблок. 
    LUACPP_TABLE_FIELD(haircuts, std::string) // Сумма дисконтов стоимости длинных (только по бумагам обеспечения) и коротких бумажных позиций, дисконтов корреляции между инструментами, а также дисконтов на задолженности по валютам, не покрытые бумажным обеспечением в этих же валютах Сумма дисконтов 
    LUACPP_TABLE_FIELD(assets_without_hc, std::string) // Суммарная величина денежных остатков, стоимости длинных позиций по бумагам обеспечения и стоимости коротких позиций, без учета дисконтирующих коэффициентов, без учета неттинга стоимости бумаг в рамках объединенной бумажной позиции и без учета корреляции между инструментами ТекАктБезДиск 
    LUACPP_TABLE_FIELD(status_coef, std::string) // Отношение суммы дисконтов к текущим активам без учета дисконтов Статус счета 
    LUACPP_TABLE_FIELD(varmargin, std::string) // Текущая вариационная маржа по позициям клиента, по всем инструментам Вариац. маржа 
    LUACPP_TABLE_FIELD(go_for_positions, std::string) // Размер денежных средств, уплаченных под все открытые позиции на срочном рынке ГО поз. 
    LUACPP_TABLE_FIELD(go_for_orders, std::string) // Оценка стоимости активов в заявках на срочном рынке ГО заяв. 
    LUACPP_TABLE_FIELD(rate_futures, std::string) // Отношение ликвидационной стоимости портфеля к ГО по срочному рынку Активы/ГО 
    LUACPP_TABLE_FIELD(is_qual_client, std::string) // Признак «квалифицированного» клиента, которому разрешено кредитование заемными средствами с плечом 1:3. Возможные значения: «ПовышУрРиска» – квалифицированный, <пусто> – нет ПовышУрРиска 
    LUACPP_TABLE_FIELD(is_futures, std::string) // Счет клиента на FORTS, в случае наличия объединенной позиции, иначе поле остается пустым Сроч. счет 
    LUACPP_TABLE_FIELD(curr_tag, std::string) // Актуальные текущие параметры расчета для данной строки в формате «<Валюта>-<Тег расчётов>». Пример: «SUR-EQTV» Парам
    
    LUACPP_TABLE_FIELD(init_margin, std::string) // Значение начальной маржи. Заполняется для клиентов типа «МД» Нач.маржа 
    LUACPP_TABLE_FIELD(min_margin, std::string) // Значение минимальной маржи. Заполняется для клиентов типа «МД» Мин.маржа 
    LUACPP_TABLE_FIELD(corrected_margin, std::string) // Значение скорректированной маржи. Заполняется для клиентов типа «МД» Скор.маржа 
    LUACPP_TABLE_FIELD(client_type, std::string) // Тип клиента Тип клиента 
    LUACPP_TABLE_FIELD(portfolio_value, std::string) // Стоимость портфеля. Для клиентов типа «МД» возвращается значение для строк с максимальным видом лимита limit_kind Стоимость портфеля 
    LUACPP_TABLE_FIELD(start_limit_open_pos, std::string) // Лимит открытых позиций на начало дня ЛимОткрПозНачДня 
    LUACPP_TABLE_FIELD(total_limit_open_pos, std::string) // Лимит открытых позиций ЛимОткрПоз 
    LUACPP_TABLE_FIELD(limit_open_pos, std::string) // Планируемые чистые позиции ПланЧистПоз 
    LUACPP_TABLE_FIELD(used_lim_open_pos, std::string) // Текущие чистые позиции ТекЧистПоз 
    LUACPP_TABLE_FIELD(acc_var_margin, std::string) // Накопленная вариационная маржа НакопВарМаржа 
    LUACPP_TABLE_FIELD(cl_var_margin, std::string) // Вариационная маржа по итогам промклиринга ВарМаржаПромклир. 
    LUACPP_TABLE_FIELD(opt_liquid_cost, std::string) // Ликвидационная стоимость опционов ЛиквСтоимОпционов 
    LUACPP_TABLE_FIELD(fut_asset, std::string) // Сумма оценки средств клиента на срочном рынке СумАктивовНаСрчРынке 
    LUACPP_TABLE_FIELD(fut_total_asset, std::string) // Сумма оценки собственных средств клиента на фондовом и срочном рынках ПолнСтоимостьПортфеля 
    LUACPP_TABLE_FIELD(fut_debt, std::string) // Текущая задолженность на срочном рынке ТекЗадолжНаСрчРынке 
    LUACPP_TABLE_FIELD(fut_rate_asset, std::string) // Достаточность средств Дост. Средств 
    LUACPP_TABLE_FIELD(fut_rate_asset_open, std::string) // Достаточность средств (под открытые позиции) Дост. Средств (ОткрПоз) 
    LUACPP_TABLE_FIELD(fut_rate_go, std::string) // Коэффициент ликвидности ГО КоэффЛикв ГО 
    LUACPP_TABLE_FIELD(planed_rate_go, std::string) // Ожидаемый коэффициент ликвидности ГО Ожид. КоэффЛикв ГО 
    LUACPP_TABLE_FIELD(cash_leverage, std::string) // Cash Leverage Cash Leverage 
    LUACPP_TABLE_FIELD(fut_position_type, std::string) /* Тип позиции на срочном рынке. Возможные значения 
                                                          «0» – нет позиции; 
                                                          «1» – фьючерсы; 
                                                          «2» – опционы; 
                                                          «3» – фьючерсы и опционы
                                                          ТипПозНаСрчРынке */
    LUACPP_TABLE_FIELD(fut_accured_int, std::string) // Накопленный доход с учётом премии по опционам и биржевым сборам НакопДоход
    LUACPP_TABLE_FIELD(rcv1, std::string) // Норматив покрытия риска 1. Рассчитывается как разница параметров «Стоимость портфеля» и «Начальная маржа». Для клиентов типа «МД» и «МД+» НПР1 
    LUACPP_TABLE_FIELD(rcv2, std::string) // Норматив покрытия риска 2. Рассчитывается как разница параметров «Стоимость портфеля» и «Минимальная маржа». Для клиентов типа «МД» и «МД+» НПР2 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::portfolio_info_getPortfolioInfoEx)

// buy_sell_info_getBuySellInfo (table returned from getBuySellInfo)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(buy_sell_info_getBuySellInfo)
    LUACPP_TABLE_FIELD(is_margin_sec, std::string) /* Признак маржинальности инструмента. Возможные значения: 
                                                 «0» – не маржинальная; 
                                                 «1» – маржинальная.*/
    LUACPP_TABLE_FIELD(is_asset_sec, std::string) /* Принадлежность инструмента к списку бумаг, принимаемых в обеспечение. Возможные значения: 
                                                «0» – не принимается в обеспечение; 
                                                «1» – принимается в обеспечение.
                                             */
    LUACPP_TABLE_FIELD(balance, std::string) // Текущая позиция по инструменту, в лотах  
    LUACPP_TABLE_FIELD(can_buy, std::string) // Оценка количества лотов, доступных на покупку по указанной цене * 
    LUACPP_TABLE_FIELD(can_sell, std::string) // Оценка количества лотов, доступных на продажу по указанной цене * 
    LUACPP_TABLE_FIELD(position_valuation, std::string) // Денежная оценка позиции по инструменту по ценам спроса/предложения 
    LUACPP_TABLE_FIELD(value, std::string) // Оценка стоимости позиции по цене последней сделки  
    LUACPP_TABLE_FIELD(open_value, std::string) // Оценка стоимости позиции клиента, рассчитанная по цене закрытия предыдущей торговой сессии  
    LUACPP_TABLE_FIELD(lim_long, std::string) // Предельный размер позиции по данному инструменту, принимаемый в обеспечение длинных позиций  
    LUACPP_TABLE_FIELD(long_coef, std::string) // Коэффициент дисконтирования, применяемый для длинных позиций по данному инструменту  
    LUACPP_TABLE_FIELD(lim_short, std::string) // Предельный размер короткой позиции по данному инструменту  
    LUACPP_TABLE_FIELD(short_coef, std::string) // Коэффициент дисконтирования, применяемый для коротких позиций по данному инструменту  
    LUACPP_TABLE_FIELD(value_coef, std::string) // Оценка стоимости позиции по цене последней сделки, с учетом дисконтирующих коэффициентов  
    LUACPP_TABLE_FIELD(open_value_coef, std::string) // Оценка стоимости позиции клиента, рассчитанная по цене закрытия предыдущей торговой сессии с учетом дисконтирующих коэффициентов  
    LUACPP_TABLE_FIELD(share, std::string) // Процентное отношение стоимости позиции по данному инструменту к стоимости всех активов клиента, рассчитанное по текущим ценам  
    LUACPP_TABLE_FIELD(short_wa_price, std::string) // Средневзвешенная стоимость коротких позиций по инструментам  
    LUACPP_TABLE_FIELD(long_wa_price, std::string) // Средневзвешенная стоимость длинных позиций по инструментам  
    LUACPP_TABLE_FIELD(profit_loss, std::string) // Разница между средневзвешенной ценой приобретения бумаг и их рыночной оценки  
    LUACPP_TABLE_FIELD(spread_hc, std::string) // Коэффициент корреляции между инструментами  
    LUACPP_TABLE_FIELD(can_buy_own, std::string) // Максимально возможное количество бумаг в заявке на покупку этого инструмента на этом классе на собственные средства клиента, исходя из цены лучшего предложения  
    LUACPP_TABLE_FIELD(can_sell_own, std::string) // Максимально возможное количество бумаг в заявке на продажу этого инструмента на этом классе из собственных активов клиента, исходя из цены лучшего спроса
    LUACPP_STATIC_TABLE_END();
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::buy_sell_info_getBuySellInfo)

// buy_sell_info_getBuySellInfoEx (table returned from getBuySellInfoEx)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(buy_sell_info_getBuySellInfoEx)
    LUACPP_TABLE_FIELD(is_margin_sec, std::string) /* Признак маржинальности инструмента. Возможные значения: 
                                                 «0» – не маржинальная; 
                                                 «1» – маржинальная.*/
    LUACPP_TABLE_FIELD(is_asset_sec, std::string) /* Принадлежность инструмента к списку бумаг, принимаемых в обеспечение. Возможные значения: 
                                                «0» – не принимается в обеспечение; 
                                                «1» – принимается в обеспечение.
                                             */
    LUACPP_TABLE_FIELD(balance, std::string) // Текущая позиция по инструменту, в лотах  
    LUACPP_TABLE_FIELD(can_buy, std::string) // Оценка количества лотов, доступных на покупку по указанной цене * 
    LUACPP_TABLE_FIELD(can_sell, std::string) // Оценка количества лотов, доступных на продажу по указанной цене * 
    LUACPP_TABLE_FIELD(position_valuation, std::string) // Денежная оценка позиции по инструменту по ценам спроса/предложения 
    LUACPP_TABLE_FIELD(value, std::string) // Оценка стоимости позиции по цене последней сделки  
    LUACPP_TABLE_FIELD(open_value, std::string) // Оценка стоимости позиции клиента, рассчитанная по цене закрытия предыдущей торговой сессии  
    LUACPP_TABLE_FIELD(lim_long, std::string) // Предельный размер позиции по данному инструменту, принимаемый в обеспечение длинных позиций  
    LUACPP_TABLE_FIELD(long_coef, std::string) // Коэффициент дисконтирования, применяемый для длинных позиций по данному инструменту  
    LUACPP_TABLE_FIELD(lim_short, std::string) // Предельный размер короткой позиции по данному инструменту  
    LUACPP_TABLE_FIELD(short_coef, std::string) // Коэффициент дисконтирования, применяемый для коротких позиций по данному инструменту  
    LUACPP_TABLE_FIELD(value_coef, std::string) // Оценка стоимости позиции по цене последней сделки, с учетом дисконтирующих коэффициентов  
    LUACPP_TABLE_FIELD(open_value_coef, std::string) // Оценка стоимости позиции клиента, рассчитанная по цене закрытия предыдущей торговой сессии с учетом дисконтирующих коэффициентов  
    LUACPP_TABLE_FIELD(share, std::string) // Процентное отношение стоимости позиции по данному инструменту к стоимости всех активов клиента, рассчитанное по текущим ценам  
    LUACPP_TABLE_FIELD(short_wa_price, std::string) // Средневзвешенная стоимость коротких позиций по инструментам  
    LUACPP_TABLE_FIELD(long_wa_price, std::string) // Средневзвешенная стоимость длинных позиций по инструментам  
    LUACPP_TABLE_FIELD(profit_loss, std::string) // Разница между средневзвешенной ценой приобретения бумаг и их рыночной оценки  
    LUACPP_TABLE_FIELD(spread_hc, std::string) // Коэффициент корреляции между инструментами  
    LUACPP_TABLE_FIELD(can_buy_own, std::string) // Максимально возможное количество бумаг в заявке на покупку этого инструмента на этом классе на собственные средства клиента, исходя из цены лучшего предложения  
    LUACPP_TABLE_FIELD(can_sell_own, std::string) // Максимально возможное количество бумаг в заявке на продажу этого инструмента на этом классе из собственных активов клиента, исходя из цены лучшего спроса

    LUACPP_TABLE_FIELD(limit_kind, int) // Вид лимита. Возможные значения: положительные целые числа, начиная с «0», соответствующие видам лимитов из таблицы «Лимиты по бумагам»: «0» – T0, «1» – T1, «2» – T2 и т.д.  
    LUACPP_TABLE_FIELD(d_long, std::string) // Эффективный начальный дисконт для длинной позиции. Заполняется для клиентов типа «МД» 
    LUACPP_TABLE_FIELD(d_min_long, std::string) // Эффективный минимальный дисконт для длинной позиции. Заполняется для клиентов типа «МД» 
    LUACPP_TABLE_FIELD(d_short, std::string) // Эффективный начальный дисконт для короткой позиции. Заполняется для клиентов типа «МД» 
    LUACPP_TABLE_FIELD(d_min_short, std::string) // Эффективный минимальный дисконт для короткой позиции. Заполняется для клиентов типа «МД» 
    LUACPP_TABLE_FIELD(client_type, std::string) // Тип клиента 
    LUACPP_TABLE_FIELD(is_long_allowed, std::string) /* Признак того, является ли бумага разрешенной для покупки на заемные средства. Возможные значения: 
                                                   «1» – разрешена, «0» – не разрешена. 
                                                   Заполняется для клиентов типа «МД» */
    LUACPP_TABLE_FIELD(is_short_allowed, std::string) /* Признак того, является ли бумага разрешенной для продажи на заемные средства. Возможные значения: 
                                                    «1» – разрешена, «0» – не разрешена. 
                                                    Заполняется для клиентов типа «МД» */
    
    LUACPP_STATIC_TABLE_END();
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::buy_sell_info_getBuySellInfoEx)

// candle_time (Returned by Функции O, H, L, C, V, T)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(candle_time)
    LUACPP_TABLE_FIELD(year, unsigned int)
    LUACPP_TABLE_FIELD(month, unsigned int)
    LUACPP_TABLE_FIELD(day, unsigned int)
    LUACPP_TABLE_FIELD(week_day, unsigned int)
    LUACPP_TABLE_FIELD(hour, unsigned int)
    LUACPP_TABLE_FIELD(min, unsigned int)
    LUACPP_TABLE_FIELD(sec, unsigned int)
    LUACPP_TABLE_FIELD(ms, unsigned int)
    LUACPP_TABLE_FIELD(count, unsigned int) // количество тиковых интервалов в секунду. Может принимать значения от «1» до «10000» включительно.
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::candle_time)

// TODO: Make dynamic return value
// current_trades_getParamEx (returned by getParamEx, getParamEx2)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(current_trades_getParamEx)
    LUACPP_TABLE_FIELD(param_type, unsigned int) /* Тип данных параметра, используемый в Таблице текущих торгов. Возможные значения: 
                                              «1» - DOUBLE;
                                              «2» - LONG; 
                                              «3» - CHAR; 
                                              «4» - перечислимый тип; 
                                              «5» - время; 
                                              «6» - дата */
 
    LUACPP_TABLE_FIELD(param_value, double) // Значение параметра. Для param_type = 3 значение параметра равно «0», в остальных случаях – числовое представление. Для перечислимых типов значение равно порядковому значению перечисления  
    LUACPP_TABLE_FIELD(param_image, std::string) // Строковое значение параметра, аналогичное его представлению в таблице. В строковом представлении учитываются разделители разрядов, разделители целой и дробной части. Для перечислимых типов выводятся соответствующие им строковые значения  
    LUACPP_TABLE_FIELD(result, unsigned int) /* Результат выполнения операции. Возможные значения: 
                                          «0» - ошибка; 
                                          «1» - параметр найден */

    // Вызов param_value() с результатом STRING для тех случаев, когда в param_type Quik ошибочно возвращает DOUBLE/LONG

    struct param_value_as_string_type_policy :
    public ::lua::detail::table_field_policy_base<const char*, std::string> {
      using base_type = ::lua::detail::table_field_policy_base<const char*, std::string>;

      static inline read_type get_unsafe(::lua::state s, int idx)  {
        return base_type::get_unsafe(s, idx, "param_value");
      }

      static inline void apply_unsafe(::lua::state s, int idx, std::function<void(const lua::state&, int)> f) {
        base_type::apply_unsafe(s, idx, f, "param_value");
      }

      static inline void set(::lua::state s, int idx, const std::string& value)   {
        base_type::set(s, idx, value, "param_value");
      }
    };
    ::lua::entity<param_value_as_string_type_policy> param_value_as_string{s_, idx_};

    
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::current_trades_getParamEx)

// class_info (Returned by getClassInfo)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(class_info_getClassInfo)
    LUACPP_TABLE_FIELD(firmid, const char*) // Код фирмы 
    LUACPP_TABLE_FIELD(name, const char*) // Наименование класса 
    LUACPP_TABLE_FIELD(code, const char*) // Код класса 
    LUACPP_TABLE_FIELD(npars, unsigned int) // Количество параметров в классе 
    LUACPP_TABLE_FIELD(nsecs, unsigned int) // Количество бумаг в классе
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::class_info_getClassInfo)

// chart_time (Returned by ds:T)
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(chart_time)
    LUACPP_TABLE_FIELD(year, unsigned int)
    LUACPP_TABLE_FIELD(month, unsigned int)
    LUACPP_TABLE_FIELD(day, unsigned int)
    LUACPP_TABLE_FIELD(week_day, unsigned int)
    LUACPP_TABLE_FIELD(hour, unsigned int)
    LUACPP_TABLE_FIELD(min, unsigned int)
    LUACPP_TABLE_FIELD(sec, unsigned int)
    LUACPP_TABLE_FIELD(ms, unsigned int)
    LUACPP_TABLE_FIELD(count, unsigned int)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::chart_time)
