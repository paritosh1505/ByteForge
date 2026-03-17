#pragma once
#include <cstddef>
namespace ByteForge {
class CustString {
private:
  size_t size_;
  size_t capacity_;
  char *data_;

public:
  CustString();
  CustString(const char *c);
  CustString(const CustString &other);
  CustString &operator=(const CustString &other);
  CustString(CustString &&other) noexcept;
  CustString &operator=(CustString &&other);
  ~CustString();

  size_t stsize() const;
  bool isEmpty() const;
  const char *c_str() const;
};
} // namespace ByteForge
