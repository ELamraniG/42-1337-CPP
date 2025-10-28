#pragma once
#include <iostream>


void pri(int &x)
{
	x++;
	
}

void pri2(const int &x)
{
	std::cout<<x<<std::endl;
}

template <typename T,typename F>
void iter(T *array,const int size, F func)
{
	for (int i = 0;i < size; i++)
	{
		func(array[i]);
	}
}