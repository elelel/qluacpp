#pragma once

// getParamEx - Функция предназначена для получения значений всех параметров биржевой информации из Таблицы текущих торгов.
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY8(::qlua::table::current_trades_getParamEx,
                            getParamEx,
                            const char*, class_code,
                            const char*, sec_code,
                            const char*, param_name
                            )
// getParamEx2 - Функция предназначена для получения значений всех параметров биржевой информации из Таблицы текущих торгов с возможностью в дальнейшем отказаться от получения определенных параметров, заказанных с помощью функции ParamRequest.
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY8(::qlua::table::current_trades_getParamEx,
                            getParamEx2,
                            const char*, class_code, // код класса;
                            const char*, sec_code, // код бумаги; 
                            const char*, param_name // код параметра. 
                            )
