#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
	if (ac != 2)
	{
		std::cout<<"we only accept 1 arg here"<<std::endl;
		return 0;
	}
	std::string s = av[1];
	BitcoinExchange f;
	f.parse_the_bitc();
	std::cout<<f.map_csv["2009-01-11"]<<"??"<<std::endl;
}