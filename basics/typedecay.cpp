#include "../ihelper.h"
// #include "maxdecltypedecay.hpp"
// #include "maxcommon.hpp"
// #include "maxdefault1.hpp"
#include "maxdefault3.hpp"
int main() {
  int x = 0;
  int const &rci = x;
  auto t = rci; // decays to remove reference and const
  cout << type_print_pretty<decltype(t)>() << endl;
  cout << type_print_pretty<decltype(rci)>() << endl;

  max(rci, 3);

  return 0;
}
