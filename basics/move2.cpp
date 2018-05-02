/*
 * move2.cpp
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

// handles all f() calls
//template <typename T>
//void f(T x) {
//  cout << "f(T)\n";
//  // always calls g(X&)
//  g(x);
//}

// illustration of the need for std::forward
template <typename T>
void f(T&& x) {
  cout << "f(T&&)\n";
  // X x;
  // f(x) -> g(X&) // x is a copy. call to g(X&) is perfect
  // X const x;
  // f(x) -> g(X const&) // x is a const reference. call to g(X const &) is perfect
  // f(move(x) -> g(X&) // x is a rvalue reference. call to g(X&) is not perfect as g(X&&) is the perfect match
  g(x);
  g(std::forward<T>(x)); // f(move(x) -> g(X&&) // perfect matched version is called for all 3 cases
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




