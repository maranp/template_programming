#pragma once

#include <type_traits>

// use of T1, T2 before they are introduced is not allowed.
//template <typename RT = std::common_type_t<T1, T2>,
template <typename RT = long,
typename T1, typename T2>
RT max(T1 a, T2 b) {
  cout << type_print_pretty<T1>() << endl;
  return a > b ? a : b;
}
