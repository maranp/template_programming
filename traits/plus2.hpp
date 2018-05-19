#pragma once

#include "../ihelper.h"

// when no operator+ defined for T1 and T2
// this fails to compile, because type evaluation
// does not happen in sfinae context to tolerate the
// invalid expression formed due to the types substituted
//template <typename T1, typename T2>
//struct plus_type {
//  using type = decltype(declval<T1>() + declval<T2>());
//};

// more resilient, sfinae friendly
template <typename T1, typename T2, typename = std::void_t<>>
struct plus_type : std::false_type {};

template <typename T1, typename T2>
struct plus_type<T1, T2,
  std::void_t<decltype(declval<T1>() + declval<T2>())>>
  : std::true_type {
  using type = decltype(declval<T1>() + declval<T2>());
};
