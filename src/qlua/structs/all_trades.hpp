#pragma once

// all_trades "Обезличенные сделки"
// Object names in qlua.chm: alltrade
namespace qlua {
  namespace table {
    struct all_trades {
      struct datetime_struct {
        int mcs;
        int ms;
        int sec;
        int min;
        int hour;
        int day;
        int week_day;
        int month;
        int year;
      };

      all_trades(const lua::state& l, const int idx) :
        l_(l), idx_(idx) {
        if (!l_.istable(idx_)) {
          throw std::runtime_error("alltrade: can't create, not a table");
        }
      }

      inline const unsigned int trade_num() const { // Номер сделки в торговой системе
        return get_field<unsigned int>("trade_num"); 
      }
      
      const unsigned int flags() const { // Набор битовых флагов
        return get_field<unsigned int>("flags");
      }
      
      const double price() const { // Цена
        return get_field<double>("price");
      }
      
      const unsigned int qty() const { // Количество бумаг в последней сделке в лотах
        return get_field<unsigned int>("qty");
      }
      
      const double value() const { // Объем в денежных средствах
        return get_field<double>("value");
      }
      
      const double accruedint() const { // Накопленный купонный доход
        return get_field<double>("accruedint");
      }
      
      const double yield() const { // Доходность
        return get_field<double>("yield");
      }
      
      const std::string settlecode() const { // Код расчетов
        return get_field<std::string>("settlecode");
      }
      
      const double reporate() const { // Ставка РЕПО (%)
        return get_field<double>("reporate");
      }
      
      const double repovalue() const { // Сумма РЕПО
        return get_field<double>("repovalue");
      }
      
      const double repo2value() const { // Объем выкупа РЕПО
        return get_field<double>("repo2value");
      }
      
      const double repoterm() const { // Срок РЕПО в днях
        return get_field<double>("repoterm");
      }
      
      const std::string sec_code() const { // Код бумаги заявки
        return get_field<std::string>("sec_code");
      }
      
      const std::string class_code() const { // Код класса
        return get_field<std::string>("class_code");
      }
      
      const datetime_struct datetime() const { // Дата и время
        datetime_struct dt;
        l_.push<const char*>("datetime");
        l_.rawget(idx_ - 1);
        if (l_.istable(-1)) {
          auto qdt = ::lua::entity<::lua::type_policy<::qlua::table::datetime>>(l_, -1)();
          dt.mcs = qdt.mcs();
          dt.ms = qdt.ms();
          dt.sec = qdt.sec();
          dt.min = qdt.min();
          dt.hour = qdt.hour();
          dt.day = qdt.day();
          dt.week_day = qdt.week_day();
          dt.month = qdt.month();
          dt.year = qdt.year();
        } else {
          throw std::runtime_error("all_trades: get datetime table failed, not a table");
        }
        l_.pop(1);
        return dt;
      }
      
      const unsigned int period() const { /* Период торговой сессии. Возможные значения: 
                                             «0» – Открытие; 
                                             «1» – Нормальный; 
                                             «2» – Закрытие */
        return get_field<unsigned int>("period");
      }
      
      const double open_interest() const { // Открытый интерес
        return get_field<double>("open_interest");
      }
      
      const std::string exchange_code() const { // Код биржи в торговой системе
        return get_field<std::string>("exchange_code");
      }

    private:
      const lua::state& l_;
      const size_t idx_;

      template <typename T>
      inline const T get_field(const char* name) const {
        l_.push<const char*>(name);
        l_.rawget(idx_ - 1);
        auto rslt = ::lua::entity<::lua::type_policy<const T>>(l_, -1).get();
        l_.pop(1);
        return rslt;
      }
      
    };
  }
}

namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(all_trades_no_datetime)
    LUACPP_TABLE_FIELD(trade_num, unsigned int) // Номер сделки в торговой системе 
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
    //    LUACPP_TABLE_FIELD(datetime, ::qlua::table::datetime) // Дата и время; НЕДОСТУПНО, ИСПОЛЬЗОВАТЬ ::qlua::table::all_trades  
    LUACPP_TABLE_FIELD(period, unsigned int) /* Период торговой сессии. Возможные значения: 
                                                «0» – Открытие; 
                                                «1» – Нормальный; 
                                                «2» – Закрытие */
    LUACPP_TABLE_FIELD(open_interest, double) // Открытый интерес 
    LUACPP_TABLE_FIELD(exchange_code, std::string) // Код биржи в торговой системе 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::all_trades_no_datetime)


