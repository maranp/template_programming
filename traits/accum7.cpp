/*
 * accum7.cpp
 *
 *  Created on: 11-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "accumtraits4.hpp"
#include "sumpolicy2.hpp"
#include "accum7.hpp"

int main() {
  int a[] = {1, 2, 3, 4};
  std::cout <<
  accum9(a, a + 4) / 4 << endl;
  double d[] = {1, 2, 3, 4};
  std::cout <<
      accum9(d, d + 4) / 4 << endl;
}






