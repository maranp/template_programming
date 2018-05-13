/*
 * is_same1.cpp
 *
 *  Created on: 12-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "is_same0.hpp"

template <typename T>
void fooimpl(T, TrueType) {
  cout << "from same type" << endl;
}

template <typename T>
void fooimpl(T, FalseType) {
  cout << "from different type" << endl;
}

template <typename T>
void foo(T t) {
  fooimpl(t, is_same1<T, int>{});
}

struct B1 {};
struct D1 : B1 {};

struct B2 {};
struct D2 : B2 {};

// illustration of
// basic idea that helps tag dispatching
void f1(B1) {
  cout << "B1 for D1" << endl;
}

void f1(B2) {
  cout << "B2 for D2" << endl;
}

int main() {
  foo(7);
  foo(42.2);

  f1(D1{});
  f1(D2{});
}


