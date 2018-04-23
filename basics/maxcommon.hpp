#pragma once

#include <type_traits>

// note: std::common_type_t decays by itself. SO no need to use decay_t explicitly
template <typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 a, T2 b) {
  cout << type_print_pretty<T1>() << endl;
  return a > b ? a : b;
}
