#pragma once

void getDepo(const std::string& client_code,
             const std::string& firmid,
             const std::string& sec_code,
             const std::string& trdaccid,
             std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::depo_limits_getDepo>>&)> lambda) const {
  api::getDepo(client_code.c_str(), firmid.c_str(), sec_code.c_str(), trdaccid.c_str(), lambda);
}

void getDepo(const char* client_code,
             const char* firmid,
             const char* sec_code,
             const char* trdaccid,
             std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::depo_limits_getDepo>>&)> lambda) const {
  api::getDepo(client_code, firmid, sec_code, trdaccid, lambda);
}

void getDepoEx(const std::string& firmid,
               const std::string& client_code,
               const std::string& sec_code,
               const std::string& trdaccid,
               const int limit_kind,
               std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::depo_limits>>&)> lambda) const {
  api::getDepoEx(firmid.c_str(), client_code.c_str(), sec_code.c_str(), trdaccid.c_str(), limit_kind, lambda);
}

void getDepoEx(const char* firmid,
               const char* client_code,
               const char* sec_code,
               const char* trdaccid,
               const int limit_kind,
               std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::depo_limits>>&)> lambda) const {
  api::getDepoEx(firmid, client_code, sec_code, trdaccid, limit_kind, lambda);
}

void getMoney(const std::string& client_code,
              const std::string& firmid,
              const std::string& tag,
              const std::string& currcode,
              std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::money_limits_getMoney>>&)> lambda) const {
  api::getMoney(client_code.c_str(), firmid.c_str(), tag.c_str(), currcode.c_str(), lambda);
}

void getMoney(const char* client_code,
              const char* firmid,
              const char* tag,
              const char* currcode,
              std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::money_limits_getMoney>>&)> lambda) const {
  api::getMoney(client_code, firmid, tag, currcode, lambda);
}

void getMoneyEx(const std::string& firmid,
                const std::string& client_code,
                const std::string& tag,
                const std::string& currcode,
                const int limit_kind,
                std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::money_limits>>&)> lambda) const {
  api::getMoneyEx(firmid.c_str(), client_code.c_str(), tag.c_str(), currcode.c_str(), limit_kind, lambda);
}

void getMoneyEx(const char* firmid,
                const char* client_code,
                const char* tag,
                const char* currcode,
                const int limit_kind,
                std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::money_limits>>&)> lambda) const {
  api::getMoneyEx(firmid, client_code, tag, currcode, limit_kind, lambda);
}

void getFuturesLimit(const std::string& firmid,
                     const std::string& trdaccid,
                     const int limit_type,
                     const std::string& currcode,
                     std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::futures_client_limits>>&)> lambda) const {
  api::getFuturesLimit(firmid.c_str(), trdaccid.c_str(), limit_type, currcode.c_str(), lambda);
}

void getFuturesLimit(const char* firmid,
                     const char* trdaccid,
                     const int limit_type,
                     const char* currcode,
                     std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::futures_client_limits>>&)> lambda) const {
  api::getFuturesLimit(firmid, trdaccid, limit_type, currcode, lambda);
}

void getFuturesHolding(const std::string& firmid,
                       const std::string& trdaccid,
                       const std::string& sec_code,
                       const int type,
                       std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::futures_client_holding>>&)> lambda) const {
  api::getFuturesHolding(firmid.c_str(), trdaccid.c_str(), sec_code.c_str(), type, lambda);
}

void getFuturesHolding(const char* firmid,
                       const char* trdaccid,
                       const char* sec_code,
                       const int type,
                       std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::futures_client_holding>>&)> lambda) const {
  api::getFuturesHolding(firmid, trdaccid, sec_code, type, lambda);
}

void getQuoteLevel2(const std::string& class_code,
                    const std::string& sec_code,
                    std::function<void(const ::qlua::table::level2_quotes &)> lambda) const {
  api::getQuoteLevel2(class_code.c_str(), sec_code.c_str(), lambda);
}

void getQuoteLevel2(const char* class_code,
                    const char* sec_code,
                    std::function<void(const ::qlua::table::level2_quotes &)> lambda) const {
  api::getQuoteLevel2(class_code, sec_code, lambda);
}

void getSecurityInfo(const std::string& class_code,
                     const std::string& sec_code,
                     std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::securities>>&)> lambda) const {
  api::getSecurityInfo(class_code.c_str(), sec_code.c_str(), lambda);
}


void getSecurityInfo(const char* class_code,
                     const char* sec_code,
                     std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::securities>>&)> lambda) const {
  api::getSecurityInfo(class_code, sec_code, lambda);
}

std::tuple<unsigned int, double> CalcBuySell(const std::string& class_code,
                                             const std::string& sec_code,
                                             const std::string& client_code,
                                             const std::string& account,
                                             const double price,
                                             const bool is_buy,
                                             const bool is_market) {
  return api::CalcBuySell(class_code.c_str(), sec_code.c_str(), client_code.c_str(), account.c_str(), price, is_buy, is_market);
}

std::tuple<unsigned int, double> CalcBuySell(const char* class_code,
                                             const char* sec_code,
                                             const char* client_code,
                                             const char* account,
                                             const double price,
                                             const bool is_buy,
                                             const bool is_market) {
  return api::CalcBuySell(class_code, sec_code, client_code, account, price, is_buy, is_market);
}

void getPortfolioInfo(const std::string& firm_id,
                      const std::string& client_code,
                      std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::portfolio_info_getPortfolioInfo>>&)> lambda) const {
  api::getPortfolioInfo(firm_id.c_str(), client_code.c_str(), lambda);
}

void getPortfolioInfo(const char* firm_id,
                      const char* client_code,
                      std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::portfolio_info_getPortfolioInfo>>&)> lambda) const {
  api::getPortfolioInfo(firm_id, client_code, lambda);
}

void getPortfolioInfoEx(const std::string& firm_id,
                        const std::string& client_code,
                        const int limit_kind,
                        std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::portfolio_info_getPortfolioInfoEx>>&)> lambda) const {
  api::getPortfolioInfoEx(firm_id.c_str(), client_code.c_str(), limit_kind, lambda);
}

void getPortfolioInfoEx(const char* firm_id,
                        const char* client_code,
                        const int limit_kind,
                        std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::portfolio_info_getPortfolioInfoEx>>&)> lambda) const {
  api::getPortfolioInfoEx(firm_id, client_code, limit_kind, lambda);
}

void getBuySellInfo(const std::string& firm_id,
                    const std::string& client_code,
                    const std::string& class_code,
                    const std::string& sec_code,
                    const double price,
                    std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::buy_sell_info_getBuySellInfo>>&)> lambda) const {
  api::getBuySellInfo(firm_id.c_str(), client_code.c_str(), class_code.c_str(), sec_code.c_str(), price, lambda);
}

void getBuySellInfo(const char* firm_id,
                    const char* client_code,
                    const char* class_code,
                    const char* sec_code,
                    const double price,
                    std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::buy_sell_info_getBuySellInfo>>&)> lambda) const {
  api::getBuySellInfo(firm_id, client_code, class_code, sec_code, price, lambda);
}

void getBuySellInfoEx(const std::string& firm_id,
                      const std::string& client_code,
                      const std::string& class_code,
                      const std::string& sec_code,
                      const double price,
                      std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::buy_sell_info_getBuySellInfoEx>>&)> lambda) const {
  api::getBuySellInfoEx(firm_id.c_str(), client_code.c_str(), class_code.c_str(), sec_code.c_str(), price, lambda);
}

void getBuySellInfoEx(const char* firm_id,
                      const char* client_code,
                      const char* class_code,
                      const char* sec_code,
                      const double price,
                      std::function<void(const ::lua::entity<::lua::type_policy<::qlua::table::buy_sell_info_getBuySellInfoEx>>&)> lambda) const {
  api::getBuySellInfoEx(firm_id, client_code, class_code, sec_code, price, lambda);
}
