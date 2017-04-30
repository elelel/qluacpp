#pragma once

// ParamRequest - заказывает получение параметров Таблицы текущих торгов.
QLUACPP_DETAIL_API_FUNCTION8(bool, // В случае успешного завершения функция возвращает «true», иначе – «false». 
                             ParamRequest,
                             const char*, class_code, // код класса; 
                             const char*, sec_code, // код бумаги; 
                             const char*, db_name // код параметра
                             )
// CancelParamRequest - отменяет заказ на получение параметров Таблицы текущих торгов. 
QLUACPP_DETAIL_API_FUNCTION8(bool, // В случае успешного завершения функция возвращает «true», иначе – «false». 
                             CancelParamRequest,
                             const char*, class_code, // код класса; 
                             const char*, sec_code, // код бумаги; 
                             const char*, db_name // код параметра.
                             )

