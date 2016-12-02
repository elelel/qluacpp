#include "api.hpp"

qlua::api::api(lua::state& l) :
  lua_(l),
  constants_(l) {
  }

qlua::api::api(const qlua::api& other) :
  lua_(other.lua_),
  constants_(other.constants_) {
}

qlua::api::api(qlua::api&& other) :
  lua_(std::move(other.lua_)),
  constants_(std::move(other.lua_)) {
}

void qlua::api::api::swap(qlua::api& other) {
  std::swap(lua_, other.lua_);
  std::swap(constants_, other.constants_);
}
