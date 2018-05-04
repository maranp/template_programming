/*
 * spclmembertempl1.cpp
 *
 *  Created on: 03-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include <type_traits>

class person {
private:
  string name;
public:
//  person(string const& n) : name {n} {
//    cout << "person(string const& n)\n";
//  }
//  person(string&& n) : name {move(n)} {
//    cout << "person(string&& n)\n";
//  }

  // handles
  // person(string&)
  // person(string const&)
  // person(string&&)
  // but also handles
  // person(person&) as it is more appropriate than person(person const&)
  // for person p; person q {p}; is called.
  // so, undefine person(STR&&) when STR is "person&"
#if 0
  // approach 1
  template <typename STR,
  typename  = std::enable_if_t<!(std::is_same<STR, person&>::value)>>
  person(STR&& n) : name {std::forward<STR>(n)} {
    cout << "person(STR&& n)\n";
  }
#endif
  // approach 2
  // define an alias template to keep things simple
  template <typename T>
  using IsStringType = std::enable_if_t<std::is_convertible<T, string>::value>;

  template<typename STR, typename = IsStringType<STR>>
  person(STR&& n) : name {std::forward<STR>(n)} {
    cout << "person(STR&& n)\n";
  }

  person(person const& p) : name {p.name} {
    cout << "person(person const& p)\n";
  }
  person(person&& p) : name {move(p.name)} {
    cout << "person(person&& p)\n";
  }
};

int main() {
  string s = "hello";
  person p1 {s};
  person p2 {"world"};

  person p3 {p1};

  // person from person(string&& n) is created
  // but person(person&&) is not called as copy elision happens
  //person p4 {person("")};

  // explicit move on the temporary object prevents copy elision
  // so, person(person&&) is also called
  person p4 {move(person(""))};
}


