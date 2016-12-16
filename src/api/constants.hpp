#pragma once

#include <luacpp>

namespace qlua {
  struct qlua_constants {
    qlua_constants(const lua::state& l);
    qlua_constants(const qlua_constants& other);
    qlua_constants(qlua_constants&& other);
    void swap(qlua_constants& other);
    qlua_constants& operator=(const qlua_constants& other);
    
    int QTABLE_INT_TYPE() const;
    int QTABLE_DOUBLE_TYPE() const;
    int QTABLE_INT64_TYPE() const;
    int QTABLE_CACHED_STRING_TYPE() const;
    int QTABLE_TIME_TYPE() const;
    int QTABLE_DATE_TYPE() const;
    int QTABLE_STRING_TYPE() const;

    unsigned int QTABLE_DEFAULT_COLOR() const;
    int QTABLE_NO_INDEX() const;
  private:
    lua::state l_;
  };
}

