#include "constants.hpp"

qlua::qlua_constants::qlua_constants(const lua::state& l) :
  l_(l) {
}

qlua::qlua_constants::qlua_constants(const qlua::qlua_constants& other) :
  l_(other.l_) {
}

qlua::qlua_constants::qlua_constants(qlua::qlua_constants&& other) :
  l_(std::move(other.l_)) {
}

void qlua::qlua_constants::swap(qlua::qlua_constants& other) {
  std::swap(l_, other.l_);
}

auto qlua::qlua_constants::operator=(const qlua::qlua_constants& other) -> qlua_constants& {
  qlua_constants tmp(other);
  swap(tmp);
  return *this;
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
