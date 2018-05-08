/*
 * len2.cpp
 *
 *  Created on: 08-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T, size_t N>
size_t len(T (&)[N]) {
  return N;
}

// if T is std::allocator<U>, this fn. template will be chose
// but allocator does not have size() but it contains size_type
// so this leads to compilation error
// solution is to add existence of size() as requirement
//template <typename T>
//typename T::size_type len(T const& container) {
//  return container.size();
//}


// but this still doesn't help
// as the variadinc function len(...) does not
// accept non-POD type where allocator is a non-POD type
template <typename T>
auto len(T const& container) -> decltype((void)(container.size()), typename T::size_type()) {
  return container.size();
}

size_t len(...) {
  return 0;
}

int main() {
  int a[5];
  cout << boolalpha <<
      len(a)
      << endl;
  vector<int> v(10);
  cout << len(v) << endl;

//  int *p = nullptr;
//  cout << len(p) << endl;

  // all 3 len fn. templates are candidates
  // len(T) and len(...) are matches
  // len(T) is a better match as return type and fn. args match
  // the fact that allocator does not have size() member is not taken
  // into account when choosing the overload.
  // so, T having member size() is an requirement.
  // so add it to the function template signature
//  std::allocator<int> alloc;
//  cout << len(alloc) << endl;
  return 0;
}



