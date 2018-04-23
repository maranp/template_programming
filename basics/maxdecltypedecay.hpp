#pragma once

#include <type_traits>

template <typename T1, typename T2>
auto max(T1 a, T2 b) -> std::decay_t<decltype(true ? a : b)> {
  cout << type_print_pretty<T1>() << endl;
  return a > b ? a : b;
}
