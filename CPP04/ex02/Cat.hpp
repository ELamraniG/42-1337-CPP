#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *b;
  public:
	Cat();
	~Cat();
	Cat(const Cat &cpy);
	Cat &operator=(const Cat &cpy);
	void makeSound() const;
	std::string getType() const;
};