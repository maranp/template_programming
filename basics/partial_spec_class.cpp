/*
 * partial_spec_class.cpp
 *
 *  Created on: 25-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T1, typename T2>
class MyClass {
public:
  MyClass() {
    cout << "MyC<T1, T2>" << endl;
  }
};

template <typename T>
class MyClass<T, int> {
public:
  MyClass() {
    cout << "MyC<T, int>" << endl;
  }
};

template <typename T>
class MyClass<T, T> {
public:
  MyClass() {
    cout << "MyC<T>" << endl;
  }
};

template <typename T1, typename T2>
class MyClass<T1*, T2*> {
public:
  MyClass() {
    cout << "MyC<T1*, T2*>" << endl;
  }
};

template <typename T>
class MyClass<T*, T*> {
public:
  MyClass() {
    cout << "MyC<T*, T*>" << endl;
  }
};

int main() {
  MyClass<int, float> m1;
  MyClass<float, int> m2;
  MyClass<int*, int*> m3;
  MyClass<int*, float*> m4;

  MyClass<int*, int*> m5;
}


