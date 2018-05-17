#pragma once

#include "../ihelper.h"

// we want to call T(T&&) - the move constructor
// under noexcept (operator version of noexcept) in order to determine whether
// the move constructor is a no throw move constructor
// but if T has no move constructor, evaluation of
// the expression T(std::declval<T>) will fail and the program will be illformed
// we want sfinae to help us to choose the partial specialization
// by checking the validity of the move ctor call expression when it can be sfinaed out (template argument deduction)
// and if valid, we allow the expression to be checked for nothorow by noexcept
// in the specifier part of bool-constant

// ill formed
//template <typename T>
//struct is_nothrow_move_constructible
//  : std::bool_constant<noexcept(T(std::declval<T>()))>{};

// well formed
template <typename T, typename = std::void_t<>>
struct is_nothrow_move_constructible : std::false_type {};

// let's first decide whether move cinstruction of T is valid
// by sfinaeing out if not valid
// if T(T&&) is valid, we move onto check its noexcept-ness
template <typename T>
struct is_nothrow_move_constructible<T, std::void_t<decltype(T(std::declval<T>()))>>
  : std::bool_constant<noexcept(T(std::declval<T>()))>{};
