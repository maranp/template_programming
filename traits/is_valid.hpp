#pragma once

#include "../ihelper.h"

// we want to determine F(Args...) is valid invocation
// for given instance of F without evaluating it
template <typename F, typename... Args,
          typename = decltype(declval<F>()(declval<Args&&>()...))>
std::true_type isValidImpl(...);

template <typename, typename...>
std::false_type isValidImpl(...);

// is_valid takes a function/lambda f
// and returns lambda
// auto cond_lamda = is_valid(f_the_lambda);
// true_or_false = cond_lamba(condition);
// cond_lambda takes consition as argument and
// checkes f_the_lambda(condition) is a valid expression
inline constexpr auto is_valid = [](auto f) {
  return [](auto... args) {
    return decltype(isValidImpl<decltype(f), decltype(args)&&...>(nullptr)){};
  };
};
