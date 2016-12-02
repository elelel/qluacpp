#include "extended_api.hpp"

qlua::extended_api::extended_api(lua::state& l) :
  api(l) {
}

qlua::extended_api::extended_api(const extended_api& other) :
  api(other) {
}

qlua::extended_api::extended_api(extended_api&& other) :
  api(std::move(other)) {
}

void qlua::extended_api::swap(extended_api& other) {
  api::swap(other);
}

auto qlua::extended_api::operator=(const extended_api& other) -> extended_api& {
  extended_api tmp(other);
  swap(tmp);
  return *this;
}


