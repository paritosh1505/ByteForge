#include "stratum/string.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace ByteForge {
CustomString::CustomString() : size_(0), capacity_(SSO_SIZE) {
  sso_buff[0] = '\0';
}
CustomString::CustomString(const char *c)
    : size_(c ? strlen(c) : 0), capacity_(size_ + 1) {
  if (c && strlen(c) < 15) {
    std::memcpy(sso_buff, c, capacity_);
  } else if (c && strlen(c) >= 15) {
    memcpy(heap_data_, c, capacity_);
  } else {
    sso_buff[0] = '\0';
  }
}
CustomString::~CustomString() { delete[] data_; }
size_t CustomString::size() const { return size_; }
size_t CustomString::capacity() const { return capacity_; }
bool CustomString::empty() const { return size_ == 0; }
const char *CustomString::c_str() const { return data_; }

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
  size_t total_size = size_ + other.size_;
  char *new_size = new char[total_size + 1];
  for (size_t i = 0; i < size_; i++) {
    new_size[i] = data_[i];
  }
  for (size_t j = 0; j < other.size_; j++) {
    new_size[size_ + j] = other.data_[j];
  }
  new_size[total_size] = '\0';
  delete[] data_;
  data_ = new_size;
  size_ = total_size;
  capacity_ = total_size + 1;
  return *this;
}
bool CustomString::operator==(const CustomString &other) const {
  size_t counter = 0;
  size_t i = 0;
  if (this->size_ != other.size_) {
    return false;
  }

  while (i < size_) {
    if (this->data_[i] == other.data_[i]) {
      counter = counter + 1;
    } else {
      break;
    }
    i++;
  }
  if (counter == other.size_)
    return true;
  else
    return false;
}
char &CustomString::operator[](size_t index) {

  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[index];
}
const char &CustomString::operator[](size_t index) const {

  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[index];
}
bool CustomString::operator!=(const CustomString &other) const {
  if (size_ != other.size_) {
    return true;
  }
  for (size_t i = 0; i < size_; i++) {
    if (data_[i] != other.data_[i]) {
      return true;
    }
  }
  return false;
}
bool CustomString::operator<(const CustomString &other) const {
  size_t loopTraversal = 0;

  if (size_ > other.size_) {
    loopTraversal = other.size_;
  } else {
    loopTraversal = size_;
  }
  for (size_t i = 0; i < loopTraversal; i++) {
    if (data_[i] > other.data_[i]) {
      return false;
    } else if (data_[i] < other.data_[i]) {
      return true;
    }
  }
  return size_ < other.size_;
}
bool CustomString::operator>(const CustomString &other) const {
  size_t nval = size_ > other.size_ ? other.size_ : size_;
  // count <0 string is smaller
  // count =0 string is equal
  // count>0 string is greater
  int count = std::memcmp(data_, other.data_, nval);
  if (count != 0) {
    return count > 0;
  }
  return size_ > other.size_;
}
bool CustomString::operator<=(const CustomString &other) const {
  size_t nval = size_ > other.size_ ? other.size_ : size_;
  int cmp = std::memcmp(data_, other.data_, nval);
  if (cmp != 0) {
    return cmp <= 0;
  }
  return size_ <= other.size_;
}
bool CustomString::operator>=(const CustomString &other) const {
  size_t nval = size_ > other.size_ ? other.size_ : size_;
  int cmp = std::memcmp(data_, other.data_, nval);
  if (cmp != 0) {
    return cmp >= 0;
  }
  return size_ >= other.size_;
}
CustomString CustomString::operator+(const CustomString &other) const {
  size_t cap = other.size_ + size_ + 1;
  char *tmp = new char[cap];
  for (size_t i = 0; i < size_; i++) {
    tmp[i] = data_[i];
  }
  for (size_t j = 0; j < other.size_; j++) {
    tmp[size_ + j] = other.data_[j];
  }
  tmp[cap - 1] = '\0';
  CustomString result(tmp);

  delete[] tmp;
  return result;
}
CustomString CustomString::substring(size_t start, size_t len) const {
  char *tmp = new char[len + 1];
  size_t last = (start + len);
  tmp[0] = '\0';

  for (size_t i = start, j = 0; i < last; i++, j++) {
    tmp[j] = data_[i];
  }
  tmp[len] = '\0';
  CustomString result(tmp);
  delete[] tmp;
  return result;
}
void CustomString::reserve(size_t n) {
  if (n > this->capacity_) {
    char *newdata_ = new char[n];
    // newdata_[0] = '\0';
    std::memcpy(newdata_, data_, size_ + 1);
    delete[] data_;
    data_ = newdata_;
    capacity_ = n;
    std::cout << this->capacity_;
  }
}
} // namespace ByteForge
/*
void CustomString::reserve(size_t n) {
  if (n > this->capacity_) {
    this->capacity_ = n;
    std::cout << this->capacity_ << "\n";
    std::cout << this->size_ << "\n";

    char *newdata_ = new char[capacity_];
    CustomString result(newdata_);
    result.data_ = data_;
    delete[] data_;
  }
}
*/