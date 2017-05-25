#pragma once

#include "../structs/function_results.hpp"

// getClassesList - функция для получения списка кодов классов, полученных с сервера в ходе сеанса связи
QLUACPP_DETAIL_API_FUNCTION2(const char*, getClassesList)
// getClassInfo - функция для получения информации о классе
QLUACPP_DETAIL_API_FUNCTION_RES1_APPLY4(::qlua::table::class_info_getClassInfo,
                                        getClassInfo,
                                        const char*, class_name
                                        )

// getClassSecurities - функция для получения списка кодов бумаг для списка классов, заданного списком кодов 
QLUACPP_DETAIL_API_FUNCTION4(const char*,
                             getClassSecurities,
                             const char*, class_name)

