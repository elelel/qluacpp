#include "api.hpp"

qlua::qlua_constants::qlua_constants(lua::state& l) :
  l_(l) {
}

int qlua::qlua_constants::QTABLE_INT_TYPE() const {
  return l_.get_field<int>("QTABLE_INT_TYPE", LUA_GLOBALSINDEX);
}
         
int qlua::qlua_constants::QTABLE_DOUBLE_TYPE() const {
  return l_.get_field<int>("QTABLE_DOUBLE_TYPE", LUA_GLOBALSINDEX);
}

int qlua::qlua_constants::QTABLE_INT64_TYPE() const {
  return l_.get_field<int>("QTABLE_INT64_TYPE", LUA_GLOBALSINDEX);
}

int qlua::qlua_constants::QTABLE_CACHED_STRING_TYPE() const {
  return l_.get_field<int>("QTABLE_CACHED_STRING_TYPE", LUA_GLOBALSINDEX);
}

int qlua::qlua_constants::QTABLE_TIME_TYPE() const {
  return l_.get_field<int>("QTABLE_TIME_TYPE", LUA_GLOBALSINDEX);
}

int qlua::qlua_constants::QTABLE_DATE_TYPE() const {
  return l_.get_field<int>("QTABLE_DATE_TYPE", LUA_GLOBALSINDEX);
}

int qlua::qlua_constants::QTABLE_STRING_TYPE() const { 
  return l_.get_field<int>("QTABLE_STRING_TYPE", LUA_GLOBALSINDEX);
}
