/*
 * accum6.cpp
 *
 *  Created on: 11-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "accumtraits4.hpp"
#include "sumpolicy1.hpp"
#include "multpolicy1.hpp"
#include "accum6.hpp"

int main() {
  int a[] = {1, 2, 3, 4};
  std::cout <<
  accum8(a, a + 4) / 4 << endl;
  double d[] = {1, 2, 3, 4};
  std::cout <<
      accum8(d, d + 4) / 4 << endl;
  std::cout <<
      accum8<double, MultPolicy>(d, d + 4) / 4 << endl;
}


