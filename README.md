# QluaCpp

C++ interface for Quik trading terminal via Lua bindings

Интерфейс для написания на C++ плагинов к торговому терминалу Quik через байндинги Lua

```c++
// ... 
#include <qluacpp/qlua>

static struct luaL_reg ls_lib[] = {
  { NULL, NULL }
};

void my_main(lua::state& l) {
  qlua::api q(l);
  q.message("qluacpp: Hello, world!");
}

LUACPP_STATIC_FUNCTION2(main, my_main)
                        
extern "C" {
  LUALIB_API int luaopen_lualib_hello(lua_State *L) {
    lua::state l(L);

    ::lua::function::main().register_in_lua(l, my_main);

    luaL_openlib(L, "lualib_hello", ls_lib, 0);
    return 0;
  }
}
```

## Requirements / Требования

- Lua 5.1 library
- C++11-compliant compiler (C++11 compliant, tested with VS 2017 15.0)

## Usage example / Пример использования

See [tutorials](https://github.com/elelel/qluacpp-tutorial) for code examples, as well as step by step instruction for creating qluacpp projects.

[Примеры](https://github.com/elelel/qluacpp-tutorial) содержат пошаговые инструкции и исходные коды небольших плагинов

## License / Лицензия

GPL v3.0.

Distribute your source code if you distribute the binaries.

Если распространяете бинарники, прилагайте и исходный код.

