#pragma once

namespace qlua {
  namespace datatype {

    LUACPP_STATIC_TABLE_BEGIN(date_)
    LUACPP_TABLE_FIELD(date, std::string)
    LUACPP_TABLE_FIELD(year, unsigned int)
    LUACPP_TABLE_FIELD(month, unsigned int)
    LUACPP_TABLE_FIELD(day, unsigned int)
    LUACPP_STATIC_TABLE_END()

    LUACPP_STATIC_TABLE_BEGIN(datetime)
    LUACPP_TABLE_FIELD(mcs, int)
    LUACPP_TABLE_FIELD(ms, int)
    LUACPP_TABLE_FIELD(sec, int)
    LUACPP_TABLE_FIELD(min, int)
    LUACPP_TABLE_FIELD(hour, int)
    LUACPP_TABLE_FIELD(day, int)
    LUACPP_TABLE_FIELD(week_day, int)
    LUACPP_TABLE_FIELD(month, int)
    LUACPP_TABLE_FIELD(year, int)
    LUACPP_STATIC_TABLE_END()
  }
}
