/*
 * is_convertible.cpp
 *
 *  Created on: 23-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename From, typename To, bool = std::is_void_v<To> || std::is_array_v<To> || std::is_function_v<To>>
struct is_convble_helper {
  using type = std::integral_constant<bool, std::is_void_v<From> && std::is_void_v<To>>;
};
// To test whether a From type can be converted to To type
// we rely on the language feature that,
// if a From type is passed to a function and the function
// takes To type, the function(To) will be selected
// if From to To conversion is possible.
template <typename From, typename To>
struct is_convble_helper<From, To, false> {
private:
  static void aux(To);
  template <typename Fr, typename = decltype(aux(declval<Fr>()))>
  static std::true_type test(void *);
  template <typename>
  static std::false_type test(...);
public:
  using type = decltype(test<From>(nullptr));
};

// inherit from true_type or false_type
template <typename From, typename To>
struct is_convble : is_convble_helper<From, To>::type {
};

template <typename From, typename To>
constexpr bool is_convble_v = is_convble<From, To>::value;

int main() {
  cout << boolalpha << is_convble<short, int>::value << endl;
  cout << is_convble<string, int>::value << endl;
  cout << is_convble_v<double*, int*> << endl;
}


