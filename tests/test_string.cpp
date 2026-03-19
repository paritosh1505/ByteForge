#include "stratum/string.hpp"
#include <iostream>
#include <utility>
int main() {
  ByteForge::CustomString s("hello");
  ByteForge::CustomString b("Bye");
  ByteForge::CustomString a("Sun");
  // Copy costructor
  ByteForge::CustomString c(b);
  // Copy assignment operator
  c = b;
  // Move cosntructor called
  ByteForge::CustomString d(std::move(c));
  // Move assignment called
  // d = std::move(a);
  std::cout << "C value-->" << c.c_str() << "\n";
  std::cout << "B value-->" << b.c_str() << "\n";
  std::cout << "D value-->" << d.c_str() << "\n";
  ByteForge::CustomString u = std::move(s);
  u += " world";
  // assert(u == "hello world");
  // assert(u.size() == 11);
  // assert(u[0] == 'h');
}
