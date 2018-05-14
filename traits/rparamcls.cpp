#include "rparam.hpp"
#include "../ihelper.h"

struct MyClass1 {
  MyClass1() {}
  MyClass1(MyClass1 const&) {
    cout << "copy construct MyClass1\n";
  }
};

struct MyClass2 {
  MyClass2() {}
  MyClass2(MyClass2 const&) {
    cout << "copy construct MyClass2\n";
  }
};

template <>
struct RParam<MyClass2> {
  using type = MyClass2;
};

template <typename T1, typename T2>
void foocore(typename RParam<T1>::type t1, typename RParam<T2>::type t2) {
  cout << boolalpha <<
      std::is_lvalue_reference<typename RParam<T1>::type>::value <<
      std::is_lvalue_reference<T1>::value << endl;
  cout << boolalpha <<
      std::is_lvalue_reference<typename RParam<T2>::type>::value <<
      std::is_lvalue_reference<T2>::value << endl;
}

template <typename T1, typename T2>
void foo(T1&& t1, T2&& t2) {
  foocore<T1, T2>(std::forward<T1>(t1), std::forward<T2>(t2));
}

template <typename T1, typename T2>
void foo1(T1&& t1, T2&& t2) {
  cout << boolalpha << "is ref? " <<
      std::is_reference<T1>::value <<
      std::is_reference<T2>::value << endl;
  cout << boolalpha << "is lvalue ref? " <<
      std::is_lvalue_reference<T1>::value <<
      std::is_lvalue_reference<T2>::value << endl;
  cout << boolalpha << "is rvalue ref? " <<
      std::is_rvalue_reference<T1>::value <<
      std::is_rvalue_reference<T2>::value << endl;
}

template <typename T1, typename T2>
void foo2(T1&& t1, T2&& t2) {
  cout << boolalpha << "is ref? " <<
      std::is_reference<T1&&>::value <<
      std::is_reference<T2&&>::value << endl;
  cout << boolalpha << "is lvalue ref? " <<
      std::is_lvalue_reference<T1&&>::value <<
      std::is_lvalue_reference<T2&&>::value << endl;
  cout << boolalpha << "is rvalue ref? " <<
      std::is_rvalue_reference<T1&&>::value <<
      std::is_rvalue_reference<T2&&>::value << endl;
}

int main() {
  MyClass1 mc1;
  MyClass2 mc2;

  // T1 and T2 are T1&, T2& respectively
  // so effectively RParam<MyClass2&>::type is evaluated
  // and hence the RParam<MyClass2> is not exercised
  foo(mc1, mc2);
  // T1&& is rvalue reference but T1 is just T1
  // so RParam<MyClass2> is exercised
  foo(MyClass1{}, MyClass2{});

  cout << "foo1(mc1, mc2)" << endl;
  foo1(mc1, mc2);
  cout << "foo1(MyClass1{}, MyClass2{})" << endl;
  foo1(MyClass1{}, MyClass2{});
  cout << "foo1(move(mc1), move(mc2))" << endl;
  foo1(move(mc1), move(mc2));

  cout << "foo2(mc1, mc2)" << endl;
  foo2(mc1, mc2);
  cout << "foo2(MyClass1{}, MyClass2{})" << endl;
  foo2(MyClass1{}, MyClass2{});
  cout << "foo2(move(mc1), move(mc2))" << endl;
  foo2(move(mc1), move(mc2));

}
