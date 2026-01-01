#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  try {
    PmergeMe sorter;

    sorter.parse_input(argc, argv);

    std::vector<int> original = sorter.get_vector();
    std::cout << "Before: ";
    for (size_t i = 0; i < original.size(); ++i) {
      std::cout << original[i];
      if (i < original.size() - 1)
        std::cout << " ";
    }
    std::cout << std::endl;

    sorter.perform_merge();

    const std::vector<int> &sorted = sorter.get_vector();
    std::cout << "After:  ";
    for (size_t i = 0; i < sorted.size(); ++i) {
      std::cout << sorted[i];
      if (i < sorted.size() - 1)
        std::cout << " ";
    }
    std::cout << std::endl;

    sorter.display_times();

    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
