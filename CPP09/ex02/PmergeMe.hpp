#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

class PmergeMe {
private:
  std::vector<int> vector_list;
  std::deque<int> deque_list;
  double vector_time;
  double deque_time;
  size_t input_size;

  static std::vector<size_t> generate_jacobsthal_sequence(size_t n);
  static std::vector<size_t> build_jacobsthal_insertion_order(size_t pendSize);

  void ford_johnson_vector(std::vector<int> &arr);
  void ford_johnson_deque(std::deque<int> &arr);
  std::vector<int>::iterator
  binary_search_insert_vec(std::vector<int> &container,
                           std::vector<int>::iterator end, int value);
  std::deque<int>::iterator
  binary_search_insert_deq(std::deque<int> &container,
                           std::deque<int>::iterator end, int value);

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void parse_input(int argc, char **argv);
  void perform_merge();
  void display_before() const;
  void display_after() const;
  void display_times() const;

  const std::vector<int> &get_vector() const;
  const std::deque<int> &get_deque() const;
};
