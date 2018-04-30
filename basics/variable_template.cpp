/*
 * variable_template.cpp
 *
 *  Created on: 30-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T>
T pi = T {3.1439458349083443908};

template <typename T = long double>
T pi1 = T {3.1439458349083443908};

template <auto N>
constexpr decltype(N) dval {N};


template <int N>
array<int, N> arr {};

int main() {
  cout << pi<long double> << endl;
  cout << pi<float> << endl;
  cout << pi1<> << endl;
  cout << pi1<float> << endl;

  cout << dval<'c'> << endl;
  cout << dval<42> << endl;

  arr<10>[0] = 42;
  cout << arr<10>[0] << endl;
}



