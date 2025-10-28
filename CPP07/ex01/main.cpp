#include "iter.hpp"

int	main(void)
{
	int x[5] = {1,2,3,4,5};
	iter(x, 5,pri);
	iter(x, 5,pri2);
	const int x2[5] = {1,2,3,4,5};
	iter(x2, 5,pri2);
	return (0);
}