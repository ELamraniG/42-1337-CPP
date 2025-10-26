#pragma once
#include <iostream>


typedef struct s_Data
{
	int i;
	int f;
}Data;

class  Serializer
{
	private :
		Serializer();
	public :
		static std::uintptr_t serialize(Data* ptr);
		static Data* deserialize(std::uintptr_t raw);
};