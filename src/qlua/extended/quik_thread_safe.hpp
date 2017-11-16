#pragma once

/* Call a function within Quik's critical section for this script (for thread safety).
   sync_name - name of the sync object, has to be unique in global namespace
   function_name_in_lua - name of the function to call with prototype: bool func(T, T)
   In C++/QLuaCPP it corresponds, for example to:
   std::tuple<bool> func(const lua::state& l,
   ::lua::entity<::lua::type_policy<const int>>,
   ::lua::entity<::lua::type_policy<const int>>)
   Two int parameters are unused but must be present in the declaration.
   The value of returned bool is unimportant (preferably true).
   Declare/register it as usual with LuaCPP macros/calls.
*/
static void thread_safe_exec(const lua::state& l,
                             const char* sync_name, 
                             const std::string& function_name_in_lua) {
  l.getglobal("table");
  int i = 1;
  if (l.istable(-1)) {
    l.getfield(-1, "ssort");
    ++i;
    if (l.isfunction(-1)) {
      l.getglobal(sync_name);
      ++i;
      // Create table if doesn't exist
      if (l.isnil(-1)) {
        l.pop(1);
        --i;
        l.newtable();
        l.setglobal(sync_name);
        l.getglobal(sync_name);
        ++i;
        if (l.istable(-1)) {
          l.push<int>(1);
          l.rawseti(-2, 1);
          l.push<int>(2);
          l.rawseti(-2, 2);
        } else {
          l.pop(i);
          throw std::runtime_error("quik_thread_safe - failed to create table");
        }
      }

      if (l.istable(-1)) {
        auto len = luaL_getn(l.C_state(), -1);
        if (len == 2) {
          l.getglobal(function_name_in_lua.c_str());
          ++i;
          if (l.isfunction(-3) && l.isfunction(-1)) {
            l.pcall(2, 0, 0);
            i -= 3;
            l.pop(i);
          } else {
            l.pop(i);
            throw std::runtime_error("quik_thread_safe - function to run is not registered in globals list");
          }
        } else {
          l.pop(i);
          throw std::runtime_error("quik_thread_safe - incorrect table size");
        }
      } else {
        l.pop(i);
        throw std::runtime_error("quik_thread_safe - table name is occupied by a symbol of another type");
      }
    } else {
      l.pop(i);
      throw std::runtime_error("quik_thread_safe - function ssort not found in the table");
    }
  } else {
    l.pop(i);
    throw std::runtime_error("quik_thread_safe - library table is not loaded");
  }
}
    
