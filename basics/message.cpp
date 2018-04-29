/*
 * message.cpp
 *
 *  Created on: 28-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <auto Msg>
class Message {
public:
  void print_msg() const {
    cout << Msg << endl;
  }
};

int main() {
  Message<42> msg1;
  msg1.print_msg();

  // this wont compile
  // Message<"hello"> msg2;
  // msg2.print_msg();

  // this works from c++17
  static char const hello[] = "hello";
  Message<hello> msg2;
  msg2.print_msg();

}

