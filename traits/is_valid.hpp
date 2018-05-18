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

// a helper used by the end user application to pass value to inner lambda (f)
// which strips the correct T from the value passed
template <typename T>
constexpr auto type_val = type_t<T>{};

// use it in unevaluated context
// unwrap a wrapped type
template <typename T>
T value_of_type_t(type_t<T> x);


// value_of_type_t(x) -> return type is T if x is type_t<T>
// so decltype(value_of_type_t(x)) is T
// so, decltype(value_of_type_t(x))() => T() (default constructor of T)
// decltype((void)decltype(value_of_type_t(x))()) => decltype((void)T()) => void
// the inner lambda, say f => [](auto x) -> decltype((void)decltype(value_of_type_t(x))()) {}
// will be instantiated only if T() is valid. If T() is not valid.
// the lambda, f, would not be instantiated and hence, the checking of
// f(x) in isValidImpl will fail and in turn will return false_type
constexpr auto is_def_ctorble = is_valid(
    [](auto x) -> decltype((void)decltype(value_of_type_t(x))()) {}
    );
