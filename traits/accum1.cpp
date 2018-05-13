/*
 * accum1.cpp
 *
 *  Created on: 11-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "accum1.hpp"

int main() {
  int a[] = {1, 2, 3, 4};
  cout <<
      accum1(a, a + 4) / 4 <<
      endl;
  char c[] = "hello world";
  cout <<
      accum1(c, c + 6) / 6 <<
      endl;

  cout <<
      accum2<int>(c, c + 6) / 6 <<
      endl;

  cout <<
      accum3(c, c + 6) / 6 <<
      endl;

  cout <<
      accum3(a, a + 4) / 4 <<
      endl;

  double d[] = {1, 2, 3, 4};
  cout <<
      accum3(d, d + 4) / 4 <<
      endl;
}


