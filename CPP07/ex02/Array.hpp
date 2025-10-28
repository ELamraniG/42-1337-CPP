#pragma once
#include <iostream>

template <typename T>
class Array 
{
	unsigned int size;
	T* array;
	Array()
	{
		size = 0;
		array = NULL;
	}
	Array(unsigned int n)
	{
		size = n;
		array = new T[n];
	}
	~Array()
	{
		if (array)
			delete []array;
	}
	Array(Array &cpy)
	{
		if (array)
			delete []array;
		array = NULL;
		if (cpy.size == 0)
			return;
		array = new T[size];
		for(int i = 0; i < cpy.size;i++)
			array[i] = cpy[i];
	}
	unsigned int get_size()
	{
		return size;
	}
	Array &operator[](int index)
	{
		if (index < 0 || index >= get_size())
			return;
		//throw exception later
	}
};