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
  size_t capacity() const;
  const char *c_str() const;

  // comparison operation
  bool operator==(const CustomString &other) const;
  bool operator!=(const CustomString &other) const;
  bool operator<(const CustomString &other) const;
  bool operator>(const CustomString &other) const;
  bool operator<=(const CustomString &other) const;
  bool operator>=(const CustomString &other) const;

  // concatenation operation
  CustomString &operator+=(const CustomString &other);
  CustomString operator+(const CustomString &other) const;
  // indexing
  char &operator[](size_t indexval);
  CustomString substring(size_t start, size_t len) const;
};
} // namespace ByteForge
