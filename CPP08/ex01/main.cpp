#include "Span.hpp"
#include <vector>

int	main(void)
{
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
	
	std::cout<<s.longestSpan()<<std::endl;
	std::cout<<s.shortestSpan();

}