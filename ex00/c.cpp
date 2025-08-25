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
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
				av[i][j] = std::toupper(av[i][j]);
			j++;
		}
		std::cout<< av[i];
		i++;
	}
	std::cout<<std::endl;
	return (0);
}
