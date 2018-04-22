#include "../ihelper.h"

int main() {
  int x = 0;
  int const &rci = x;
  auto t = rci; // decays to remove reference and const
  cout << type_print_pretty<decltype(t)>() << endl;
  cout << type_print_pretty<decltype(rci)>() << endl;

  return 0;
}
