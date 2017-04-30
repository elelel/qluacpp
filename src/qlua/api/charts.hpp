#pragma once

/*
// getLinesCount - Функция предназначена для получения количества линий в графике (индикаторе) по выбранному идентификатору. 
 NUMBER getLinesCount (STRING tag)
// getNumCandles - Функция предназначена для получения информации о количестве свечек по выбранному идентификатору.
 NUMBER getNumCandles (STRING tag)  
// getCandlesByIndex - Функция предназначена для получения информации о свечках по идентификатору
 TABLE t, NUMBER n, STRING l getCandlesByIndex (STRING tag, NUMBER line, NUMBER first_candle, NUMBER count)   
// CreateDataSource - Функция предназначена для создания таблицы Lua и позволяет работать со свечками, полученными с сервера QUIK, а также реагировать на их изменение.
 TABLE data_source, STRING error_desc CreateDataSource (STRING class_code, STRING sec_code, NUMBER interval, [, STRING param])   
// SetUpdateCallback -
   BOOLEAN res SetUpdateCallback (FUNCTION callback_function // В качестве параметра принимает функцию обратного вызова. 
                                )   
// Функции O, H, L, C, V, T  - Функции в качестве параметра принимают индекс свечи и возвращают соответствующее значение.
   Open = ds:O(1)
High = ds:H(1)
Low = ds:L(1)
Close = ds:C(1)
Volume = ds:V(1)
week_day = ds:T(1).week_day
count = ds:T(1).count

// Size - Функция возвращает текущее количество свечек в источнике данных.
   NUMBER Size(ds) 
// Close - Функция закрывает источник данных, и терминал прекращает получать данные с сервера
   BOOLEAN Close(ds) 
// SetEmptyCallback  - Функция позволяет получать данные с сервера. 
BOOLEAN SetEmptyCallback(ds)
*/
