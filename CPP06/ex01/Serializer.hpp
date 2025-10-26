#pragma once
#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
	int i;
	int f;
}Data;

class  Serializer
{
	private :
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};