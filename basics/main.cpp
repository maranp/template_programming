/*
 * main.cpp
 *
 *  Created on: 24-Apr-2018
 *      Author: maran
 */

#include "stack.hpp"
#include "../ihelper.h"
int main() {
  stack<int> si;
  si.push(7);
  cout << si.top() << endl;
  stack<string> ss;
  ss.push("hello");
  ss.push("world");
  cout << ss.top() << endl;

  cout << ss;
}

