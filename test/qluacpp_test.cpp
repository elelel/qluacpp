#include <catch.hpp>

#include <qluacpp/qlua>

SCENARIO("Static compilation test - instantiate service functions") {
  lua::state s;
  qlua::api q(s);
  q.message("test");
}
