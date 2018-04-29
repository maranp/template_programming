#pragma once

#include "ihelper.h"

template <typename T>
class AddSpace {
private:
  T const & t_ref;
public:
  AddSpace(T const &t) : t_ref {t} {}
  friend ostream& operator<<(ostream& os, AddSpace t) {
    return os << t.t_ref << ' ';
  }
};

template <typename... Args>
void vprint_space(Args... args) {
  (cout << ... << AddSpace(args));
  cout << endl;
}

template <typename... Args>
void print_doubled(Args... args) {
  vprint_space(args + args...);
}

// expand the argument list, add 1 to each and pass the list to vprint_space
template <typename... Args>
void add_one_1(Args... args) {
  vprint_space(decltype(args){1} + args ...);
}

// expand and evaluate the parmeter list, add one and then pass to vprint_space
template <typename... Args>
void add_one(Args... args) {
  vprint_space((1 + ... + args));
}

template <typename Coll, typename... Idx>
void print_coll_indices(Coll coll, Idx... idx) {
  vprint_space(coll[idx]...);
}
