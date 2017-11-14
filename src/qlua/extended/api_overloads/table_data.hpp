#pragma once

unsigned int getNumberOf(const std::string& TableName) { return api::getNumberOf(TableName.c_str()); }
unsigned int getNumberOf(const char* TableName) { return api::getNumberOf(TableName); }

template <typename Table>
unsigned int getNumberOf() const {
  return api::getNumberOf(::qlua::table::detail::name_for_type<Table>::value());
}

