#pragma once

#include <vector>

#include <luacpp>

#include "exceptions.hpp"

namespace qlua {
  struct quote_level_2 {
    struct record {
      const char* price;
      const char* quantity;
    };

    typedef quote_level_2 type;

    quote_level_2();
    quote_level_2(const type& other);
    quote_level_2(type&& other);
    void swap(type& other);
    type& operator=(const type& other);
    
    const size_t bid_count();
    const size_t offer_count();
    std::vector<record> bid;
    std::vector<record> offer;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::quote_level_2::record> {
    inline static qlua::quote_level_2::record read(const lua::state& l, int idx = -1) {
      qlua::quote_level_2::record r;
      l.get_field_into("price", r.price);
      l.get_field_into("quantity", r.quantity);
      return r;
    }
  };

  template <>
  struct stack_reader<qlua::quote_level_2> {
    inline static qlua::quote_level_2 read(const lua::state& l, int idx = -1) {
      qlua::quote_level_2 r;
      int expected_bid_count{0};
      int expected_offer_count{0};
      if (l.isnil())
        throw qlua::error::quote_level_2_nil_result("top table");

      l.getfield(-1, "bid_count");
      if (!l.isnil()) {
        l.get_value_into(expected_bid_count, -1);
        if (expected_bid_count > 0) {
          l.getfield(-2, "bid");
          if (l.isnil())
            throw qlua::error::quote_level_2_nil_result("bid table");
          l.get_rows_into(r.bid, -1, expected_bid_count);
          l.pop(1);
        }
      }
      l.pop(1);
      if (r.bid.size() != expected_bid_count)
        throw qlua::error::quote_level_2_wrong_bid_count(r.bid.size(), expected_bid_count);

      l.getfield(-1, "offer_count");
      if (!l.isnil()) {
        l.get_value_into(expected_offer_count, -1);
        if (expected_offer_count > 0) {
          if (l.isnil())
            throw qlua::error::quote_level_2_nil_result("offer table");
          l.getfield(-2, "offer");
          l.get_rows_into(r.offer, -1, expected_offer_count);
          l.pop(1);
        }
      }
      l.pop(1); 
      if (r.offer.size() != expected_offer_count)
        throw qlua::error::quote_level_2_wrong_offer_count(r.offer.size(), expected_offer_count);
      return r;
    }
  };
}
