#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe sorting_stuff;
	if (ac < 2)
		return std::cerr<<"error"<<std::endl,1;
	for (int i = 1;i < ac; i++)
	{
		std::string tmp = av[i];
		for(unsigned long i = 0;i < tmp.length();i++)
		{
			if (!std::isdigit(tmp[i]))
				return std::cerr<<"error"<<std::endl,1;
			sorting_stuff.insert(tmp[i] - '0');
		}
	}
	sorting_stuff.print();
}