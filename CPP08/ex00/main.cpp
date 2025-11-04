
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> t;
	t.push_back(1114);
	t.push_back(3);
	t.push_back(5);
	t.push_back(7);
	t.push_back(9);
	t.push_back(9);
	t.push_back(9);
	t.push_back(9);
	t.push_back(9);
	t.push_back(11);
	int target = 5;
	int i = ::easyfind(t,target);
	if (i == -1)
		std::cout<<"target " << target <<" not found"<<std::endl;
	else 
		std::cout<<"target "<<target<<" found at index "<<i<<std::endl;

	target = 66;
	i = ::easyfind(t,target);
	if (i == -1)
		std::cout<<"target " << target <<" not found"<<std::endl;
	else 
		std::cout<<"target "<<target<<" found at index "<<i<<std::endl;
	return (0);
}