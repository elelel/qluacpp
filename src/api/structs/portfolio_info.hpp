#pragma once

namespace qlua {
  struct portfolio_info {
    std::string is_leverage;
    std::string in_assets;
    std::string leverage;
    std::string open_limit;
    std::string val_short;
    std::string val_long;
    std::string val_long_margin;
    std::string val_long_asset;
    std::string assets;
    std::string cur_leverage;
    std::string margin;
    std::string lim_all;
    std::string av_lim_all;
    std::string locked_buy;
    std::string locked_buy_margin;
    std::string locked_buy_assset;
    std::string locked_sell;
    std::string locked_value_coef;
    std::string in_all_assets;
    std::string all_assets;
    std::string profit_loss;
    std::string rate_change;
    std::string lim_buy;
    std::string lim_sell;
    std::string lim_non_margin;
    std::string lim_buy_asset;
    std::string val_short_net;
    std::string val_long_net;
    std::string total_money_val;
    std::string total_locked_money;
    std::string haircuts;
    std::string assets_without_hc;
    std::string status_coef;
    std::string varmargin;
    std::string go_for_positions;
    std::string go_for_orders;
    std::string rate_futures;
    std::string is_qual_client;
    std::string is_futures;
    std::string curr_tag;
  };

  struct portfolio_info_ex : public portfolio_info {
    std::string init_margin;
    std::string min_margin;
    std::string corrected_margin;
    std::string client_type;
    std::string portfolio_value;
    std::string start_limit_open_pos;
    std::string total_limit_open_pos;
    std::string limit_open_pos;
    std::string used_lim_open_pos;
    std::string acc_var_margin;
    std::string opt_liquid_cost;
    std::string fut_asset;
    std::string fut_total_asset;
    std::string fut_debt;
    std::string fut_rate_asset;
    std::string fut_rate_go;
    std::string planed_rate_go;
    std::string cash_leverage;
    std::string fut_position_type;
    std::string fur_accrued_int;
  };
}

namespace lua {
  template <>
  struct stack_reader<qlua::portfolio_info> {
    inline static qlua::portfolio_info read(lua::state l, int idx = -1) {
      qlua::portfolio_info r;
      l.get_field_into("is_leverage", r.is_leverage);
      l.get_field_into("in_assets", r.in_assets);
      l.get_field_into("leverage", r.leverage);
      l.get_field_into("open_limit", r.open_limit);
      l.get_field_into("val_short", r.val_short);
      l.get_field_into("val_long", r.val_long);
      l.get_field_into("val_long_margin", r.val_long_margin);
      l.get_field_into("val_long_asset", r.val_long_asset);
      l.get_field_into("assets", r.assets);
      l.get_field_into("cur_leverage", r.cur_leverage);
      l.get_field_into("margin", r.margin);
      l.get_field_into("lim_all", r.lim_all);
      l.get_field_into("av_lim_all", r.av_lim_all);
      l.get_field_into("locked_buy", r.locked_buy);
      l.get_field_into("locked_buy_margin", r.locked_buy_margin);
      l.get_field_into("locked_buy_assset", r.locked_buy_assset);
      l.get_field_into("locked_sell", r.locked_sell);
      l.get_field_into("locked_value_coef", r.locked_value_coef);
      l.get_field_into("in_all_assets", r.in_all_assets);
      l.get_field_into("all_assets", r.all_assets);
      l.get_field_into("profit_loss", r.profit_loss);
      l.get_field_into("rate_change", r.rate_change);
      l.get_field_into("lim_buy", r.lim_buy);
      l.get_field_into("lim_sell", r.lim_sell);
      l.get_field_into("lim_non_margin", r.lim_non_margin);
      l.get_field_into("lim_buy_asset", r.lim_buy_asset);
      l.get_field_into("val_short_net", r.val_short_net);
      l.get_field_into("val_long_net", r.val_long_net);
      l.get_field_into("total_money_val", r.total_money_val);
      l.get_field_into("total_locked_money", r.total_locked_money);
      l.get_field_into("haircuts", r.haircuts);
      l.get_field_into("assets_without_hc", r.assets_without_hc);
      l.get_field_into("status_coef", r.status_coef);
      l.get_field_into("varmargin", r.varmargin);
      l.get_field_into("go_for_positions", r.go_for_positions);
      l.get_field_into("go_for_orders", r.go_for_orders);
      l.get_field_into("rate_futures", r.rate_futures);
      l.get_field_into("is_qual_client", r.is_qual_client);
      l.get_field_into("is_futures", r.is_futures);
      l.get_field_into("curr_tag", r.curr_tag);
      return r;
    }
  };

  template <>
  struct stack_reader<qlua::portfolio_info_ex> {
    inline static qlua::portfolio_info_ex read(lua::state l, int idx = -1) {
      qlua::portfolio_info_ex r;

      l.get_value_into(static_cast<qlua::portfolio_info&>(r));
      
      l.get_field_into("init_margin", r.init_margin);
      l.get_field_into("min_margin", r.min_margin);
      l.get_field_into("corrected_margin", r.corrected_margin);
      l.get_field_into("client_type", r.client_type);
      l.get_field_into("portfolio_value", r.portfolio_value);
      l.get_field_into("start_limit_open_pos", r.start_limit_open_pos);
      l.get_field_into("total_limit_open_pos", r.total_limit_open_pos);
      l.get_field_into("limit_open_pos", r.limit_open_pos);
      l.get_field_into("used_lim_open_pos", r.used_lim_open_pos);
      l.get_field_into("acc_var_margin", r.acc_var_margin);
      l.get_field_into("opt_liquid_cost", r.opt_liquid_cost);
      l.get_field_into("fut_asset", r.fut_asset);
      l.get_field_into("fut_total_asset", r.fut_total_asset);
      l.get_field_into("fut_debt", r.fut_debt);
      l.get_field_into("fut_rate_asset", r.fut_rate_asset);
      l.get_field_into("fut_rate_go", r.fut_rate_go);
      l.get_field_into("planed_rate_go", r.planed_rate_go);
      l.get_field_into("cash_leverage", r.cash_leverage);
      l.get_field_into("fut_position_type", r.fut_position_type);
      l.get_field_into("fur_accrued_int", r.fur_accrued_int);

      return r;
    }
  };
}
