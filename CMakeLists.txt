cmake_minimum_required(VERSION 3.4.0)
project(qluacpp)

find_package(Lua51 REQUIRED)
message ("Lua include directories: ${LUA_INCLUDE_DIR}")
message ("Lua libraries: ${LUA_LIBRARIES}")

set(LUACPP "contrib/luacpp")
include_directories(
  ${LUACPP}/include
  ${LUA_INCLUDE_DIR}
  )
set(SRC "./src")

set(SOURCES
  ${SRC}/api/constants.cpp
  ${SRC}/api/callbacks.cpp
  ${SRC}/api/service.cpp
  ${SRC}/api/tables.cpp
  ${SRC}/api/instruments.cpp
  ${SRC}/api/workplace.cpp
  ${SRC}/api/workplace_tables.cpp
  ${SRC}/api/quotes_level_2.cpp
  ${SRC}/api/current_trades.cpp
  ${SRC}/api/structs/alltrade.cpp
  ${SRC}/api/structs/quote_level_2.cpp
  ${SRC}/extended_api/service.cpp
  ${SRC}/extended_api/instruments.cpp
  ${SRC}/extended_api/workplace.cpp
  )

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++1z")
endif()

if (UNIX)
  if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC ")
  endif()
endif()

add_library(qluacpp ${SOURCES})
target_link_libraries(qluacpp ${LUA_LIBRARIES})
