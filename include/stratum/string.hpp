#pragma once
#include <cstddef>
namespace ByteForge {
constexpr int SSO_SIZE = 16;
class CustomString {
private:
  size_t size_;
  size_t capacity_;
  union {
    char *heap_data_;
    char sso_buff[SSO_SIZE + 1];
  };

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
  const char &operator[](size_t indexval) const;
  CustomString substring(size_t start, size_t len) const;
  // reserve
  void reserve(size_t n);
};
} // namespace ByteForge
