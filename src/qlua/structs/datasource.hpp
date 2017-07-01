#pragma once

// DataSource (раздел "Функции для работы с графиками" qlua.chm)

#include "function_results.hpp"

namespace qlua {
  struct data_source {
    struct time {
      unsigned int year;
      unsigned int month;
      unsigned int day;
      unsigned int week_day;
      unsigned int hour;
      unsigned int min;
      unsigned int sec;
      unsigned int ms;
      unsigned int count;
    };
    
    data_source(const lua::state& l,
                const char* class_code,  // код класса
                const char* sec_code,    // код бумаги
                const unsigned int interval, // интервал запрашиваемого графика, INTERVAL_*
                const char* param = nullptr // Необязательный параметр (что запрашивать)
                ) : l_(l) {
      typedef std::tuple<table::data_source, const char*> return_type;
      auto set_pointers = [this] (const lua::state& s) -> int {
        if (!s.isnil(-2)) {
          auto ds = s.at<table::data_source>(-2)();
          O_ = ds.O();
          H_ = ds.H();
          L_ = ds.L();
          C_ = ds.C();
          V_ = ds.V();
          T_ = ds.T();
          Size_ = ds.Size();
          Close_ = ds.Close();
          SetUpdateCallback_ = ds.SetUpdateCallback();
          SetEmptyCallback_ = ds.SetEmptyCallback();
          return 2;
        } else {
          auto err = s.at<const char*>(-1);
          throw std::runtime_error(std::string("Create data source error: ") + err());
        }
      };

      if (param != nullptr) {
        l_.call_and_apply(set_pointers, 2, "CreateDataSource", class_code, sec_code, interval, param);
      } else {
        l_.call_and_apply(set_pointers, 2, "CreateDataSource", class_code, sec_code, interval);
      }
    }

    // Open
    double O(const unsigned int idx) const {
      l_.push<unsigned int>((size_t)(O_));
      l_.pcall(1, 1, 0);
      auto rslt = l_.at<double>(-1)();
      l_.pop(1);
      return rslt;
    }
    
    // High
    double H(const unsigned int idx) const {
      l_.push<unsigned int>((size_t)(H_));
      l_.pcall(1, 1, 0);
      auto rslt = l_.at<double>(-1)();
      l_.pop(1);
      return rslt;
    }
    
    // Low
    double L(const unsigned int idx) const {
      l_.push<unsigned int>((size_t)(L_));
      l_.pcall(1, 1, 0);
      auto rslt = l_.at<double>(-1)();
      l_.pop(1);
      return rslt;
    }
    
    // Close
    double C(const unsigned int idx) const {
      l_.push<unsigned int>((size_t)(C_));
      l_.pcall(1, 1, 0);
      auto rslt = l_.at<double>(-1)();
      l_.pop(1);
      return rslt;
    }
    
    // Volume
    double V(const unsigned int idx) const {
      l_.push<unsigned int>((size_t)(V_));
      l_.pcall(1, 1, 0);
      auto rslt = l_.at<double>(-1)();
      l_.pop(1);
      return rslt;
    }
    
    // Time
    time T(const unsigned int idx) const {
      l_.push<unsigned int>((size_t)(T_));
      l_.pcall(1, 1, 0);
      auto t = l_.at<table::chart_time>(-1)();
      time rslt =  {t.year(), t.month(), t.day(), t.week_day(), t.hour(), t.min(), t.sec(), t.ms(), t.count()};
      l_.pop(1);
      return rslt;
    }

    template <typename callback_t>
    bool SetUpdateCallback() {
      
    }

    void* SetUpdateCallback_{nullptr};
    void* O_{nullptr};
    void* H_{nullptr};
    void* L_{nullptr};
    void* C_{nullptr};
    void* V_{nullptr};
    void* T_{nullptr};
    void* Size_{nullptr};
    void* Close_{nullptr};
    void* SetEmptyCallback_{nullptr};
  private:
    lua::state l_;
  };
  
}
