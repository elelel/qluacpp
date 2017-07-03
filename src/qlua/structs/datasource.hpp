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
      auto f = [this] (const lua::state& l) -> int {
        // Check if CreateDataSource returned a table in first rslt
        if (l_.istable(-2)) {
          // Copy the table
          l_.pushvalue(-2);
          // Create reference
          if (l_.istable(-4)) {
            ref_key_ = luaL_ref(l_.C_state(), -4);
            if (ref_key_ != LUA_NOREF) {
              l_.pop(2);
              return 0;
            } else {
              l_.pop(1); // pushvalue
              throw std::runtime_error("Failed to create reference to datasource");
            }
          } else {
          }
        } else  {
          auto err = l_.at<const char*>(-1);
          std::string msg("Failed to create datasource, qlua returned: ");
          msg += err();
          l_.pop(2);
          throw std::runtime_error(msg.c_str());
        }
        return 0;
      };
      
      // Take references descriptor table
      l_.getglobal(desc_table_name().c_str());
      if (l_.isnil(-1)) {  // Create table if doesn't exist
        l_.pop(1);
        l_.newtable();
        l_.setglobal(desc_table_name().c_str());
        l_.getglobal(desc_table_name().c_str());
      }
      if (l_.istable(-1)) {
        // Call CreateDataSource and handle the results
        if (param != nullptr) {
          l_.call_and_apply(f, 2, "CreateDataSource", class_code, sec_code, interval, param);
        } else {
          l_.call_and_apply(f, 2, "CreateDataSource", class_code, sec_code, interval);
        }
      } else {
        l_.pop(1); // getglobal desc table
        throw std::runtime_error("Failed to create lua table in globals for datasource descriptor");
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
      if (ref_key_ == LUA_NOREF)
        throw std::runtime_error("Can't call datasource method: no reference to the object");

      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushnumber(ref_key_);
        l_.rawget(-2);
        ++i;
        l_.pushstring("T");
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (l_.isfunction(-1)) {
          l_.pushvalue(-2); // Push 'this'
          l_.pushnumber(idx);
          l_.pcall(2, 1, 0);
          ++i;
          auto t = l_.at<table::chart_time>(-1)();
          time rslt =  {t.year(), t.month(), t.day(), t.week_day(), t.hour(), t.min(), t.sec(), t.ms(), t.count()};
          l_.pop(i);
          return rslt;
        } else {
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: T method is not a function in object table");
        }
      } else {
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    bool SetUpdateCallback(const char* lua_function_name) {
      if (ref_key_ == LUA_NOREF)
        throw std::runtime_error("Can't call datasource method: no reference to the object");

      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushnumber(ref_key_);
        l_.rawget(-2);
        ++i;
        l_.pushstring("SetUpdateCallback");
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (l_.isfunction(-1)) {
          l_.pushvalue(-2); // Push 'this'
          ++i;
          l_.getglobal(lua_function_name);
          ++i;
          if (l_.isfunction(-1)) {
            l_.pcall(2, 1, 0);
            ++i;
            auto rslt = l_.at<bool>(-1)();
            l_.pop(i - 3); // Function address and arguments
            return rslt;
          } else {
            throw std::runtime_error("Call to datasource method failed: " + std::string(lua_function_name) + " is not a function in lua globals");
          }
        } else {
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: SetUpdateCallback method is not a function in object table");
        }
      } else {
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    bool SetEmptyCallback() {
      if (ref_key_ == LUA_NOREF)
        throw std::runtime_error("Can't call datasource method: no reference to the object");

      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushnumber(ref_key_);
        l_.rawget(-2);
        ++i;
        l_.pushstring("SetEmptyCallback");
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (l_.isfunction(-1)) {
          l_.pushvalue(-2); // Push 'this'
          l_.pcall(0, 1, 0);
          auto rslt = l_.at<unsigned int>(-1)();
          l_.pop(i - 1); // Function name already removed
          return rslt;
        } else {
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: SetEmptyCallback method is not a function in object table");
        }
      } else {
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    unsigned int Size() {
      if (ref_key_ == LUA_NOREF)
        throw std::runtime_error("Can't call datasource method: no reference to the object");

      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushnumber(ref_key_);
        l_.rawget(-2);
        ++i;
        l_.pushstring("Size");
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (l_.isfunction(-1)) {
          l_.pushvalue(-2); // Push 'this'
          l_.pcall(1, 1, 0);
          ++i;
          auto rslt = l_.at<unsigned int>(-1)();
          l_.pop(i - 1); // Function name already removed
          return rslt;
        } else {
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: Size method is not a function in object table");
        }
      } else {
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }
    
    bool Close() {
      if (ref_key_ == LUA_NOREF)
        throw std::runtime_error("Can't call datasource method: no reference to the object");

      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushnumber(ref_key_);
        l_.rawget(-2);
        ++i;
        l_.pushstring("Close");
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (l_.isfunction(-1)) {
          l_.pushvalue(-2); // Push 'this'
          l_.pcall(0, 1, 0);
          auto rslt = l_.at<unsigned int>(-1)();
          l_.pop(i - 1); // Function name already removed

          l_.getglobal(desc_table_name().c_str());
          luaL_unref(l_.C_state(), -1, ref_key_);
          ref_key_ = LUA_NOREF;
          l_.pop(1); // desc table

          return rslt;
        } else {
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: Close method is not a function in object table");
        }
      } else {
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }

    static std::string& desc_table_name() {
      static std::string s = "qluacpp_datasource_object_refs";
      return s;
    }

  private:
    lua::state l_;
    int ref_key_{LUA_NOREF};

    inline double double_method_call(const char* name, const unsigned int idx) const {
      if (ref_key_ == LUA_NOREF)
        throw std::runtime_error("Can't call datasource method: no reference to the object");

      l_.getglobal(desc_table_name().c_str());
      auto i = 1;
      if (l_.istable(-1)) {
        l_.pushnumber(ref_key_);
        l_.rawget(-2);
        ++i;
        l_.pushstring(name);
        l_.rawget(-2); // Push function from table to stack
        ++i;
        if (l_.isfunction(-1)) {
          l_.pushvalue(-2); // Push 'this'
          l_.pushnumber(idx);
          l_.pcall(2, 1, 0);
          ++i;
          auto rslt = l_.at<double>(-1)();
          l_.pop(i - 1);  // Function popped by pcall
          return rslt;
        } else {
          l_.pop(i);
          throw std::runtime_error("Call to datasource method failed: " + std::string(name) + " method is not a function in object table");
        }
      } else {
        l_.pop(i); 
        throw std::runtime_error("Call to datasource method failed: " + desc_table_name() + " is not a table in lua globals");
      }
    }
  };
  
}
