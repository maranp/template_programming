/*
 * use_objectcounter.cpp
 *
 *  Created on: 26-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "objectcounter.hpp"

template <typename T>
class MyClass : public ObjectCounter<MyClass<T>> {};

int main() {
  MyClass<int> i1, i2;
  cout << MyClass<int>::live() << endl;

  MyClass<char> c1, c2, c3;
  cout << c1.live() << endl;
}


