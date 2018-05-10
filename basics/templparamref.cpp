/*
 * templparamref.cpp
 *
 *  Created on: 10-May-2018
 *      Author: maran
 */
#include "../ihelper.h"

template <typename T>
void foo(T&) {
  cout << boolalpha <<
      std::is_reference_v<T> << endl;
}

int main() {
  int x;
  int& r = x;
  foo(x);
  foo(r);
  foo<int &>(x);
}



