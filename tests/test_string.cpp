#include "stratum/string.hpp"
#include <iostream>
#include <utility>
int main() {
  ByteForge::CustString s("hello");
  ByteForge::CustString b("Bye");
  b = std::move(s);

  std::cout << s.c_str() << "\n";
  std::cout << b.c_str() << "\n";
}
