/*
 * is_prime.cpp
 *
 *  Created on: 08-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <unsigned N, unsigned d>
struct do_is_prime {
  constexpr static bool value = (N % d != 0) && do_is_prime<N, d - 1>::value;
};

template <unsigned N>
struct do_is_prime<N, 2> {
  constexpr static bool value = (N % 2 != 0);
};

template <unsigned N>
struct is_prime {
  constexpr static bool value = do_is_prime<N, N / 2>::value;
};

template <>
struct is_prime<0> {
  constexpr static bool value = false;
};

template <>
struct is_prime<1> {
  constexpr static bool value = false;
};

template <>
struct is_prime<2> {
  constexpr static bool value = true;
};

template <>
struct is_prime<3> {
  constexpr static bool value = true;
};

int main() {
  cout << boolalpha <<
      is_prime<4>::value << "," << is_prime<7>::value
      << endl;
}
