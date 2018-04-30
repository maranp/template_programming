#pragma once

#include "../ihelper.h"

class boolstring {
private:
  string value;
public:
  boolstring(string const &v) : value {v} {}
  template <typename T = string>
  T get() const {
    return value;
  }
};

template<>
inline bool boolstring::get<bool>() const {
  return value == "true" || value == "1" || value == "on";
}
