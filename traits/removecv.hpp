#pragma once

#include "../ihelper.h"

template <typename T>
struct remove_const {
  using type = T;
};

template <typename T>
struct remove_const<T const> {
  using type = T;
};

template <typename T>
struct remove_volatile {
  using type = T;
};

template <typename T>
struct remove_volatile<T volatile> {
  using type = T;
};

template <typename T>
struct remove_cv : remove_volatile<typename remove_const<T>::type> {
};

// following is equivalent and works even for void
// (contrast this with AddLvalueReference in template_notes).
template <typename T>
using remove_cv_1 = typename remove_volatile<typename remove_const<T>::type>::type;

