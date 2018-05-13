/*
* passbyvalue.cpp
 *
 *  Created on: 12-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include <cstring>

template <typename T>
void f(T) {}

template <typename T>
void print_passbyvalue_type(void (*)(T)) {
  cout <<
      typeid(T).name() << ' ';
  cout << boolalpha <<
      std::is_const_v<T> << ' ';
  cout <<
      std::is_pointer_v<T> << endl;
}

int main() {
  print_passbyvalue_type(&f<int>);
  print_passbyvalue_type(&f<int const>);
  print_passbyvalue_type(&f<int []>);
  print_passbyvalue_type(&f<int(int)>);

  return 0;
}
