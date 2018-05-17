/*
 * check_fn_param.cpp
 *
 *  Created on: 17-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "is_valid.hpp"

//template <typename T>
//struct type_t {
//  using type = T;
//};

template <typename T>
constexpr auto type_val = type_t<T>{};

template <typename T>
T value_of_type_t(type_t<T> x);

int main() {

  cout << type_print_pretty<decltype(value_of_type_t(type_t<float>{}))>() << endl;
  cout << type_print_pretty<decltype(value_of_type_t(type_val<float>))>() << endl;
  //cout << type_print_pretty<decltype((void)decltype(value_of_type_t(type_val<double>)))>() << endl;

  // value_of_type_t(x) -> return type is T if x is type_t<T>
  // so decltype(value_of_type_t(x)) is T
  // so, decltype(value_of_type_t(x))() => T() (default constructor of T)
  // decltype((void)decltype(value_of_type_t(x))()) => decltype((void)T()) => void
  constexpr auto is_def_ctorble = is_valid(
      [](auto x) -> decltype((void)decltype(value_of_type_t(x))()) {}
);

  cout << boolalpha;
  cout << is_def_ctorble(type_val<int>) << endl;
  cout << is_def_ctorble(type_val<int&>) << endl;
}
