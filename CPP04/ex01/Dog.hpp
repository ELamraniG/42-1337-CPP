#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog();
	~Dog();
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &cpy);
	void makeSound() const;
	std::string getType() const;
};