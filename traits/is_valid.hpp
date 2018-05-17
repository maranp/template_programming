#pragma once

#include "../ihelper.h"

// we want to determine f(args...) is valid invocation
// so, we want to do decltype(f(args...)) as
// decltype only takes expression.
// since we don't have f(of F) and args...(of Args...)
// we make an expression out of F and Args... with the help of
// declval.
// isValidImpl is not defined. so, it can be used
// in non-evaluating context (decltype, sizeof)
template <typename F, typename... Args,
          typename = decltype(declval<F>()(declval<Args&&>()...))>
std::true_type isValidImpl(void*);

// F(Args...) is not a valid expression
template <typename, typename...>
std::false_type isValidImpl(...);

// is_valid takes a function/lambda f
// and returns lambda
// auto check_expression_lambda = is_valid(f_the_lambda);
// true_or_false_type result = check_expression_lambda(expression);
// check_expression_lambda takes expression as argument and
// checks f_the_lambda(expression) is a valid expression
inline constexpr auto is_valid = [](auto f) {
  return [](auto&&... args) {
    return decltype(isValidImpl<decltype(f), decltype(args)&&...>(nullptr)){};
  };
};

// helper template
// represents a type as value. how???
template <typename T>
struct type_t {
  using type = T;
};

template <typename T>
constexpr auto type_as_val = type_t<T>{};

// use it in unevaluated context
// unwrap a wrapped type
template <typename T>
T value_of_t(type_t<T>);

// decltype(type_as_val<T>) gives T
