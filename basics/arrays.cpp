/*
 * arrays.cpp
 *
 *  Created on: 01-May-2018
 *      Author: maran
 */
#include "../ihelper.h"

template <typename T>
class MyClass;

template <typename T, int Sz>
class MyClass<T[Sz]> {
public:
  static void print() {
    cout << "T[" << Sz << "]\n";
  }
};

template <typename T>
class MyClass<T[]> {
public:
  static void print() {
    cout << "T[]\n";
  }
};

// a1, a2
template <typename T>
class MyClass<T*> {
public:
  static void print() {
    cout << "T*\n";
  }
};

// a3
template <typename T, int Sz>
class MyClass<T(&)[Sz]> {
public:
  static void print() {
    cout << "T(&)[" << Sz << "]\n";
  }
};

template <typename T>
class MyClass<T(&)[]> {
public:
  static void print() {
    cout << "T(&)[]\n";
  }
};

template <typename T1, typename T2, typename T3>
void foo(int a1[7], int a2[],
       int (&a3)[42],
       int (&x0)[], T1 x1, T2& x2, T3&& x3) {
  MyClass<decltype(a1)>::print(); // int *
  MyClass<decltype(a2)>::print(); // int * <T*>
  MyClass<decltype(a3)>::print(); // int (&)[42] <T (&)[Sz]>
  MyClass<decltype(x0)>::print(); // int (&)[] <T (&)[]>
  MyClass<decltype(x1)>::print(); // int * <T*>
  MyClass<decltype(x2)>::print(); // int (&) [] <T (&)[]>
  MyClass<decltype(x3)>::print(); // int (&) [] <T (&)[]>
}

int main() {
  int a[42];
  MyClass<decltype(a)>::print(); // int [42]
  cout << type_print_pretty<decltype(a)>() << endl;
  extern int x[];
  MyClass<decltype(x)>::print();
  cout << type_print_pretty<decltype(x)>() << endl;

  // foo((1)int a1[7], (2)int a2[],
  //     (3)int (&a3)[42]
  //     (4)int (&x0)[], (5)T1 x1, (6) T2& x2, (7) T3&& x3
  foo(a, a, a, x, x, x, x);
}

int x[] = {0, 8, 15};

