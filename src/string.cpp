#include "stratum/string.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
namespace ByteForge {
CustomString::CustomString() : size_(0), capacity_(0), data_(nullptr) {}
CustomString::CustomString(const char *c)
    : size_(c ? strlen(c) : 0), capacity_(size_ + 1),
      data_(new char[capacity_]) {
  if (c)
    std::memcpy(data_, c, capacity_);
  else
    data_[0] = '\0';
}
CustomString::~CustomString() { delete[] data_; }
size_t CustomString::size() const { return size_; }
bool CustomString::empty() const { return size_ == 0; }
const char *CustomString::c_str() const { return data_ ? data_ : ""; }

CustomString::CustomString(const CustomString &other) {
  this->size_ = other.size_;
  this->capacity_ = other.size_ + 1;
  this->data_ = new char[this->capacity_];
  if (other.data_ == nullptr) {
    this->data_[0] = '\0';
  } else {
    std::memcpy(this->data_, other.data_, this->capacity_);
  }
}
CustomString &CustomString::operator=(const CustomString &other) {
  delete[] data_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = new char[other.capacity_];
  std::memcpy(data_, other.data_, other.capacity_);
  return *this;
}
CustomString::CustomString(CustomString &&other) noexcept {
  size_ = other.size_;
  capacity_ = other.capacity_;
  data_ = other.data_;
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

CustomString &CustomString::operator=(CustomString &&other) {
  if (this != &other) {
    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}
CustomString &CustomString::operator+=(const CustomString &other) {
  size_t i = 0;
  size_t k = 0;
  size_t total_size = other.size_ + size_;
  while (i < total_size) {
    if (i == size_) {
      data_[i] = other.data_[k];
      std::cout << "jh";
    } else if (i > size_) {
      data_[i] = other.data_[k];
    }
    i++;
    k++;
    std::cout << "**" << this->data_[i] << "\n";
  }
  std::cout << "other" << other.data_ << this->data_ << "\n";
  return *this;
}
} // namespace ByteForge
