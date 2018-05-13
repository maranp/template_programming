#pragma once

template <typename T1, typename T2>
class SumPolicy {
public:
  static T1 accumulate(T1& a, T2 const& b) {
    return a += b;
  }
};
