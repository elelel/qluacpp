#pragma once

// date and datetime tables

#define QLUACPP_DATETIME_TABLE_FIELD( NAME )    \
  static constexpr const char _##NAME##_field_name[] = #NAME; \
  ::lua::entity<detail::datetime_type_policy<_##NAME##_field_name>> NAME{s_, idx_}; \


// --- Direct macro table generators ---

// date
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(date_)
    LUACPP_TABLE_FIELD(date, std::string)
    LUACPP_TABLE_FIELD(year, unsigned int)
    LUACPP_TABLE_FIELD(month, unsigned int)
    LUACPP_TABLE_FIELD(day, unsigned int)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::date_)

// datetime "Формат даты и времени, используемый таблицах"
namespace qlua {
  namespace table {
    LUACPP_STATIC_TABLE_BEGIN(datetime)
    LUACPP_TABLE_FIELD(mcs, int)
    LUACPP_TABLE_FIELD(ms, int)
    LUACPP_TABLE_FIELD(sec, int)
    LUACPP_TABLE_FIELD(min, int)
    LUACPP_TABLE_FIELD(hour, int)
    LUACPP_TABLE_FIELD(day, int)
    LUACPP_TABLE_FIELD(week_day, int)
    LUACPP_TABLE_FIELD(month, int)
    LUACPP_TABLE_FIELD(year, int)
    LUACPP_STATIC_TABLE_END()
  }
}
LUACPP_STATIC_TABLE_TYPE_POLICY(::qlua::table::datetime)

// --- For nested tables ---

// datetime "Формат даты и времени, используемый таблицах"
namespace qlua {
  // Plain C structure to hold date_time
  struct c_date_time {
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
  
  namespace table {
    namespace detail {

      template <const char* FieldName>
      struct datetime_type_policy {
        using write_type = const c_date_time&;
        using read_type = c_date_time;

        static inline bool type_matches(::lua::state s, int idx) {
          return s.istable(idx); // Check that we're at a table
        }

        static inline read_type get_unsafe(::lua::state s, int idx) {
          read_type rslt{0};
          int table_idx = idx;
          s.push<const char*>(FieldName);
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
            throw std::runtime_error("table does not have "+std::string(FieldName)+" table member");
          }
          s.pop(1);
          return rslt;
        }

        static inline void apply_unsafe(::lua::state s, int idx, std::function<void(const lua::state&, int)> f) {
          throw std::runtime_error("apply_unsafe is not implemented for datetime");
        }

        static inline void set(::lua::state s, int idx, c_date_time value) {
          throw std::runtime_error("set is not implemented for datetime");
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
      
    }
  }
}
