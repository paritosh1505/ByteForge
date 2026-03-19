#pragma once
#include <cstddef>
namespace ByteForge {
class CustomString {
private:
  size_t size_;
  size_t capacity_;
  char *data_;

public:
  CustomString();
  CustomString(const char *c);
  CustomString(const CustomString &other); // copy constructor
  CustomString &
  operator=(const CustomString &other);          // copy assignment operator
  CustomString(CustomString &&other) noexcept;   // move constructor
  CustomString &operator=(CustomString &&other); // move assignment operator
  ~CustomString();

  size_t size() const;
  bool empty() const;
  const char *c_str() const;

  // modifier
  CustomString &operator+=(const CustomString &other);
};
} // namespace ByteForge
