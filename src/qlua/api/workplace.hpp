#pragma once

#include "../structs/function_results.hpp"

// regex  ^ +\(.*\) \([A-Za-z0-9]+?\) *(\(.*\))  ->  QLUACPP_DETAIL_API_FUNCTION(\1,JJ\2,JJ\3JJ)
 
// getDepo - функция для получения информации по бумажным лимитам
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY10(::qlua::table::depo_limits_getDepo,
                            getDepo,
                            const char*, client_code,
                            const char*, firmid,
                            const char*, sec_code,
                            const char*, trdaccid
                            )
// getDepoEx - функция для получения информации по бумажным лимитам указанного типа
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY12(::qlua::table::depo_limits,
                            getDepoEx,
                            const char*, firmid,
                            const char*, client_code,
                            const char*, sec_code,
                            const char*, trdaccid,
                            const int, limit_kind
                            )
   
// getMoney - функция для получения информации по денежным лимитам
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY10(::qlua::table::money_limits_getMoney,
                            getMoney,
                            const char*, client_code,
                            const char*, firmid,
                            const char*, tag,
                            const char*, currcode
                            )
// getMoneyEx - функция для получения информации по денежным лимитам указанного типа
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY12(::qlua::table::money_limits,
                            getMoneyEx,
                            const char*, firmid,
                            const char*, client_code,
                            const char*, tag,
                            const char*, currcode,
                            const int, limit_kind
                            )
// getFuturesLimit - функция для получения информации по фьючерсным лимитам
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY10(::qlua::table::futures_client_limits,
                            getFuturesLimit,
                            const char*, firmid,
                            const char*, trdaccid,
                            const int, limit_type,
                            const char*, currcode
                            )   
// getFuturesHolding - функция для получения информации по фьючерсным позициям
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY10(::qlua::table::futures_client_holding,
                            getFuturesHolding,
                            const char*, firmid,
                            const char*, trdaccid,
                            const char*, sec_code,
                            const int, type
                            )

// getQuoteLevel2 - функция для получения стакана по указанному классу и бумаге
/*QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY6(::qlua::table::level2_quotes,
                            getQuoteLevel2,
                            const char*, class_code,
                            const char*, sec_code
                            )*/
void getQuoteLevel2(const char* class_code,
                    const char* sec_code,
                    std::function<void(const ::qlua::table::level2_quotes &)> lambda) const {
  auto f = [&lambda] (const ::lua::state& s) {
    auto v = ::qlua::table::level2_quotes(s, -1);
    lambda(v);
    return 1;
  };
  l_.call_and_apply(f, 1, "getQuoteLevel2", class_code, sec_code);
}

// getSecurityInfo - функция для получения информации по инструменту
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY6(::qlua::table::securities,
                            getSecurityInfo,
                            const char*, class_code,
                            const char*, sec_code
                            )
// getTradeDate - функция для получения даты торговой сессии
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY2(::qlua::table::date_,
                            getTradeDate
                            )

// sendTransaction - функция для работы с заявками
void sendTransaction(const std::map<std::string, std::string>& transaction // Поля таблицы в соответствии с описанием .tri файла по quik.chm
                     ) {
  l_.getglobal("sendTransaction");
  l_.newtable();
  for (const auto& p : transaction) {
    l_.pushstring(p.first.c_str());
    l_.pushstring(p.second.c_str());
    l_.settable(-3);
  }
  l_.pcall(1, 1, 0);
  if (l_.isstring(-1)) {
    const auto& msg = l_.at<const char*>(-1)();
    if (msg[0] == 0) {
      l_.pop(1);
    } else {
      const std::string msg_str = msg;
      l_.pop(1);
      throw std::runtime_error("sendTransaction error: " + msg_str);
    }
  } else {
    l_.pop(1);
    throw std::runtime_error("sendTransaction returned unexpected type");
  }
}

// CalcBuySell - функция для расчета максимально возможного количества лотов в заявке
QLUACPP_DETAIL_API_FUNCTION_TUPLE2_17(unsigned int, double, // qty,  comission,
                            CalcBuySell,
                            const char*, class_code,
                            const char*, sec_code,
                            const char*, client_code,
                            const char*, account,
                            const double, price,
                            const bool, is_buy,
                            const bool, is_market
                            ) 

// getPortfolioInfo - функция для получения значений параметров таблицы «Клиентский портфель»
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY6(::qlua::table::portfolio_info_getPortfolioInfo,
                            getPortfolioInfo,
                            const char*, firm_id,
                            const char*, client_code
                            )
// getPortfolioInfoEx - функция для получения значений параметров таблицы «Клиентский портфель» с учетом вида лимита
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY8(::qlua::table::portfolio_info_getPortfolioInfoEx,
                            getPortfolioInfoEx,
                            const char*, firm_id,
                            const char*, client_code,
                            const int, limit_kind
                            )
// getBuySellInfo - функция для получения параметров таблицы «Купить/Продать»
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY12(::qlua::table::buy_sell_info_getBuySellInfo,
                            getBuySellInfo,
                            const char*, firm_id,
                            const char*, client_code,
                            const char*, class_code,
                            const char*, sec_code,
                            const double, price
                            )
// getBuySellInfoEx - функция для получения параметров (включая вид лимита) таблицы «Купить/Продать» 
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY12(::qlua::table::buy_sell_info_getBuySellInfoEx,
                            getBuySellInfoEx,
                             const char*, firm_id,
                             const char*, client_code,
                             const char*, class_code,
                             const char*, sec_code,
                             const double, price
                            )
