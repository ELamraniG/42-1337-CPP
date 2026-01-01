#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vector_time(0), deque_time(0), input_size(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : vector_list(other.vector_list), deque_list(other.deque_list),
      vector_time(other.vector_time), deque_time(other.deque_time),
      input_size(other.input_size) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    vector_list = other.vector_list;
    deque_list = other.deque_list;
    vector_time = other.vector_time;
    deque_time = other.deque_time;
    input_size = other.input_size;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse_input(int argc, char **argv) {
  if (argc < 2)
    throw std::runtime_error("Error");

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg.empty())
      throw std::runtime_error("Error");

    for (size_t j = 0; j < arg.length(); ++j) {
      if (!std::isdigit(arg[j]) && !(j == 0 && arg[j] == '+'))
        throw std::runtime_error("Error");
    }

    long num = std::atol(argv[i]);
    if (num < 0 || num > 2147483647)
      throw std::runtime_error("Error");

    vector_list.push_back(static_cast<int>(num));
    deque_list.push_back(static_cast<int>(num));
  }
  input_size = vector_list.size();

  std::vector<int> sorted = vector_list;
  std::sort(sorted.begin(), sorted.end());
  for (size_t i = 1; i < sorted.size(); ++i) {
    if (sorted[i] == sorted[i - 1])
      throw std::runtime_error("Error");
  }
}

std::vector<size_t> PmergeMe::generate_jacobsthal_sequence(size_t n) {
  std::vector<size_t> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);

  while (jacobsthal.back() < n) {
    size_t next = jacobsthal[jacobsthal.size() - 1] +
                  2 * jacobsthal[jacobsthal.size() - 2];
    jacobsthal.push_back(next);
  }
  return jacobsthal;
}

std::vector<size_t>
PmergeMe::build_jacobsthal_insertion_order(size_t pendSize) {
  std::vector<size_t> order;
  if (pendSize == 0)
    return order;

  std::vector<size_t> jacobsthal = generate_jacobsthal_sequence(pendSize + 1);

  std::vector<bool> inserted(pendSize, false);

  size_t prevJacob = 1;

  for (size_t k = 3; k < jacobsthal.size(); ++k) {
    size_t currJacob = jacobsthal[k];
    if (currJacob > pendSize)
      currJacob = pendSize;

    for (size_t i = currJacob; i > prevJacob; --i) {
      if (i - 1 < pendSize && !inserted[i - 1]) {
        order.push_back(i - 1);
        inserted[i - 1] = true;
      }
    }

    prevJacob = currJacob;
    if (prevJacob >= pendSize)
      break;
  }

  for (size_t i = 0; i < pendSize; ++i) {
    if (!inserted[i])
      order.push_back(i);
  }

  return order;
}

std::vector<int>::iterator
PmergeMe::binary_search_insert_vec(std::vector<int> &container,
                                   std::vector<int>::iterator end, int value) {
  std::vector<int>::iterator pos =
      std::lower_bound(container.begin(), end, value);
  return container.insert(pos, value);
}

std::deque<int>::iterator
PmergeMe::binary_search_insert_deq(std::deque<int> &container,
                                   std::deque<int>::iterator end, int value) {
  std::deque<int>::iterator pos =
      std::lower_bound(container.begin(), end, value);
  return container.insert(pos, value);
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
        pairs[j][0] = -1;
        break;
      }
    }
  }
  delete[] pairs;

  if (!pend.empty()) {
    big_numbers.insert(big_numbers.begin(), pend[0]);
  }

  if (pend.size() > 1) {
    std::vector<size_t> insertionOrder =
        build_jacobsthal_insertion_order(pend.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
      size_t idx = insertionOrder[i];
      if (idx == 0)
        continue;

      int value = pend[idx];
      binary_search_insert_vec(big_numbers, big_numbers.end(), value);
    }
  }

  if (leftover != -1) {
    binary_search_insert_vec(big_numbers, big_numbers.end(), leftover);
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
  for (size_t i = 0; i < pairCount; ++i)
    big_numbers.push_back(pairs[i][0]);

  ford_johnson_deque(big_numbers);

  std::deque<int> pend;

  for (size_t i = 0; i < big_numbers.size(); ++i) {
    for (size_t j = 0; j < pairCount; ++j) {
      if (pairs[j][0] == big_numbers[i]) {
        pend.push_back(pairs[j][1]);
        pairs[j][0] = -1;
        break;
      }
    }
  }
  delete[] pairs;

  if (!pend.empty()) {
    big_numbers.push_front(pend[0]);
  }

  if (pend.size() > 1) {
    std::vector<size_t> insertionOrder =
        build_jacobsthal_insertion_order(pend.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
      size_t idx = insertionOrder[i];
      if (idx == 0)
        continue;

      int value = pend[idx];
      binary_search_insert_deq(big_numbers, big_numbers.end(), value);
    }
  }

  if (leftover != -1) {
    binary_search_insert_deq(big_numbers, big_numbers.end(), leftover);
  }

  arr = big_numbers;
}

void PmergeMe::perform_merge() {
  std::clock_t start = std::clock();
  ford_johnson_vector(vector_list);
  std::clock_t end = std::clock();
  vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

  start = std::clock();
  ford_johnson_deque(deque_list);
  end = std::clock();
  deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMe::display_before() const {
  std::cout << "before: ";
  for (size_t i = 0; i < input_size && i < 5; ++i) {
    std::cout << vector_list[i];
    if (i < input_size - 1 && i < 4)
      std::cout << " ";
  }
  if (input_size > 5)
    std::cout << " ...";
  std::cout << std::endl;
}

void PmergeMe::display_after() const {
  std::cout << "after:  ";
  for (size_t i = 0; i < vector_list.size() && i < 5; ++i) {
    std::cout << vector_list[i];
    if (i < vector_list.size() - 1 && i < 4)
      std::cout << " ";
  }
  if (vector_list.size() > 5)
    std::cout << " ...";
  std::cout << std::endl;
}

void PmergeMe::display_times() const {
  std::cout << "time" << input_size << " of vector : " << vector_time << " us"
            << std::endl;
  std::cout << "time" << input_size << " of deque  : " << deque_time << " us"
            << std::endl;
}

const std::vector<int> &PmergeMe::get_vector() const { return vector_list; }

const std::deque<int> &PmergeMe::get_deque() const { return deque_list; }
