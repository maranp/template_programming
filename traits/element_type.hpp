#pragma once


#include "../ihelper.h"

template <typename C>
struct element_type;

template <typename T>
struct element_type<vector<T>> {
  using type = T;
};

template <typename T>
struct element_type<list<T>> {
  using type = T;
};

template <typename T, size_t N>
struct element_type<T[N]> {
  using type = T;
};

template <typename T>
struct element_type<T[]> {
  using type = T;
};
