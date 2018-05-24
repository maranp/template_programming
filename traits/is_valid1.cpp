/*
 * is_valid1.cpp
 *
 *  Created on: 24-May-2018
 *      Author: maran
 */

#include "is_valid.hpp"

struct S {
  using value_type = int;
};
int main() {
  constexpr auto has_first = is_valid(
      [](auto x) -> decltype((void) value_of_type_t(x).first){}
      );
  cout << boolalpha;
  cout << has_first(type_val<std::pair<int, int>>) << endl;
  cout << has_first(type_val<vector<int>>) << endl;

  // cannot access a type member from a reference, so decay_t applied to T
  // before accessing type member
  constexpr auto has_size_type = is_valid(
      [](auto x) -> typename std::decay_t<decltype(value_of_type_t(x))>::size_type {}
      );

  cout << has_size_type(type_val<vector<int>>) << endl;
  cout << has_size_type(type_val<S>) << endl;

  constexpr auto has_less = is_valid(
      [](auto x, auto y) -> decltype(value_of_type_t(x) < value_of_type_t(y)) {}
      );
  cout << has_less(type_val<S>, type_val<int>) << endl;
  cout << has_less(type_val<short>, type_val<int>) << endl;

}
