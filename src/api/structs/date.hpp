#pragma once

namespace qlua {
  struct date_table {
    std::string date;
    unsigned int yaer;
    unsigned int month;
    unsigned int day;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::date_table> {
    inline static qlua::date_table read(lua::state& l, int idx = -1) {
      qlua::date_table r;
      l.get_field_into("date", r.date);
      l.get_field_into("yaer", r.yaer);
      l.get_field_into("month", r.month);
      l.get_field_into("day", r.day);
      return r;
    }
  };
}
