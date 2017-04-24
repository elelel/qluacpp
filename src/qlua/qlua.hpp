#pragma once

#include <luacpp/luacpp>

#include "structs/tables.hpp"

#define QLUACPP_DETAIL_API_FUNCTION2(RETURN_TYPE, NAME) \
  RETURN_TYPE NAME() const {                            \
    typedef RETURN_TYPE bare_return_type;               \
    typedef std::tuple<bare_return_type> return_type;   \
    return std::get<0>(l_.call<return_type>(#NAME));    \
  }                                                     \

#define QLUACPP_DETAIL_API_FUNCTION4(RETURN_TYPE, NAME,         \
                                     ARG1_TYPE, ARG1)           \
  RETURN_TYPE NAME(ARG1_TYPE ARG1) const {                      \
    typedef RETURN_TYPE bare_return_type;                       \
    typedef std::tuple<bare_return_type> return_type;           \
    return std::get<0>(l_.call<return_type>(#NAME, ARG1));      \
  }                                                             \

#define QLUACPP_DETAIL_API_FUNCTION6(RETURN_TYPE, NAME,         \
                                     ARG1_TYPE, ARG1,           \
                                     ARG2_TYPE, ARG2)           \
  RETURN_TYPE NAME(ARG1_TYPE ARG1, ARG2_TYPE ARG2) const {      \
    typedef std::tuple<RETURN_TYPE> return_type;                \
    return std::get<0>(l_.call<return_type>(#NAME, ARG1));      \
  }                                                             \

#define QLUACPP_DETAIL_API_FUNCTION_VOID3(NAME,                 \
                                          ARG1_TYPE, ARG1)      \
  void NAME(ARG1_TYPE ARG1) const {                             \
    l_.call<std::tuple<>>(#NAME, ARG1);                         \
  }                                                             \


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

    void test() const {
      std::cout << "Testing internal " << l_.C_state() << "\n";
      l_.getglobal("message");
      std::cout << "Internal test done\n";
    }

    // Service "Сервисные функции"
#include "api/service.hpp"
    // Table access functions
#include "api/table.hpp"

    
  private:
    lua::state l_;
  };
}
