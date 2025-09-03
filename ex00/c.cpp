#include <iostream>

//read about std and namespaces
//read about strings in c++
// read about cout and endl

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	int i = 1;
	int j;
	std::string arg;
	while (av[i])
	{
		j = 0;
		arg = av[i];
		while (arg[j])
		{
			arg[j] = std::toupper(arg[j]);
			j++;
		}
		std::cout<< arg;
		i++;
	}
	std::cout<<std::endl;
	return (0);
}
