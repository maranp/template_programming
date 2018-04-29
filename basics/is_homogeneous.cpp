/*
 * is_homogeneous.cpp
 *
 *  Created on: 29-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include <type_traits>
template <typename T1, typename... Ts>
bool is_homogeneous(T1, Ts...) {
  // fold expression
  return (std::is_same<T1, Ts>::value && ...);
  //return (is_same_v<T1, Ts> && ...);
}

template <typename T1, typename... Ts>
bool is_homogeneous_ref(T1&&, Ts&&...) {
  // fold expression
  return (std::is_same<T1, Ts>::value && ...);
  //return (is_same_v<T1, Ts> && ...);
}

int main() {

  //add_one(5.5, std::string {"hello"}, 50.56, 10u, complex<float> {2.2, 3.3});
  cout << std::boolalpha <<
      is_homogeneous(5.5, std::string {"hello"}, 50.56, 10u, complex<float> {2.2, 3.3})
      << endl;
  cout << std::boolalpha <<
      is_homogeneous(complex<float> {2.2, 5.3}, complex<float> {2.2, 3.3})
      << endl;
  // is_homgenoeous takes parmaters by value
  // so all string literals decay to char const * and evaluates to true
  cout << std::boolalpha <<
        is_homogeneous("hi", "", "hello")
        << endl;
  // is_homgenoeous_ref takes parameters by forwarding reference
  // so, "hi" and "" are different of different types
  // "hi" -> char const [3]
  // "" -> char const [1]
  // hence evaluate to false
  cout << std::boolalpha <<
          is_homogeneous_ref("hi", "", "hello")
          << endl;
}
