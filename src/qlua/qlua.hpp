#pragma once

#include <luacpp/luacpp>

#include "api/macros.h"
#include "structs.hpp"
#include "callbacks.hpp"

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
    
    // Service "Сервисные функции"
#include "api/service.hpp"
    // Table data access Функции для обращения к строкам произвольных таблиц QUIK
#include "api/table_data.hpp"
    // Securities "Функции для обращения к спискам доступных параметров"
#include "api/securities.hpp"
    // Workplace "Функции взаимодействия скрипта Lua и Рабочего места QUIK"
#include "api/workplace.hpp"
    // Current trades "Функции получения значений Таблицы текущих торгов"
#include "api/current_trades_receive.hpp"
    // Charts "Функции для работы с графиками"
#include "api/charts.hpp"
    // Table manipulations "Функции для работы с таблицами Рабочего места QUIK"
#include "api/table.hpp"
    // "Функции для работы с метками"
#include "api/labels.hpp"
    // Level 2 quotes "Функции для заказа стакана котировок"
#include "api/level2_quotes.hpp"
    // Функции для заказа параметров Таблицы текущих торгов
#include "api/current_trades_request.hpp"
    // Функции для работы с битовыми масками в структурах данных
#include "api/bitmask.hpp"
    
  private:
    lua::state l_;
  };
}
