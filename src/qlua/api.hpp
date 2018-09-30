#pragma once

#include <map>

#include <luacpp/luacpp>

#include "api/macros.h"
#include "structs/datetime.hpp"
#include "structs/standalone.hpp"
#include "structs/function_results.hpp"
#include "structs/datasource.hpp"
#include "structs/level2_quotes.hpp"
#include "callbacks.hpp"

// TODO: type policies in numeric_tuples.hpp

namespace qlua {
  struct api {
    typedef api type;
    api(const lua::state& l) :
      l_(l) {
    }
    
    api(const type& other) :
      l_(other.l_) {
    }
    
    api(type&& other) :
      l_(std::move(other.l_)) {
    }
    
    void swap(type& other) {
      std::swap(l_, other.l_);
    }
    
    type& operator=(const type& other) {
      type tmp(other);
      swap(tmp);
      return *this;
    }

    template <typename Constant>
    Constant constant(const char* name) const {
      l_.getglobal(name);
      if (!l_.isnil(-1)) {
        auto rslt = l_.at<Constant>(-1).get();
        l_.pop(1);
        return rslt;
      } else {
        l_.pop(1);
        throw std::runtime_error("QluaCpp error: QLua constant " + std::string(name) + " is nil in globals list");
      }
    }

    const lua::state& lua_state() const {
      return l_;
    }
    
    // Service "Сервисные функции"
#include "api/service.hpp"
    // Table data access Функции для обращения к строкам произвольных таблиц QUIK
#include "api/table_data.hpp"
    // Securities "Функции для обращения к спискам доступных параметров"
#include "api/securities.hpp"
    // Workplace "Функции взаимодействия скрипта Lua и Рабочего места QUIK"
#include "api/workplace.hpp"
    // Current trades receive "Функции получения значений Таблицы текущих торгов"
#include "api/current_trades_receive.hpp"
    // Charts "Функции для работы с графиками"
#include "api/charts.hpp"
    // Table manipulations "Функции для работы с таблицами Рабочего места QUIK"
#include "api/table.hpp"
    // "Функции для работы с метками"
#include "api/labels.hpp"
    // Level 2 quotes "Функции для заказа стакана котировок"
#include "api/level2_quotes.hpp"
    // Current trades request Функции для заказа параметров Таблицы текущих торгов
#include "api/current_trades_request.hpp"
    // Bitmask Функции для работы с битовыми масками в структурах данных
#include "api/bitmask.hpp"
    
  protected:
    lua::state l_;
  };
}
