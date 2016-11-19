# qluacpp
C++ interface for Quik trading terminal via lua bindings

# Requires
- CMake
- lua5.1 library (search is performed with CMake FindModule)
- Modern C++ compiler (C++11 compliant, tested with Mingw64 GCC 6.2.0 and VS 2015 14.0)

# Creating project
Create CMakeLists.txt for the new project, linking the standard Lua C lib. Then add:
```
set (QLUACPP /path/to/qluacpp)
if (NOT TARGET qluacpp)
  add_subdirectory(${QLUACPP} qluacpp)
endif()
```
Then run the usual build commands:
```
mkdir build && cd build
make  # (or nmake)
```

# Usage example
libmybot.cpp
``` c++ 
#define LUA_LIB
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
  #define LUA_BUILD_AS_DLL
#endif

#include <chrono>
#include <thread>
#include <sstream>

#include <qlua>

void OnInit(lua::state& l, const char* script_path) {
  // Do some init...
}

// Print market depth for each TQBR class ticker requested with ParamRequest
void OnQuote(lua::state& l, const char* class_code, const char* sec_code) {
  qlua::extended_api q(l);
  if (class_code == qlua::classcode::TQBR::name()) {
    // Get quote info with normal API
    auto quote = q.getQuoteLevel2(class_code, sec_code);
    // Same with Extended API, with typechecked class code
    auto quote_tl = q.getQuoteLevel2<qlua::classcode::TQBR>(sec_code);
    ss << "Quotes for " << sec_code << " (class " << class_code << ") << ":\n"
       << "  Bid:\n";
    for (const auto& r : quote.bid) ss << "    " << r.quantity << " - " << price "\n";
    ss << "  Offer:\n";
    for (const auto& r : quote.offer) ss << "    " << r.quantity << " - " << price "\n";
    q.message(ss.str());
  }
}

void my_main(lua::state& l) {
  using namespace std::chrono_literals;
  qlua::extended_api q(l);
  q.message("Starting main handler");
  for (int i = 0; i < 5; ++i) {
    q.message("Tick " + std::to_string(i));
    std::this_thread::sleep_for(1s);
  }
  q.message("Terminating main handler");
}

extern "C" {
  LUALIB_API int luaopen_libmybot(lua_State* L) {
    lua::state l(L);
    qlua::extended_api q(l);
    luaL_openlib(L, "libmybot", ls_lib, 0);
    q.set_callback<qlua::callback::main>(my_main);
    q.set_callback<qlua::callback::OnInit)(OnInit);
    q.set_callback<qlua::callback::OnQuote)(OnQuote);
    q.ParamRequest<qlua::classcode::TQBR, qlua::current_trades::param::LAST>("SBER");
    return 0;
  }
}
```

mybot.lua
``` lua
require "libmybot"
```

# License GPL v3.0
