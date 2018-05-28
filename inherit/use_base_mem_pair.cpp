/*
 * use_base_mem_pair.cpp
 *
 *  Created on: 26-May-2018
 *      Author: maran
 */

#include "basememberpair.hpp"

struct S {
  int x;
};

struct EmptyS {
  using Int = int;
};

template <typename T1, typename T2>
struct mem_mem_pair {
  T1 t1;
  T2 t2;
};

int main() {
  // size 8
  BaseMemberPair<S, int> bmp {S{}, 0};
  // size 8
  mem_mem_pair<S, int> mmp {S{}, 0};
  cout << sizeof(bmp) << endl;
  cout << sizeof(mmp) << endl;

  // size 4. Due to EBCO, only int occupies the space
  BaseMemberPair<EmptyS, int> ebmp {EmptyS{}, 0};
  // size 8. EmptyS size is 1, for alignment 3 bytes padded
  mem_mem_pair<EmptyS, int> emmp {EmptyS{}, 0};
  cout << sizeof(ebmp) << endl;
  cout << sizeof(emmp) << endl;
}


