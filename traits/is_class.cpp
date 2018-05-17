/*
 * is_class.cpp
 *
 *  Created on: 14-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T, typename = std::void_t<>>
struct is_class : std::false_type {};

template <typename T>
struct is_class<T, std::void_t<int T::*>> : std::true_type {};

// instead, we might have wanted to do it this way
// but this partial specialization resolves to a pointer to class member
// not to the class itself
// what we need is, to resolve to a type T which is a valid type to
// fit the expression int T::*
// and only class types can for this expression.
// and sfinaeing-out with void_t<> fits the bill, as implemented above

//template <typename T>
//struct is_class<int T::*> : std::true_type {};

int main() {
  vector<int> vi;
  cout << boolalpha <<
      is_class<decltype(vi)>::value << endl;
  cout << boolalpha <<
        is_class<float>::value << endl;
  // a lambda expression is a of class type
  // lambda expression is a unique, unnamed, non-union class type
  auto l = []{};
  cout << boolalpha <<
      is_class<decltype(l)>::value << endl;
}
