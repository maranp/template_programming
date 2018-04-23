#pragma once

#include <type_traits>

template <typename T1, typename T2,
// expects T1 and T2 to have default constructors
//typename RT = std::decay_t<decltype(true ? T1() : T2())>>
typename RT = std::common_type_t<T1, T2>>
RT max(T1 a, T2 b) {
  cout << type_print_pretty<T1>() << endl;
  return a > b ? a : b;
}
