#pragma once
#include <iostream>
#include <iterator>
#include <vector>

class Span {
private:
  unsigned int arr_size;
  unsigned int arr_length;
  std::vector<int> array;

public:
  Span();
  Span(unsigned int n);
  ~Span();
  Span(const Span &cpy);
  Span &operator=(const Span &cpy);
  int shortestSpan();
  int longestSpan();
  void addNumber(int n);
  template <typename T>
  void add_numbers(typename T::iterator begin, typename T::iterator end) {

    if (std::distance(begin, end) <= arr_size - arr_length) {
      while (begin != end) {
        addNumber(*begin);
        begin++;
      }
      return;
    }
    std::cout << "range bigger than length" << std::endl;
  }
  unsigned int get_arr_size() const;
  unsigned int get_arr_length() const;
  std::vector<int> get_array() const;
};