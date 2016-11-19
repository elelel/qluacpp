#include "quote_level_2.hpp"

qlua::quote_level_2::quote_level_2() {
}

qlua::quote_level_2::quote_level_2(const type& other) :
  bid(other.bid),
  offer(other.offer) {
}

qlua::quote_level_2::quote_level_2(type&& other) :
  bid(std::move(other.bid)),
  offer(std::move(other.offer)) {
}

void qlua::quote_level_2::swap(type& other) {
  std::swap(bid, other.bid);
  std::swap(offer, other.offer);
}

auto qlua::quote_level_2::operator=(const type& other) -> type& {
  type tmp(other);
  swap(tmp);
  return *this;
}

const size_t qlua::quote_level_2::bid_count() {
  return bid.size();
}

const size_t qlua::quote_level_2::offer_count() {
  return offer.size();
}

