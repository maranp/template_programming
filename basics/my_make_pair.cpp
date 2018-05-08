/*
 * my_make_pair.cpp
 *
 *  Created on: 08-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T1, typename T2>
constexpr std::pair<std::decay_t<T1>, std::decay_t<T2>> my_make_pair(T1&& a, T2&& b) {
  return std::pair<std::decay_t<T1>, std::decay_t<T2>>(forward<T1>(a), forward<T2>(b));
}

int main() {
  auto p = my_make_pair(10, 20);
  cout << p.first << " " << p.second << endl;
}


