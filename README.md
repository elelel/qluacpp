# qluacpp
C++ interface for Quik trading terminal via lua bindings

# Requirements
- CMake
- lua5.1 library (search is performed with CMake FindModule)
- Modern C++ compiler (C++11 compliant, tested with Mingw64 GCC 6.2.0 and VS 2015 14.0)

# Creating project
Create CMakeLists.txt for your new project, linking the standard Lua C lib. Then add:
```
set (QLUACPP /path/to/qluacpp)
if (NOT TARGET qluacpp)
  add_subdirectory(${QLUACPP} qluacpp)
endif()
```
Then run the usual build commands:
```
mkdir $YOUR_BUILD_DIR && cd $YOUR_BUILD_DIR
cmake -G "MSYS Makefiles" $YOUR_PROJECT_PATH  # (-G "NMake Makefiles", or any other Makfiles target for the compiler you use)
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

// Handler for OnInit Quik callback
void OnInit(lua::state& l, const char* script_path) {
  // Do some init...
}

// Handler for OnAllTrade Quik callback
void OnAllTrade(lua::state& l, const qlua::alltrade& data) {
  // Create extended QluaCpp API object. 
  qlua::extended_api q(l);
  // Call message Quik LUA function
  q.message(std::string("OnAllTrade: ") + data.sec_code + std::to_string(data.price));
}

// Handler for OnQuote Quik callback
void OnQuote(lua::state& l, const char* class_code, const char* sec_code) {
  // Print depth for currently opened depth windows (aka "level 2 quotes"
  qlua::extended_api q(l);
  if (class_code == qlua::classcode::TQBR::name()) {
    // Get quote info with normal API, will work on standard API object
    auto quote = q.getQuoteLevel2(class_code, sec_code);
    // Same with Extended API, with typechecked class code, works on extended API object
    auto quote_tl = q.getQuoteLevel2<qlua::classcode::TQBR>(sec_code);
    ss << "Quotes for " << sec_code << " (class " << class_code << "):\n"
       << "  Bid:\n";
    for (const auto& r : quote.bid) ss << "    " << r.quantity << " - " << r.price << "\n";
    ss << "  Offer:\n";
    for (const auto& r : quote.offer) ss << "    " << r.quantity << " - " << r.price << "\n";
    q.message(ss.str());
  }
}

// Handler for main Quik callback
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
    // Create LUA state object (luacpp library) with plain LUA state
    lua::state l(L);
    // Create QLUA API
    qlua::extended_api q(l);
    // Register LUA library
    luaL_openlib(L, "libmybot", ls_lib, 0);
    // Register QLUA standard callbacks
    q.set_callback<qlua::callback::main>(my_main);
    q.set_callback<qlua::callback::OnInit>(OnInit);
    q.set_callback<qlua::callback::OnQuote>(OnQuote);
    q.set_callback<qlua::callback::OnAllTrade>(OnAllTrade);
    return 0;
  }
}
```

mybot.lua
``` lua
require "libmybot"
```

# License
GPL v3.0
