/*
 * use_plus2.cpp
 *
 *  Created on: 19-May-2018
 *      Author: maran
 */

#include "plus2.hpp"

template <typename T1, typename T2>
typename plus_type<T1, T2>::type plus(T1 a, T2 b) {
  return a + b;
}

struct t {};
struct u {};

int operator+(t a, u b) {
  return 0;
}

int main() {
  int a = 5, b = 10;
  float f = 2.33f;
  cout << plus(a, b) << endl;
  cout << plus(a, f) << endl;
  cout << type_print_pretty<decltype(plus(t{}, u{}))>() << endl;
}


