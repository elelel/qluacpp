#pragma once

unsigned int getLinesCount(const std::string& tag) const {
  return api::getLinesCount(tag.c_str());
}

unsigned int getLinesCount(const char* tag) const {
  return api::getLinesCount(tag);
}

unsigned int getNumCandles(const std::string& tag) const {
  return api::getNumCandles(tag.c_str());
}

unsigned int getNumCandles(const char* tag) const {
  return api::getNumCandles(tag);
}

void getCandlesByIndex(const std::string& tag,
                       unsigned int line,
                       unsigned int first_candle,
                       unsigned int count,
                       std::function<void
                       (const ::lua::entity<::lua::type_policy<::qlua::table::candle>>&,
                        const unsigned int index,
                        const ::lua::entity<::lua::type_policy<unsigned int>>&,
                        const ::lua::entity<::lua::type_policy<const char*>>&
                        )> lambda
                       ) const {
  return api::getCandlesByIndex(tag.c_str(), line, first_candle, count, lambda);
}

void getCandlesByIndex(const char* tag,
                       unsigned int line,
                       unsigned int first_candle,
                       unsigned int count,
                       std::function<void
                       (const ::lua::entity<::lua::type_policy<::qlua::table::candle>>&,
                        const unsigned int index,
                        const ::lua::entity<::lua::type_policy<unsigned int>>&,
                        const ::lua::entity<::lua::type_policy<const char*>>&
                        )> lambda
                       ) const {
  return api::getCandlesByIndex(tag, line, first_candle, count, lambda);
}

::qlua::data_source CreateDataSource(const std::string& class_code,
                                     const std::string& sec_code,
                                     unsigned int interval) const {
  return api::CreateDataSource(class_code.c_str(), sec_code.c_str(), interval, nullptr);
}

::qlua::data_source CreateDataSource(const std::string& class_code,
                                     const std::string& sec_code,
                                     unsigned int interval,
                                     const std::string& param) const {
  return api::CreateDataSource(class_code.c_str(), sec_code.c_str(), interval, param.c_str());
}

::qlua::data_source CreateDataSource(const char* class_code,
                                     const char* sec_code,
                                     unsigned int interval,
                                     const char* param = nullptr) const {
  return api::CreateDataSource(class_code, sec_code, interval, param);
}

