/*
 * move1.cpp
 *
 *  Created on: 01-May-2018
 *      Author: maran
 */
#include "../ihelper.h"

class X {};

void g(X&) {
  cout << "->g(X&)\n";
}

void g(X const&) {
  cout << "->g(X const&)\n";
}

void g(X &&) {
  cout << "->g(X&&)\n";
}

void f(X& x) {
  cout << "f(X&)\n";
  g(x);
}

void f(X const& x) {
  cout << "f(X const&)\n";
  g(x);
}

//void f(X) {
//  cout << "f(X)\n";
//}

void f(X && x) {
  cout << "f(X&&)\n";

  // this function is called for temporaries (rvalue)
  // still the argument x is a non-const lvalue, x is equivalent to as if f was called, f(X x)
  // because the move semantics information is not passed to x
  g(x); // so this call is resolved to g(X&)
  g(move(x)); // this resolves to g(X&&)
}

int main() {
  X x;
  // candidates: f(X), f(X&), f(X const &)
  // among f(X&), f(X const &) chooses f(X&)
  f(x);

  // candidates: f(X), f(X const &)
  X const y;
  f(y);

  // candidates: f(X), f(X const&), f(X &&)
  // among f(X const&), f(X &&) chooses f(X&&)
  f(X{});

  // same semantics as f(X{})
  f(move(x));
}
