/*
 * referror1.cpp
 *
 *  Created on: 10-May-2018
 *      Author: maran
 */
#include "../ihelper.h"


template <typename T, T Z = T{}>
class RefMem {
private:
  T Zero;
public:
  RefMem() : Zero {Z} {}
};

int null = 0;
int main() {
  RefMem<int> a, b;
  a = b;

  // non-const lvalue reference to type 'int' cannot bind to an initializer list temporary
  // invalid argument to Z
  // RefMem<int &> ra;

  // value of type 'int' is not implicitly convertible to 'int &'
  // invalid argument to Z
  // RefMem<int &, 0> ra;

  extern int null;
  RefMem<int &, null> ra;
  // no overloaded "="
  // treat int& Z = null as member in ra
  // so  operator= is deleted for a reference member class
  // ra = b;
}



