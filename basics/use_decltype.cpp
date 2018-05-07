/*
 * use_decltype.cpp
 *
 *  Created on: 04-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

int main() {
  int x;
  auto& y = x;
  cout << type_print_pretty<decltype(x)>() << endl;
  cout << type_print_pretty<decltype((x))>() << endl;
  cout << type_print_pretty<decltype(y)>() << endl;
  cout << type_print_pretty<decltype((y))>() << endl;
  cout << type_print_pretty<decltype(5)>() << endl;
  cout << type_print_pretty<decltype((5 + 6))>() << endl;

  if constexpr (std::is_lvalue_reference<decltype(5 + 6)>::value) {
    cout << "lvalue reference\n";
  } else if constexpr (std::is_rvalue_reference<decltype(5 + 6)>::value) {
    cout << "xvalue reference\n";
  } else {
    cout << "prvalue\n";
  }

  if constexpr (std::is_lvalue_reference<decltype((y))>::value) {
    cout << "lvalue reference\n";
  } else if constexpr (std::is_rvalue_reference<decltype((y))>::value) {
    cout << "xvalue reference\n";
  } else {
    cout << "prvalue\n";
  }

  // int &&z = move(y);
  int &&z = 5; // temporary matetialization
  if constexpr (std::is_lvalue_reference<decltype(z)>::value) {
    cout << "lvalue reference\n";
  } else if constexpr (std::is_rvalue_reference<decltype(z)>::value) {
    cout << "xvalue reference\n";
  } else {
    cout << "prvalue\n";
  }
}



