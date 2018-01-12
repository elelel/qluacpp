#pragma once

// all_trades "Обезличенные сделки"
// Object names in qlua.chm: alltrade
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(all_trades)
    struct date_time {
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

    struct datetime_type_policy {
      using write_type = const date_time&;
      using read_type = date_time;

      static inline bool type_matches(::lua::state s, int idx) {
        return s.istable(idx); // Check only for all_trades table 
      }

      static inline read_type get_unsafe(::lua::state s, int idx) {
        read_type rslt{0};
        int table_idx = idx;
        s.push<const char*>("datetime");
        if (idx <= 0)
          s.gettable(idx - 1);
        else
          s.gettable(idx);
        if (s.istable(-1)) {
          rslt.mcs = get_field<int>(s, "mcs");
          rslt.ms = get_field<int>(s, "ms");
          rslt.sec = get_field<int>(s, "sec");
          rslt.min = get_field<int>(s, "min");
          rslt.hour = get_field<int>(s, "hour");
          rslt.day = get_field<int>(s, "day");
          rslt.week_day = get_field<int>(s, "week_day");
          rslt.month = get_field<int>(s, "month");
          rslt.year = get_field<int>(s, "year"); 
        } else {
          s.pop(1);
          throw std::runtime_error("alltrade table does not have datetime table member");
        }
        s.pop(1);
        return rslt;
      }

      static inline void apply_unsafe(::lua::state s, int idx, std::function<void(const lua::state&, int)> f) {
        throw std::runtime_error("apply_unsafe is not implemented for alltrade datetime");
      }

      static inline void set(::lua::state s, int idx, date_time value) {
        throw std::runtime_error("set is not implemented for alltrade datetime");
      }
      
    private:
      template <typename T>
      static inline const T get_field(::lua::state s, const char* name) {
        s.push<const char*>(name);
        s.rawget(-2);
        auto rslt = ::lua::entity<::lua::type_policy<T>>(s, -1).get();
        s.pop(1);
        return rslt;
      }
      
    };

    ::lua::entity<datetime_type_policy> datetime{s_, idx_};
    
    LUACPP_TABLE_FIELD(period, unsigned int) /* Период торговой сессии. Возможные значения: 
                                                «0» – Открытие; 
                                                «1» – Нормальный; 
                                                «2» – Закрытие */
    LUACPP_TABLE_FIELD(open_interest, double) // Открытый интерес 
    LUACPP_TABLE_FIELD(exchange_code, std::string) // Код биржи в торговой системе 
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::all_trades)

namespace qlua {
  namespace table {
    namespace detail {
      template <>
      struct name_for_type<::qlua::table::all_trades> {
        static const char* value() { return "all_trades"; }
      };
    }
  }
}

