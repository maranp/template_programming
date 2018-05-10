/*
 * typetraits.cpp
 *
 *  Created on: 09-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

int main() {
  cout << boolalpha <<
      std::is_reference_v<int &> << ' ' <<
      std::is_reference_v<int &&> << ' ' <<
      std::is_reference_v<int> << ' ' <<
      endl;

  cout << std::is_same_v<std::remove_const_t<int const>, int> << endl;
  cout << std::is_same_v<std::remove_const_t<int const&>, int> << endl;
  cout << std::is_same_v<std::remove_const_t<std::remove_reference_t<int const&>>, int> << endl;
  cout << std::is_same_v<std::decay_t<int const&>, int> << endl;

  cout << "******" << endl;
  cout << std::is_copy_assignable_v<int> << endl;
  cout << std::is_assignable_v<int&, int&> << endl;

  cout << "******" << endl;
  cout << std::is_swappable_v<int> << endl;
  cout << std::is_swappable_with_v<int&, int&> << endl;
  cout << std::is_swappable_with_v<int, int> << endl;

}



