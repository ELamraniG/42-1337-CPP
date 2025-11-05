#include "Span.hpp"
#include <vector>

int main(void) {
  Span s(5);
  std::vector<int> tester;
  tester.push_back(1);
  tester.push_back(11);
  tester.push_back(23);
  tester.push_back(36);
  tester.push_back(50);
  s.add_numbers<std::vector<int> >(tester.begin(), tester.end());
  s.addNumber(1);
  s.add_numbers<std::vector<int> >(tester.begin(), tester.end());
  s.addNumber(1);
  s.addNumber(1);
  s.add_numbers<std::vector<int> >(tester.begin(), tester.end());
  s.addNumber(1);
  s.addNumber(1);
  s.addNumber(1);

  int longest = s.longestSpan();
  if (longest != -1)
    std::cout << longest << std::endl;

  int shortest = s.shortestSpan();
  if (shortest != -1)
    std::cout << shortest << std::endl;

  Span s2(10);
  s2.addNumber(42);
  int result = s2.shortestSpan();
  if (result == -1)
    std::cout << "AT LEAST 2 VARS" << std::endl;
}
