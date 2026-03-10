#include "stratum/string.hpp"
#include <algorithm>
#include <iostream>
int main() {
  ByteForge::CustString s("hello");
  ByteForge::CustString b("Bye");
  b = s;
  std::cout << s.c_str() << "\n";
  std::cout << b.c_str() << "\n";
}