#pragma once

namespace qlua {
  struct instrument {
    std::string code;
    std::string name;
    std::string short_name;
    std::string class_code;
    std::string class_name;
    double face_value;
    std::string face_unit;
    unsigned int scale;
    unsigned int mat_date;
    unsigned int lot_size;
    std::string isin;
    double min_price_step;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::instrument> {
    inline static qlua::instrument read(lua::state& l, int idx = -1) {
      qlua::instrument r;
      
      l.get_field_into("code", r.code);
      l.get_field_into("name", r.name);
      l.get_field_into("short_name", r.short_name);
      l.get_field_into("class_code", r.class_code);
      l.get_field_into("class_name", r.class_name);
      l.get_field_into("face_value", r.face_value);
      l.get_field_into("face_unit", r.face_unit);
      l.get_field_into("scale", r.scale);
      l.get_field_into("mat_date", r.mat_date);
      l.get_field_into("lot_size", r.lot_size);
      l.get_field_into("isin", r.isin);
      l.get_field_into("min_price_step", r.min_price_step);

      return r;
    }
  };
}
