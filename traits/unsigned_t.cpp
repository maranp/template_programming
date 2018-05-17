/*
 * unsigned_t.cpp
 *
 *  Created on: 14-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

// doesn't work if T is bool
// as both if and else branches are evaluated in std::conditional_t's template arguments
//template <typename T>
//struct unsigned_t {
//  using type = typename std::conditional_t<std::is_integral<T>::value && !std::is_same<T, bool>::value,
//      std::make_unsigned_t<T>,
//      T>;
//};

template <typename T>
struct makeunsigned_t {
  using type = std::make_unsigned_t<T>;
};

template <typename T>
struct identity_t {
  using type = T;
};

template <typename T>
struct unsigned_t {
  using type = typename std::conditional_t<std::is_integral<T>::value && !std::is_same<T, bool>::value,
      makeunsigned_t<T>,
      identity_t<T>>::type;
};



int main() {
  cout << boolalpha <<
      std::is_unsigned<int>::value << endl <<
      std::is_unsigned<unsigned int>::value << endl <<
      std::is_unsigned<unsigned_t<int>::type>::value << endl <<
      std::is_unsigned<unsigned_t<bool>::type>::value << endl;
}


