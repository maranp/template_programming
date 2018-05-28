#pragma once

#include "../ihelper.h"

// when Base is an empty class,
// the size of BaseMemberPair is just the size of the member
template <typename Base, typename Member>
class BaseMemberPair : Base {
  Member mem;
public:
  BaseMemberPair(Base const& base, Member const& mem_) :
    Base {base}, mem {mem_} {}

  Base const& base() const {
    return static_cast<Base const&>(*this);
  }
  Base& base() {
    return static_cast<Base&>(*this);
  }
  Member const& member() const {
    return mem;
  }
  Member& member() {
    return mem;
  }
};
