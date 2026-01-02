#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
	if (ac != 2)
	{
		std::cerr << "we only accept 1 arg here" << std::endl;
		return 0;
	}
	std::string s = av[1];
	BitcoinExchange f(s);
	f.parse_the_bitc();
}