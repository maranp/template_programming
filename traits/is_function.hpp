/*
 * is_function.hpp
 *
 *  Created on: 14-May-2018
 *      Author: maran
 */

#pragma once

// primary template
template <typename T>
struct is_function : std::false_type {};

// normal functions (fixed number of args)
template <typename R, typename... Args >
struct is_function<R (Args...)> : std::true_type {
  using ret_type = R;
  using params_type = typelist<Args...>;
  static constexpr bool variadic = false;
};

// cstyle varargs functions
template <typename R, typename... Args >
struct is_function<R (Args..., ...)> : std::true_type {
  using ret_type = R;
  using params_type = typelist<Args...>;
  static constexpr bool variadic = true;
};
