#pragma once

#include <functional>

// all callable objects passed to "Callable f" (passed by value) are
// decayed to a function pointer
// works for all callable except member functions
template <typename Iter, typename Callable>
void foreach(Iter start, Iter end, Callable f) {
  while (start != end) {
    f(*start);
    start++;
  }
}

// if f is a member function.
// std::invoke interprets first arg in args... as this
// and forms a call, this->f and passes
// rest of arg in args... as parameters to this->f
// also includes *start as the last argument to this->f() call
// ie this->f(args... (except first), *start)
// can be called like:
// foreach(begin(c), end(c), &class_type::member, class_type_obj, first few params)
// if f is a callable but not a member function,
// call is made as
// f(args..., *start)
// can be called like:
// foreach(begin(c), end(c), callable, first few params)
template <typename Iter, typename Callable, typename... Args>
void foreach(Iter start, Iter end, Callable f, Args... args) {
  while (start != end) {
    std::invoke(f, args..., *start);
    start++;
  }
}
