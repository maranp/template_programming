#pragma once

class SumPolicy {
public:
  template <typename T1, typename T2>
  static T1 accumulate(T1& a, T2 const& b) {
    return a += b;
  }
};
