#include "PmergeMe.hpp"

static bool parse_input(int ac, char **av, std::vector<int> &result) {
  if (ac < 2)
    return false;

  std::vector<int> duplicate;

  for (int i = 1; i < ac; i++) {
    std::string arg = av[i];
    if (arg.empty())
      return false;

    for (size_t j = 0; j < arg.length(); j++) {
      if (!std::isdigit(arg[j]) &&
          !(j == 0 && arg[j] == '+' && arg.length() > 1))
        return false;
    }

    long num = std::atol(av[i]);
    if (num < 0 || num > 2147483647)
      return false;

    int value = num;
    if (std::find(duplicate.begin(), duplicate.end(), value) != duplicate.end())
      return false;
    duplicate.push_back(value);

    result.push_back(value);
  }
  return true;
}

int main(int ac, char **av) {
  std::vector<int> numbers;

  if (!parse_input(ac, av, numbers)) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  PmergeMe sorter(numbers);
  sorter.do_ford_johnson();
  sorter.print_all();

  // if (!sorter.is_sorted()) {
  //   std::cerr << "SORT FAILED" << std::endl;
  //   return 1;
  // } else {
  //   std::cout << "PERFECTLY SORTED" << std::endl;
  // }

  return 0;
}
