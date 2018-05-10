/*
 * maxdefaultdecval.cpp
 *
 *  Created on: 09-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

// for call max(5.2, 30)
// T1, T2 are rvalue-references.
// we do not want our RT to be reference type
// so decay the type
template <typename T1, typename T2,
typename RT = std::decay_t<decltype(true ? std::declval<T1>() : std::declval<T2>())>>
RT max(T1 a, T2 b) {
  return a > b ? a : b;
}

int main() {
  cout << boolalpha <<
      max(5.2, 30) << endl;
}
