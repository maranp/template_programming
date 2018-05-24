/*
 * is_valid2.cpp
 *
 *  Created on: 24-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "is_valid.hpp"

// not sure about the requirement of & operator in return type
constexpr auto has_first = is_valid([](auto &&x) -> decltype(&x.first){});

template <typename T>
using has_first_t = decltype(has_first(declval<T>()));

constexpr auto has_less = is_valid([](auto &&x, auto &&y) -> decltype(x < y){});

template <typename T1, typename T2>
using has_less_t = decltype(has_less(declval<T1>(), declval<T2>()));


struct S {
  static int first;
};
int main() {
  cout << boolalpha;
  cout << has_first_t<S>::value << endl;
  cout << has_first_t<double>::value << endl;
}


