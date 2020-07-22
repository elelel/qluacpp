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
  std::string name;
  q.getSecurityInfo("TQBR", "SBER",
                    [&name] (const auto& sec_info) {     // C++14 style lambda
                      name = sec_info().name();
                      return 1;  // How many stack items should be cleaned up (poped)
                    });
  std::string text = "qluacpp: Hello, world! Ticker's SBER name is " + name;                  
  q.message(msg.c_str());  
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

## Преимущества
- Позволяет писать плагины к терминалу Quik на типизированном языке с развитой экосистемой
и избежать программирования на сложном для отладке языке Lua
- Предельная быстрота: в отличие от других интерфейсов к Quik данные не пересылаются и в
большинстве случаев даже не копируются, чтение осуществляется непосредственно через ссылки
на память терминала. В ряде случаев даже быстрее, чем доступ через встроенный интерпретатор
Lua (благодаря C-интерфейсу к API Lua, предоставляющему больше возможностей, чем языковые средства).

## Requirements / Требования

- Lua 5.1 or Lua 5.3 library (depending on target Quik)
- C++17-compliant compiler (C++17 compliant, tested with VS 2017 15.0)

## Usage example / Пример использования

See [tutorials](https://github.com/elelel/qluacpp-tutorial) for code examples, as well as step by step instruction for creating qluacpp projects.

[Примеры](https://github.com/elelel/qluacpp-tutorial) содержат пошаговые инструкции и исходные коды небольших плагинов

## License / Лицензия

GPL v3.0.

Distribute your source code if you distribute the binaries.

Если распространяете бинарники, прилагайте и исходный код.

