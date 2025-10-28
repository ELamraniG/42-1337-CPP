#pragma once
#include <iostream>

template <typename T> class Array {
private:
  unsigned int arr_size;
  T *array;

public:
  Array() {
    arr_size = 0;
    array = NULL;
  }
  Array(unsigned int n) {
    arr_size = n;
    array = new T[n];
  }
  ~Array() {
    if (array)
      delete[] array;
  }
  Array(const Array &cpy) {
    arr_size = 0;
    array = NULL;
    *this = cpy;
  }
  Array &operator=(const Array &cpy) {
    if (this == &cpy)
      return *this;
    if (array)
      delete[] array;
    array = NULL;
    if (cpy.arr_size == 0)
    {
      arr_size = 0;
      return *this;
    }
    this->arr_size = cpy.size();
    array = new T[arr_size];
    for (unsigned int i = 0; i < cpy.size(); i++)
      array[i] = cpy[i];
    return *this;
  }
  unsigned int size() const { return arr_size; }
  T &operator[](unsigned int index) {
    if (index >= size())
      throw std::out_of_range("index out of range");
    return array[index];
  }
};