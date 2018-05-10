/*
 * foreach.cpp
 *
 *  Created on: 09-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "foreach.hpp"

void func(int e) {
  cout << "from func " << e << endl;
}

// functors produced by lambda expressions are called closures
struct func_obj_type {
  // aka functor
  void operator()(int e) const {
    cout << "from func object " << e << endl;
  }
};

int main() {
  vector<int> vi {5, 3, 6, 7};

  foreach(begin(vi), end(vi), [](auto e) {
    cout << "from lambda " << e << endl;
  });

  foreach(begin(vi), end(vi), func);
  foreach(begin(vi), end(vi), &func);
  foreach(begin(vi), end(vi), func_obj_type{});

  auto functor = func_obj_type{};
  foreach(begin(vi), end(vi), &func_obj_type::operator(), functor);

  auto callable = [](string const& str, int e) {
    cout << str << " " << e << endl;
  };
  foreach(begin(vi), end(vi), callable, "from callable");

}
