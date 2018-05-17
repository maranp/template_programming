/*
 * has_begin.cpp
 *
 *  Created on: 16-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T, typename = std::void_t<>>
struct has_member_function_begin : std::false_type {};

// this works only when begin is accessible, not overloaded
// has_member_function_begin<E>::value returns true only when there is only one begin
template <typename T>
struct has_member_function_begin<T, std::void_t<decltype(&T::begin)>> : std::true_type {};

// to hadnle member functions that have overloads
// yes, evaluate the xpression calling the function overload in the sfinae context

template <typename T, typename = std::void_t<>>
struct has_member_function_begin_1 : std::false_type {};

// returns true only if one of the overloads of begin is
// begin(); // no argument
// returns true of the overlaod is begin(float)
// when the check is decltype(std::declval<T>().begin(5.5f))
template <typename T>
struct has_member_function_begin_1<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};

struct E {
  void begin(float);
  void begin(int);
  void begin();
};

int main() {
  cout << boolalpha <<
      has_member_function_begin<E>::value << endl;
  cout <<
      has_member_function_begin<vector<int>>::value << endl;

  cout <<
      has_member_function_begin_1<E>::value << endl;
  cout <<
      has_member_function_begin_1<vector<int>>::value << endl;

}



