#include "stratum/string.hpp"
#include <cstddef>
#include <cstring>
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
CustString::~CustString() { delete[] data_; }
size_t CustString::stsize() const { return size_; }
bool CustString::isEmpty() const { return size_ == 0; }
const char *CustString::c_str() const { return data_; }
} // namespace ByteForge