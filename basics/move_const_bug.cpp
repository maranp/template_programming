/*
 * move2.cpp
 *
 *  Created on: 01-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

class X {
public:
  int i;
};

// compilation error when rvalue
// is passed as *T& x* expects l-value
template <typename T>
void f(T& x) {
  cout << "f(T x)\n";
  // f takes even const object
  // but compilation fails only when
  // deliberately attepted to modify x
  // x.i = 1;

  // move(x) compiles well even if x is from a const object
  //g(move(x));
}

void ff(X& x) {
  cout << "ff(X& x)\n";
  //x.i = 10;
}

int main() {
  X x;
  // candidates: f(X), f(X&), f(X const &)
  // among f(X&), f(X const &) chooses f(X&)
  ff(x);
  f(x);

  // candidates: f(X), f(X const &)
  X const y {};
  // fails as no match for ff taking const&
  //ff(y);

  // succeeds invoking the f<T>(X&) version
  f(y);
}




