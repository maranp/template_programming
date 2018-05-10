/*
 * referror2.cpp
 *
 *  Created on: 10-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T, int& SZ>
class Arr {
private:
  vector<T> elems;
public:
  Arr() : elems(SZ) {}
  void printelems() {
    for (auto i = 0; i < SZ; i++) {
      cout << elems[i] << ' ';
    }
    cout << endl;
  }
};

int size = 10;

int main() {

  // Arr<int, 10> a;

  // compiletime error - errornovel
  // reason: following statement constructs vector<int &> v(size)
  // size number of elements of type int& are tried to be constructed
  // but the reference elements will refer to what?
  // Arr<int &, size> a;
  Arr<int, size> a;
  // this automatically reflects in SZ of Arr<int, size>
  // imagine following public member in Arr<int, size>
  // int& SZ = size;
  // since size binds to SZ, chnages to size reflects when SZ is used.
  // runtime error or runtime misbehaviour
  size += 10;
  a.printelems();
}


