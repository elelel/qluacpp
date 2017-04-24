#include <catch.hpp>

#include <qluacpp/qlua>

SCENARIO("Static compilation test - instantiate service functions") {
  lua::state s;
  //s.getglobal("message");
  qlua::api q(s);
  q.test();
  q.message("test");
}
