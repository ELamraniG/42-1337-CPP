#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *b;
	public:
	Dog();
	~Dog();
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &cpy);
	void makeSound() const;
	std::string getType() const;
};