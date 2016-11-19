#pragma once

#include <string>
#include <stdexcept>

namespace qlua {
  namespace error {
    struct quote_level_2_nil_result : public std::runtime_error {
      quote_level_2_nil_result(const std::string& where) :
        std::runtime_error("quote_level_2 result is nil in " + where) {
      }
    };
    
    struct quote_level_2_wrong_bid_count : public std::runtime_error {
      quote_level_2_wrong_bid_count(const size_t expected_count, const size_t actual_count) :
        std::runtime_error("quote_level_2 read error, wrong bid count: expected  " +
                           std::to_string(expected_count) + ", actually returned " +
                           std::to_string(actual_count)) {
      }
    };

    struct quote_level_2_wrong_offer_count : public std::runtime_error {
      quote_level_2_wrong_offer_count(const size_t expected_count, const size_t actual_count) :
        std::runtime_error("quote_level_2 read error, wrong offer count: expected  " +
                           std::to_string(expected_count) + ", actually returned " +
                           std::to_string(actual_count)) {
      }
    };

  }
}
