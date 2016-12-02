#pragma once

namespace qlua {
  struct datetime {
    int mcs{0};
    int ms{0};
    int sec{0};
    int min{0};
    int hour{0};
    int day{0};
    int week_day{0};
    int month{0};
    int year{0};
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::datetime> {
    inline static qlua::datetime read(const lua::state& l, int idx = -1) {
      qlua::datetime r;
      l.get_field_into("mcs", r.mcs);
      l.get_field_into("ms", r.ms);
      l.get_field_into("sec", r.sec);
      l.get_field_into("min", r.min);
      l.get_field_into("hour", r.hour);
      l.get_field_into("day", r.day);
      l.get_field_into("week_day", r.week_day);
      l.get_field_into("month", r.month);
      l.get_field_into("year", r.year);
      return r;
    }
  };
}
