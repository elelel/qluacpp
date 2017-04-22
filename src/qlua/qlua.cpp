#include "qlua.hpp"

namespace qlua {
  api::api(const lua::state& l) :
    l_(l) {
  }

  api::api(const type& other) :
    l_(other.l_) {
  }

  api::api(type&& other) :
    l_(std::move(other.l_)) {
  }

  void api::swap(type& other) {
    std::swap(l_, other.l_);
  }

  auto api::operator=(const type& other) -> type& {
    type tmp(other);
    swap(tmp);
    return *this;
  }
}
