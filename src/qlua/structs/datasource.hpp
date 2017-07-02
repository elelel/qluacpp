#pragma once

// DataSource (раздел "Функции для работы с графиками" qlua.chm)

#include "function_results.hpp"

#include <iostream>

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
      auto set_pointers = [this] (const lua::state& s) -> int {
        if (s.istable(-2)) {
          // Copy object table
          s.getglobal(desc_table_name().c_str());
          if (s.isnil(-1)) {  // Create table if doesn't exist
            s.pop(1);
            s.newtable();
            s.setglobal(desc_table_name().c_str());
            s.getglobal(desc_table_name().c_str());
          }
          if (s.istable(-1)) {
            // Source table at -3, dest table at -1
            s.pushnil(); // Push nil as key
            while (s.next(-4) != 0) {
              // Duplicate the key
              s.pushvalue(-2);
              // Swap the key duplicate with value
              s.insert(-2);
              // Dest table is now at -4, set key/value
              s.settable(-4);
            }
            s.pop(); // getglobal (dest table)
            std::cout << "Done copying table" << std::endl;
          } else {
            s.pop(1 // getglobal (dest table)
                  + 2 // values of function result on stack after pcall);
                  );
            throw std::runtime_error("Failed to create lua table in globals for datasource descriptor");
          }
          return 2;
        } else {
          auto err = s.at<const char*>(-1);
          std::string msg("Failed to create datasource, qlua returned: ");
          msg += err();
          s.pop(2);
          throw std::runtime_error(msg.c_str());
        }
      };

      if (param != nullptr) {
        std::cout << "Creating datasource" << std::endl;
        l_.call_and_apply(set_pointers, 2, "CreateDataSource", class_code, sec_code, interval, param);
      } else {
        l_.call_and_apply(set_pointers, 2, "CreateDataSource", class_code, sec_code, interval);
      }
    }

    double O(const unsigned int idx) {
      return double_method_call("O", idx);
    }

    double C(const unsigned int idx) {
      return double_method_call("C", idx);
    }
    
    double H(const unsigned int idx) {
      return double_method_call("H", idx);
    }
    
    double L(const unsigned int idx) {
      return double_method_call("L", idx);
    }
    
    double V(const unsigned int idx) {
      return double_method_call("V", idx);
    }
    
    // Time
    time T(const unsigned int idx) const {
      l_.getglobal(desc_table_name().c_str());
      if (l_.istable(-1)) {
        l_.pushstring("T");
        l_.gettable(-1); // Push function from table to stack
        l_.pcall(1, 1, 0);
        auto t = l_.at<table::chart_time>(-1)();
        time rslt =  {t.year(), t.month(), t.day(), t.week_day(), t.hour(), t.min(), t.sec(), t.ms(), t.count()};
        l_.pop(2); // table and value
        return rslt;
      } else {
        l_.pop(1); // getglobal
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    bool SetUpdateCallback(const char* lua_function_name) {
      std::cout << "Setting update callback" << std::endl;
      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        std::cout << "istable passed" << std::endl;
        l_.pushstring("SetUpdateCallback");
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (!l_.isnil(-1)) {
          std::cout << "getting lua function name" << std::endl;
          l_.getglobal(lua_function_name);
          ++i;
          if (l_.isfunction(-1)) {
            l_.pcall(1, 1, 0);
            ++i;
            auto rslt = l_.at<bool>(-1)();
            l_.pop(i);
            std::cout << "Returning " << rslt << std::endl;
            return rslt;
          } else {
            l_.pop(i);
            std::cout << "Error 1" << std::endl;
            throw std::runtime_error("Call to datasource method failed: " + std::string(lua_function_name) + " is not a function in lua globals");
          }
        } else {
          std::cout << "Error 3" << std::endl;
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: SetUpdateCallback method is nil in desc table");
        }
      } else {
        std::cout << "Error 2" << std::endl;
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    bool SetEmptyCallback() {
      l_.getglobal(desc_table_name().c_str());
      if (l_.istable(-1)) {
        l_.pushstring("SetEmptyCallback");
        l_.rawget(-1); // Push function from table to stack
        l_.pcall(0, 1, 0);
        auto rslt = l_.at<bool>(-1)();
        l_.pop(2); // table and value
        return rslt;
      } else {
        l_.pop(1); // getglobal
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    unsigned int Size() {
      l_.getglobal(desc_table_name().c_str());
      if (l_.istable(-1)) {
        l_.pushstring("Size");
        l_.rawget(-1); // Push function from table to stack
        l_.pcall(0, 1, 0);
        auto rslt = l_.at<unsigned int>(-1)();
        l_.pop(2); // table and value
        return rslt;
      } else {
        l_.pop(1); // getglobal
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }
    
    bool Close() {
      l_.getglobal(desc_table_name().c_str());
      if (l_.istable(-1)) {
        l_.pushstring("Close");
        l_.rawget(-1); // Push function from table to stack
        l_.pcall(0, 1, 0);
        auto rslt = l_.at<bool>(-1)();
        l_.pop(2); // table and value
        return rslt;
      } else {
        l_.pop(1); // getglobal
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    std::string desc_table_name() const {
      return "qluacpp_datasource_object_" + std::to_string((uint32_t)this);
    }

  private:
    lua::state l_;

    inline double double_method_call(const char* name, const unsigned int idx) const {
      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushstring(name);
        l_.rawget(-1); // Push function from table to stack
        l_.push<unsigned int>(idx);
        l_.pcall(1, 1, 0);
        ++i;
        auto rslt = l_.at<double>(-1)();
        l_.pop(i);
        return rslt;
      } else {
        l_.pop(i);
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }
  };
  
}
