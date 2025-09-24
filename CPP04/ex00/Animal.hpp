#pragma once
#include <iostream>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	~Animal();
	Animal(const Animal &cpy);
	Animal &operator=(const Animal &cpy);
	virtual void makeSound() const;
	std::string getType() const;
};
