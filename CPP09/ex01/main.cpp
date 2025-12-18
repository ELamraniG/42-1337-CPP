#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return  std::cerr<<"Error"<<std::endl, 0;
	if (av[1][0] == 0)
	{
		std::cerr<<"Error"<<std::endl;
		return 0;
	}
	std::string s = av[1];
	RPN r(s);
	r.performRPN();
	return 0;
}