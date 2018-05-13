#pragma once

#include "../ihelper.h"

template <typename T>
struct decayt : std::remove_cv<T> {};

template <typename T>
struct decayt<T[]> {
  using type = T*;
};

template <typename T, size_t SZ>
struct decayt<T[SZ]> {
  using type = T*;
};

// decay function to function pointer
template <typename RetT, typename... Args>
struct decayt<RetT(Args...)> {
  using type = RetT (*)(Args...);
};

// decay function with c-style varargs to function pointer
template <typename RetT, typename... Args>
struct decayt<RetT(Args..., ...)> {
  using type = RetT (*)(Args..., ...);
};
