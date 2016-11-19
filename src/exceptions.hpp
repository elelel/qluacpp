#pragma once

#include <stdexcept>

namespace qlua {
  namespace error {
    struct sleep_failed : public std::runtime_error {
      sleep_failed(const int expected_ms, const int actual_ms) :
        std::runtime_error("sleep failed, expected to return " +
                           std::to_string(expected_ms) + ", actually returned " +
                           std::to_string(actual_ms)) {
      }
    };

    struct getQuoteLevel2_failed : public std::runtime_error {
      getQuoteLevel2_failed() : std::runtime_error("getQuoteLevel2 failed") {
      }
    };
    
    struct ParamRequest_failed : public std::runtime_error {
      ParamRequest_failed() : std::runtime_error("ParamRequest failed") {
      }
    };
  }
}
