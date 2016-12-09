#pragma once

#include <luacpp>

#include <string>
#include <vector>

#include "../exceptions.hpp"
#include "constants.hpp"
#include "structs/class_info.hpp"
#include "structs/money_limits.hpp"
#include "structs/depo_limits.hpp"
#include "structs/futures_limits.hpp"
#include "structs/futures_holdings.hpp"
#include "structs/instrument.hpp"
#include "structs/date.hpp"
#include "structs/quote_level_2.hpp"
#include "structs/param.hpp"
#include "structs/transaction.hpp"
#include "structs/portfolio_info.hpp"
#include "structs/buy_sell_info.hpp"
#include "tables/orders.hpp"
#include "tables/depo_limits.hpp"
#include "tables/money_limits.hpp"

namespace qlua {
  struct api {
    api(lua::state& l);
    api(const api& other);
    api(api&& other);
    void swap(api& other);
    api& operator=(const api& other);
    
    template <typename callback_t>
    callback_t& set_callback(typename callback_t::handler_type handler) {
      static callback_t instance(lua_, handler);
      return instance;
    }
    
    // Service
    bool isConnected();
    const char* getScriptPath();
    const char* getInfoParam(const char* param_name);

    void message(const char* text, const unsigned int icon);
    void message(const char* text);
    void sleep(const int ms);
    const char* getWorkingFolder();
    void PrintDbgStr(const char* s);

    // Table access functions
    template <typename item_t>
    item_t getItem(const char* table_name, const int index) const {
      const char api_name[] = "getItem";
      typedef std::tuple<item_t> return_type;
      auto params = std::make_tuple(table_name, index);
      auto result = lua_.pcall<return_type>(api_name, params);
      return std::get<0>(result);
    }
    std::tuple<table::row::orders, unsigned int> getOrderByNumber(const char* class_code, unsigned int order_id) const;
    unsigned int getNumberOf(const char* table_name) const;
    /*
    template <typename... Args>
    std::vector<unsigned int> SearchItems(const char* table_name, bool(Args...)) {
      throw std::runtime_error("Not implemented");
      }*/
    
    // Instrument info (so called "parameters")
    const char* getClassesList();
    class_info getClassInfo(const char* class_name);
    const char* getClassSecurities(const char* class_name);

    // Workplace
    money_limits getMoney(const char* client_code, const char* firmid,
                          const char* tag, const char* currcode);
    money_limits getMoneyEx(const char* firm_id, const char* client_code,
                            const char* tag, const char* curr_code,
                            unsigned int limit_kind);
    depo_limits getDepo(const char* client_code, const char* firmid,
                        const char* sec_code, const char * account);
    depo_limits getDepoEx(const char* firm_id, const char* client_code,
                          const char* sec_code, const char* acc_id,
                          unsigned int limit_kind);
    futures_limits getFuturesLimit(const char* firm_id, const char* acc_id,
                                   unsigned int limit_type, const char* curr_code);
    futures_holdings getFuturesHolding(const char* firm_id, const char* acc_id,
                                       const char* sec_code, unsigned int pos_type);
    instrument getSecurityInfo(const char* class_code, const char* sec_code);
    date_table getTradeDate();
    quote_level_2 getQuoteLevel2(const char* class_code, const char* sec_code);
    param getParamEx(const char* class_code, const char* sec_code, const char* param_name);
    param getParamEx2(const char* class_code, const char* sec_code, const char* param_name);
    char* sendTransaction(const transaction_import& tri);
    std::tuple<double, double> CalcBuySell(const char* class_code, const char* sec_code, const char* client_code, const char* account, double price, bool is_buy, bool is_market);
    portfolio_info getPortfolioInfo(const char* firm_id, const char* client_code);
    portfolio_info_ex getPortfolioInfoEx(const char* firm_id, const char* client_code, unsigned int limit_kind);
    buy_sell_info getBuySellInfo(const char* firm_id, const char* client_code, const char* class_code, const char* sec_code, double price);
    buy_sell_info_ex getBuySellInfoEx(const char* firm_id, const char* client_code, const char* class_code, const char* sec_code, double price);

    // Workplace tables
    int AllocTable();
    bool AddColumn(const int& t_id, const int& iCode, const char* name, const bool& is_default, const int& par_type, const int& width);
    bool CreateWindow(const int& t_id);
    bool DeleteRow(const int& t_id, const int& key);
    bool DestroyTable(const int& t_id);
    int InsertRow(const int& t_id, const int& key);
    bool SetCell(const int& t_id, const int& key, const int& code, const char* text);
    bool SetCell(const int& t_id, const int& key, const int& code, const char* text, const double& value);
    bool SetWindowCaption(const int& t_id, const char* str);
    
    // Quotes Level 2
    bool Subscribe_Level_II_Quotes(const char* class_code, const char* sec_code);
    bool Unsubscribe_Level_II_Quotes(const char* class_code, const char* sec_code);
    bool IsSubscribed_Level_II_Quotes(const char* class_code, const char* sec_code);

    // Current trades table
    bool ParamRequest(const char* class_code, const char* sec_code, const char* db_name);

    const qlua_constants& constants() {
      return constants_;
    }
  protected:
    lua::state lua_;
    qlua_constants constants_;
  };
}
