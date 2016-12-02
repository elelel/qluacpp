#pragma once

namespace qlua {
  struct class_info {
    std::string firmid;
    std::string name;
    std::string code;
    unsigned int npars;
    unsigned int nsecs;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::class_info> {
    inline static qlua::class_info read(const lua::state& l, int idx = -1) {
      qlua::class_info r;
      l.get_field_into("firmid", r.firmid);
      l.get_field_into("name", r.name);
      l.get_field_into("code", r.code);
      l.get_field_into("npars", r.npars);
      l.get_field_into("nsecs", r.nsecs);
      return r;
    }
  };
}
