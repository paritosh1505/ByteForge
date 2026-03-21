#include "stratum/string.hpp"
#include <cassert>

#include <iostream>
#include <utility>
int main() {
  ByteForge::CustomString test("hello");
  ByteForge::CustomString b("Bye");
  const ByteForge::CustomString d("Sun");
  ByteForge::CustomString g("abc");
  ByteForge::CustomString f("ab");
  ByteForge::CustomString s("ab");

  // Copy costructor
  ByteForge::CustomString c(b);
  // Copy assignment operator
  c = b;
  // Move cosntructor called
  ByteForge::CustomString e(std::move(c));
  // Move assignment called
  // d = std::move(a);
  ByteForge::CustomString u = std::move(s);
  u += " world";
  ByteForge::CustomString k = test.substring(2, 3);
  std::cout << k.c_str();
  //  assert(d == "Sun");
  //  assert(u == "hello world");
  //  assert(u != "hello worlds");
  //  assert(u.size() == 11);
  //  assert(g < f);
}
