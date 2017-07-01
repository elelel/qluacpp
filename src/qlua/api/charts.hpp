#pragma once

// getLinesCount - Функция предназначена для получения количества линий в графике (индикаторе) по выбранному идентификатору. 
QLUACPP_DETAIL_API_FUNCTION4(unsigned int,
                             getLinesCount,
                             const char*, tag)
// getNumCandles - Функция предназначена для получения информации о количестве свечек по выбранному идентификатору.
QLUACPP_DETAIL_API_FUNCTION4(unsigned int,
                             getNumCandles,
                             const char*, tag)

// getCandlesByIndex - Функция предназначена для получения информации о свечках по идентификатору
void getCandlesByIndex(const char* tag, // строковый идентификатор графика или индикатора
                       unsigned int line, //  номер линии графика или индикатора. Первая линия имеет номер 0
                       unsigned int first_candle, // индекс первой свечки. Первая (самая левая) свечка имеет индекс 0
                       unsigned int count, // количество запрашиваемых свечек
                       std::function<void
                       (const ::lua::entity<::lua::type_policy<std::vector<::qlua::table::candle>>>&, // таблица, содержащая запрашиваемые свечки
                        const ::lua::entity<::lua::type_policy<unsigned int>>&, // количество свечек в таблице t 
                        const ::lua::entity<::lua::type_policy<const char*>>& // легенда (подпись) графика
                       )> lambda
                       ) const {
  auto f = [&lambda] (const ::lua::state& s) {
    auto l = s.at<const char*>(-1);
    auto n = s.at<unsigned int>(-2);
    auto t = s.at<::std::vector<::qlua::table::candle>>(-3);
    lambda(t, n, l);
    return 3;
  };                                                                  
  l_.call_and_apply(f, 3, "getCandlesByIndex", tag, line, first_candle, count);
}                                                                     


// CreateDataSource - Функция предназначена для создания таблицы Lua и позволяет работать со свечками, полученными с сервера QUIK, а также реагировать на их изменение.
::qlua::data_source CreateDataSource(const char* class_code,
                                     const char* sec_code,
                                     unsigned int interval,
                                     const char* param = nullptr) {
  return ::qlua::data_source(l_, class_code, sec_code, interval, param);
}

