#pragma once

#include <cstdlib>
#include <algorithm>
#include <iostream>

template <typename T>
class SimpleVector {
public:
  SimpleVector() {}
  explicit SimpleVector(size_t size) {
    this->capacity_ = 2 * size;
    this->size_ = size;
    this->Init();
  }
  void Init() {
    this->data = new T[this->capacity_];
    this->end_ = this->data + this->size_;
  }
  ~SimpleVector() {
    delete[] this->data;
  }

  T& operator[](size_t index) {
    return *(this->data + index);
  }

  T* begin() { return this->data; }
  T* end() { return this->end_; }

  const T* begin() const { return this->data; }
  const T* end() const { return this->end_; }

  size_t Size() const {
    return this->size_;
  }
  size_t Capacity() const {
    return this->capacity_;
  }

  void PushBack(const T& value) {
    if ( !this->capacity_ ) {
      this->capacity_ = 1;
      this->Init();
    } else if ( this->size_ == this->capacity_ ) {
      this->capacity_ *= 2;
      T* new_data = new T[this->capacity_];
      // copy old elements into new block of memory and clean the old one;
      std::copy(this->data, this->end_, new_data);

      delete[] this->data;
      this->data = new_data;
    }
    *(this->data + this->size_) = value;
    this->size_++;
    this->end_ = this->data + this->size_;
  }

private:
  T* data = nullptr;
  T* end_ = nullptr;
  size_t capacity_ = 0;
  size_t size_ = 0;
};
