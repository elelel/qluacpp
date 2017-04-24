#pragma once

// This file should be included only from qlua.hpp
// Table access functions
template <typename item_t>
item_t getItem(const char* table_name, const int index) const {
  const char api_name[] = "getItem";
  typedef std::tuple<item_t> return_type;
  return std::get<0>(l_.call<return_type>(api_name, table_name, index));
}

/* TODO: fix table row orders
   std::tuple<table::row::orders, unsigned int> getOrderByNumber(const char* class_code, unsigned int order_id) const {
   const char api_name[] = "getOrderByNumber";
   typedef std::tuple<table::row::orders, unsigned int> return_type;
   return l_.call<return_type>(api_name, class_code, order_id);
   }
*/

QLUACPP_DETAIL_API_FUNCTION4(unsigned int, getNumberOf,
                             const char*, table_name);

/*
  template <typename... Args>
  std::vector<unsigned int> SearchItems(const char* table_name, bool(Args...)) {
  throw std::runtime_error("Not implemented");
  }*/
