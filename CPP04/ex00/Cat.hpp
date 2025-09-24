#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat();
	~Cat();
	Cat(const Cat &cpy);
	Cat &operator=(const Cat &cpy);
	virtual void makeSound() const;
	std::string getType() const;
};