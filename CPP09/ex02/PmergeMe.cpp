#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec_t(0), deq_t(0), size(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : our_vec(other.our_vec), our_deq(other.our_deq), vec_t(other.vec_t),
      deq_t(other.deq_t), size(other.size) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    our_vec = other.our_vec;
    our_deq = other.our_deq;
    vec_t = other.vec_t;
    deq_t = other.deq_t;
    size = other.size;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int> &input)
    : our_vec(input), our_deq(input.begin(), input.end()), vec_t(0), deq_t(0),
      size(input.size()) {}

std::vector<int> PmergeMe::gen_sthal_nums(int n) {
  std::vector<int> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);

  while (jacobsthal.back() < n) {
    size_t next = jacobsthal[jacobsthal.size() - 1] +
                  2 * jacobsthal[jacobsthal.size() - 2];
    jacobsthal.push_back(next);
  }
  return jacobsthal;
}

std::vector<int> PmergeMe::do_the_sthal(int pendSize) {
  std::vector<int> order;
  if (pendSize == 0)
    return order;

  std::vector<int> jacobsthal = gen_sthal_nums(pendSize + 1);

  int prevJacob = 1;

  for (int k = 3; k < (int)jacobsthal.size(); k++) {
    int currJacob = jacobsthal[k];
    if (currJacob > pendSize)
      currJacob = pendSize;

    for (int i = currJacob; i > prevJacob; i--)
      order.push_back(i - 1);

    prevJacob = currJacob;
    if (prevJacob >= pendSize)
      break;
  }
  return order;
}

void PmergeMe::binary_vec(std::vector<int> &container, int value) {
  std::vector<int>::iterator pos =
      std::lower_bound(container.begin(), container.end(), value);
  container.insert(pos, value);
}

void PmergeMe::binary_deq(std::deque<int> &container, int value) {
  std::deque<int>::iterator pos =
      std::lower_bound(container.begin(), container.end(), value);
  container.insert(pos, value);
}

void PmergeMe::ford_johnson_vector(std::vector<int> &arr) {
  size_t n = arr.size();

  if (n <= 1)
    return;

  if (n == 2) {
    if (arr[0] > arr[1])
      std::swap(arr[0], arr[1]);
    return;
  }

  size_t pairCount = n / 2;
  int (*pairs)[2] = new int[pairCount][2];
  int leftover = -1;
  if ((n % 2 == 1))
    leftover = arr[n - 1];

  for (size_t i = 0; i + 1 < n; i += 2) {
    if (arr[i] > arr[i + 1]) {
      pairs[i / 2][0] = arr[i];
      pairs[i / 2][1] = arr[i + 1];
    } else {
      pairs[i / 2][0] = arr[i + 1];
      pairs[i / 2][1] = arr[i];
    }
  }

  std::vector<int> big_numbers;
  for (size_t i = 0; i < pairCount; i++)
    big_numbers.push_back(pairs[i][0]);

  ford_johnson_vector(big_numbers);

  std::vector<int> pend;

  for (size_t i = 0; i < big_numbers.size(); i++) {
    for (size_t j = 0; j < pairCount; j++) {
      if (pairs[j][0] == big_numbers[i]) {
        pend.push_back(pairs[j][1]);
        break;
      }
    }
  }
  delete[] pairs;

  if (!pend.empty()) {
    big_numbers.insert(big_numbers.begin(), pend[0]);
  }

  if (pend.size() > 1) {
    std::vector<int> insertionOrder = do_the_sthal(pend.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
      int idx = insertionOrder[i];
      if (idx == 0)
        continue;

      int value = pend[idx];
      binary_vec(big_numbers, value);
    }
  }

  if (leftover != -1) {
    binary_vec(big_numbers, leftover);
  }

  arr = big_numbers;
}

void PmergeMe::ford_johnson_deque(std::deque<int> &arr) {
  size_t n = arr.size();

  if (n <= 1)
    return;

  if (n == 2) {
    if (arr[0] > arr[1])
      std::swap(arr[0], arr[1]);
    return;
  }

  size_t pairCount = n / 2;
  int (*pairs)[2] = new int[pairCount][2];
  int leftover = -1;

  if (n % 2 == 1)
    leftover = arr[n - 1];

  for (size_t i = 0; i + 1 < n; i += 2) {
    if (arr[i] > arr[i + 1]) {
      pairs[i / 2][0] = arr[i];
      pairs[i / 2][1] = arr[i + 1];
    } else {
      pairs[i / 2][0] = arr[i + 1];
      pairs[i / 2][1] = arr[i];
    }
  }

  std::deque<int> big_numbers;
  for (size_t i = 0; i < pairCount; i++)
    big_numbers.push_back(pairs[i][0]);

  ford_johnson_deque(big_numbers);

  std::deque<int> pend;

  for (size_t i = 0; i < big_numbers.size(); i++) {
    for (size_t j = 0; j < pairCount; j++) {
      if (pairs[j][0] == big_numbers[i]) {
        pend.push_back(pairs[j][1]);
        break;
      }
    }
  }
  delete[] pairs;

  if (!pend.empty()) {
    big_numbers.push_front(pend[0]);
  }

  if (pend.size() > 1) {
    std::vector<int> insertionOrder = do_the_sthal(pend.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
      int idx = insertionOrder[i];
      if (idx == 0)
        continue;

      int value = pend[idx];
      binary_deq(big_numbers, value);
    }
  }

  if (leftover != -1) {
    binary_deq(big_numbers, leftover);
  }

  arr = big_numbers;
}

void PmergeMe::do_ford_johnson() {
  print_before();
  std::clock_t start = std::clock();
  ford_johnson_vector(our_vec);
  std::clock_t end = std::clock();
  vec_t = (double)(end - start) / CLOCKS_PER_SEC * 1000;
  start = std::clock();
  ford_johnson_deque(our_deq);
  end = std::clock();
  deq_t = (double)(end - start) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::print_before() const {
  std::cout << "Before: ";
  for (size_t i = 0; i < size; i++) {
    std::cout << our_vec[i];
    if (i < size - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::print_after() const {
  std::cout << "After: ";
  for (size_t i = 0; i < our_vec.size(); i++) {
    std::cout << our_vec[i];
    if (i < our_vec.size() - 1)
      std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::print_times() const {
  std::cout << "Time to process a range of " << size
            << " elements with std::vector : " << vec_t << " ms" << std::endl;
  std::cout << "Time to process a range of " << size
            << " elements with std::deque  : " << deq_t << " ms" << std::endl;
}

void PmergeMe::print_all() const {
  print_after();
  print_times();
}

bool PmergeMe::is_sorted() const {
  for (size_t i = 1; i < our_vec.size(); i++) {
    if (our_vec[i] < our_vec[i - 1])
      return false;
  }
  for (size_t i = 1; i < our_deq.size(); i++) {
    if (our_deq[i] < our_deq[i - 1])
      return false;
  }
  return true;
}

const std::vector<int> &PmergeMe::get_vector() const { return our_vec; }

const std::deque<int> &PmergeMe::get_deque() const { return our_deq; }
