#pragma once

namespace qlua {
  struct buy_sell_info {
    std::string is_margin_sec;
    std::string is_asset_sec;
    std::string balance;
    std::string can_buy;
    std::string can_sell;
    std::string position_valuation;
    std::string value;
    std::string open_value;
    std::string lim_long;
    std::string long_coef;
    std::string lim_short;
    std::string short_coef;
    std::string value_coef;
    std::string open_value_coef;
    std::string share;
    std::string short_wa_price;
    std::string long_wa_price;
    std::string profit_loss;
    std::string spread_hc;
    std::string can_buy_own;
    std::string can_sell_own;
  };

  struct buy_sell_info_ex : public buy_sell_info {
    int limit_kind;
    std::string d_long;
    std::string d_min_long;
    std::string d_short;
    std::string d_min_short;
    std::string client_type;
    std::string is_long_allowed;
    std::string is_short_allowed;
  };  
}

namespace lua {
  template <>
  struct stack_reader<qlua::buy_sell_info> {
    inline static qlua::buy_sell_info read(lua::state& l, int idx = -1) {
      qlua::buy_sell_info r;

      l.get_field_into("is_margin_sec", r.is_margin_sec);
      l.get_field_into("is_asset_sec", r.is_asset_sec);
      l.get_field_into("balance", r.balance);
      l.get_field_into("can_buy", r.can_buy);
      l.get_field_into("can_sell", r.can_sell);
      l.get_field_into("position_valuation", r.position_valuation);
      l.get_field_into("value", r.value);
      l.get_field_into("open_value", r.open_value);
      l.get_field_into("lim_long", r.lim_long);
      l.get_field_into("long_coef", r.long_coef);
      l.get_field_into("lim_short", r.lim_short);
      l.get_field_into("short_coef", r.short_coef);
      l.get_field_into("value_coef", r.value_coef);
      l.get_field_into("open_value_coef", r.open_value_coef);
      l.get_field_into("share", r.share);
      l.get_field_into("short_wa_price", r.short_wa_price);
      l.get_field_into("long_wa_price", r.long_wa_price);
      l.get_field_into("profit_loss", r.profit_loss);
      l.get_field_into("spread_hc", r.spread_hc);
      l.get_field_into("can_buy_own", r.can_buy_own);
      l.get_field_into("can_sell_own", r.can_sell_own);
      
      return r;
    }
  };

  template <>
  struct stack_reader<qlua::buy_sell_info_ex> {
    inline static qlua::buy_sell_info_ex read(lua::state& l, int idx = -1) {
      qlua::buy_sell_info_ex r;

      l.get_value_into(static_cast<qlua::buy_sell_info&>(r));
      
      l.get_field_into("limit_kind", r.limit_kind);
      l.get_field_into("d_long", r.d_long);
      l.get_field_into("d_min_long", r.d_min_long);
      l.get_field_into("d_short", r.d_short);
      l.get_field_into("d_min_short", r.d_min_short);
      l.get_field_into("client_type", r.client_type);
      l.get_field_into("is_long_allowed", r.is_long_allowed);
      l.get_field_into("is_short_allowed", r.is_short_allowed);
      
      return r;
    }
  };
}
