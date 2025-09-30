#pragma once
#include <iostream>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &cpy);
	Animal &operator=(const Animal &cpy);
	virtual void makeSound() const = 0;
	std::string getType() const;
};
