#include "alltrade.hpp"

qlua::alltrade::alltrade() {
}

qlua::alltrade::alltrade(const alltrade& other) :
  trade_num(other.trade_num),
  flags(other.flags),
  price(other.price),
  qty(other.qty),
  value(other.value),
  accruedint(other.accruedint),
  yield(other.yield),
  settlecode(other.settlecode),
  reporate(other.reporate),
  repovalue(other.repovalue),
  repo2value(other.repo2value),
  repoterm(other.repoterm),
  sec_code(other.sec_code),
  class_code(other.class_code),
  datetime(other.datetime),
  period(other.period),
  open_interest(other.open_interest),
  exchange_code(other.exchange_code) {
  }

qlua::alltrade::alltrade(alltrade&& other) :
  trade_num(std::move(other.trade_num)),
  flags(std::move(other.flags)),
  price(std::move(other.price)),
  qty(std::move(other.qty)),
  value(std::move(other.value)),
  accruedint(std::move(other.accruedint)),
  yield(std::move(other.yield)),
  settlecode(std::move(other.settlecode)),
  reporate(std::move(other.reporate)),
  repovalue(std::move(other.repovalue)),
  repo2value(std::move(other.repo2value)),
  repoterm(std::move(other.repoterm)),
  sec_code(std::move(other.sec_code)),
  class_code(std::move(other.class_code)),
  datetime(std::move(other.datetime)),
  period(std::move(other.period)),
  open_interest(std::move(other.open_interest)),
  exchange_code(std::move(other.exchange_code)) {
  }

bool qlua::alltrade::is_sell() const {
  return (flags & 0x1) != 0;
}

bool qlua::alltrade::is_buy() const {
  return (flags & 0x2) != 0;
}

