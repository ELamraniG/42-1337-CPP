#pragma once
#include <iostream>
#include <iterator>
#include <vector>
template<typename T>
int easyfind(T array, int target)
{
	typename T::iterator i = std::find(array.begin(),  array.end(), target);
	if (i == array.end())
		return -1;
	else
		return (std::distance(array.begin(), i));
}