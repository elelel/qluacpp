#pragma once

namespace qlua {
  struct param {
    enum class TYPE {
      DOUBLE = 1,
      LONG,
      CHAR,
      ENUM,
      TIME,
      DATE
    };
    
    TYPE param_type;
    union {
      double double_value;
      long int long_value;
      unsigned int enum_value;
    };
    std::string param_image;
    unsigned int result;

    template <typename value_t>
    value_t& param_value() {
      switch (param_type) {
      case qlua::param::TYPE::DOUBLE :
        return double_value;
      case qlua::param::TYPE::LONG :
        return long_value;
      case qlua::param::TYPE::CHAR :
        return int(0);
      case qlua::param::TYPE::ENUM :
        return long_value;
      case qlua::param::TYPE::DATE :
        return long_value;
      case qlua::param::TYPE::TIME :
        return long_value;
      }
    }
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::param> {
    inline static qlua::param read(lua::state& l, int idx = -1) {
      qlua::param r;
      r.param_type = static_cast<qlua::param::TYPE>(l.get_field<unsigned int>("param_type"));
      switch (r.param_type) {
      case qlua::param::TYPE::DOUBLE :
        l.get_field_into("param_value", r.double_value);
        break;
      case qlua::param::TYPE::LONG :
        l.get_field_into("param_value", r.long_value);
        break;
      case qlua::param::TYPE::CHAR :
        r.long_value = 0;
        break;
      case qlua::param::TYPE::ENUM :
        l.get_field_into("param_value", r.long_value);
        break;
      case qlua::param::TYPE::DATE :
        l.get_field_into("param_value", r.long_value);
        break;
      case qlua::param::TYPE::TIME :
        l.get_field_into("param_value", r.long_value);
        break;
      }
      l.get_field_into("param_image", r.param_image);
      l.get_field_into("result", r.result);
      return r;
    }
  };
}
