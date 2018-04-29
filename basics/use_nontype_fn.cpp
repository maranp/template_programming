/*
 * use_nontype_fn.cpp
 *
 *  Created on: 28-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "add_value.hpp"

int main() {
  vector<int> vi {1, 2, 3, 4, 5};
  vector<int> viplus;

  std::transform(begin(vi), end(vi), std::back_inserter(viplus), add_value<5, int>);
  cprint(viplus);

  // add_value_1<auto Val, typename T = decltype(val)>(T)
  std::transform(begin(vi), end(vi), begin(viplus), add_value_1<62>);
  cprint(viplus);

  // add_value_2<T, T Val = T {}>(T)
  std::transform(begin(vi), end(vi), begin(viplus), add_value_2<int, 3>);
  cprint(viplus);

  cout <<
  type_print_pretty<std::nullptr_t>()
  << endl;

}
