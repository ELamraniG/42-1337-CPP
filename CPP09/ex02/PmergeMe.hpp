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
  std::vector<int> our_vec;
  std::deque<int> our_deq;
  double vec_t;
  double deq_t;
  size_t size;

  std::vector<int> gen_sthal_nums(int n);
  std::vector<int> do_the_sthal(int pendSize);

  void ford_johnson_vector(std::vector<int> &arr);
  void ford_johnson_deque(std::deque<int> &arr);
  void binary_vec(std::vector<int> &container, int value);
  void binary_deq(std::deque<int> &container, int value);

public:
  PmergeMe();
  PmergeMe(const std::vector<int> &input);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void do_ford_johnson();
  void print_before() const;
  void print_after() const;
  void print_times() const;
  void print_all() const;
  bool is_sorted() const;

  const std::vector<int> &get_vector() const;
  const std::deque<int> &get_deque() const;
};
