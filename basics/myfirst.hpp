#pragma once

#include <typeinfo>
#include <iostream>

template <typename T>
void print_type_of(T const& arg);

template <typename T>
void print_type_of(T const& arg) {
  std::cout << typeid(arg).name() << std::endl;
}

