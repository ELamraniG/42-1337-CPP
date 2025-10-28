#pragma once
#include <iostream>

template <typename T>
class Array 
{
	public :
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
		size = 0;
		array = NULL;
		*this = cpy;
	}
	Array &operator=(Array &cpy)
	{
		if (array)
			delete []array;
		array = NULL;
		if (cpy.size == 0)
			return *this;
		array = new T[size];
		for(int i = 0; i < cpy.get_size();i++)
			array[i] = cpy[i];
		return *this;
	}
	unsigned int get_size()
	{
		return size;
	}
	T& operator[](int index)
	{
		if (index < 0 || index >= get_size())
			throw std::out_of_range("out of bound");
		return array[index];
	}
};