/*
 * use_is_def_consble.cpp
 *
 *  Created on: 13-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "is_default_constructible1.hpp"

struct S {
  S() = delete;
};

struct T {
  T() = default;
};

int main() {
  cout << boolalpha;
  cout << is_default_constructible<S>::value << endl;
  cout << is_default_constructible<T>::value << endl;
  cout << is_default_constructible2<S>::value << endl;
  cout << is_default_constructible2<T>::value << endl;
}


