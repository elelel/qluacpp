cmake_minimum_required(VERSION 3.4.0)
project(qluacpp_test)

get_filename_component(TOP_DIR "${CMAKE_CURRENT_SOURCE_DIR}" PATH)
set(CATCH "${TOP_DIR}/contrib/Catch")
set(SRC "${TOP_DIR}/src")

message("Catch dir ${CATCH}")

if (NOT LUACPP_LUA_LIBRARIES)
  find_package(Lua51)
  if (NOT LUA_LIBRARIES)
    message( FATAL_ERROR "Please set LUACPP_LUA_LIBRARIES variable to your Lua library file. For example:\n cmake -DLUACPP_LUA_LIBRARIES=c:\\lua\\lua5.1.lib ...")
  endif()
  set(LUACPP_LUA_LIBRARIES ${LUA_LIBRARIES})
endif()
message ("Lua library: ${LUACPP_LUA_LIBRARIES}")

if (NOT LUACPP_LUA_INCLUDE_DIR)
  find_package(Lua51)
  if (NOT LUA_INCLUDE_DIR)
    message( FATAL_ERROR "Please set LUACPP_LUA_INCLUDE_DIR variable to the path to your lua.h file. For example:\n cmake -DLUACPP_LUA_INCLUDE_DIR=c:\\lua\\include ...")
  endif()
  set(LUACPP_LUA_INCLUDE_DIR ${LUA_INCLUDE_DIR})
endif()
message ("Lua include dir: ${LUACPP_LUA_INCLUDE_DIR}")

include_directories(
  ${TOP_DIR}/contrib/luacpp/include
  ${TOP_DIR}/include
  ${CATCH}/include
  ${LUACPP_LUA_INCLUDE_DIR}
)

set(TEST_SOURCES
  qluacpp_test.cpp)

add_executable(qluacpp_test
  ${TEST_SOURCES})

target_compile_definitions(qluacpp_test PUBLIC "CATCH_CONFIG_MAIN" "CATCH_CONFIG_COLOUR_NONE")
target_link_libraries(qluacpp_test ${LUACPP_LUA_LIBRARIES})
add_test(CommonTests qluacpp_test)
