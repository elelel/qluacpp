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

void qlua::alltrade::swap(alltrade& other) {
  std::swap(trade_num, other.trade_num);
  std::swap(flags, other.flags);
  std::swap(price, other.price);
  std::swap(qty, other.qty);
  std::swap(value, other.value);
  std::swap(accruedint, other.accruedint);
  std::swap(yield, other.yield);
  std::swap(settlecode, other.settlecode);
  std::swap(reporate, other.reporate);
  std::swap(repovalue, other.repovalue);
  std::swap(repo2value, other.repo2value);
  std::swap(repoterm, other.repoterm);
  std::swap(sec_code, other.sec_code);
  std::swap(class_code, other.class_code);
  std::swap(datetime, other.datetime);
  std::swap(period, other.period);
  std::swap(open_interest, other.open_interest);
  std::swap(exchange_code, other.exchange_code);
}

qlua::alltrade& qlua::alltrade::operator=(cosnt qlua::alltrade& other) {
  alltrade tmp(other);
  swap(tmp);
  return *this;
}

bool qlua::alltrade::is_sell() const {
  return (flags & 0x1) != 0;
}

bool qlua::alltrade::is_buy() const {
  return (flags & 0x2) != 0;
}

