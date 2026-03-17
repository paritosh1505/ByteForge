#include "stratum/string.hpp"
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <utility>
namespace ByteForge {
CustString::CustString() : size_(0), capacity_(0), data_(nullptr) {}
CustString::CustString(const char *c)
    : size_(c ? strlen(c) : 0), capacity_(size_ + 1),
      data_(new char[capacity_]) {
  if (c)
    std::memcpy(data_, c, capacity_);
  else
    data_[0] = '\0';
}
CustString::CustString(const CustString &other) {
  this->size_ = other.size_;
  this->capacity_ = other.size_ + 1;
  this->data_ = new char[this->capacity_];
  if (other.data_ == nullptr) {
    this->data_[0] = '\0';
  } else {
    std::memcpy(this->data_, other.data_, this->capacity_);
  }

  // CustString{cdata};
}
CustString &CustString::operator=(const CustString &other) {
  CustString temp(other);
  std::swap(size_, temp.size_);
  std::swap(capacity_, temp.capacity_);
  std::swap(data_, temp.data_);
  return *this;
}
CustString::CustString(CustString &&other) noexcept {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}
CustString::~CustString() { delete[] data_; }
size_t CustString::stsize() const { return size_; }
bool CustString::isEmpty() const { return size_ == 0; }
const char *CustString::c_str() const { return data_; }

CustString &CustString::operator=(CustString &&other) {
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
  this->data_ = new char[this->capacity_];
  data_ = other.data_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
  return *this;
}
} // namespace ByteForge
