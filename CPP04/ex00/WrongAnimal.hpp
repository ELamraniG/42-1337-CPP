
#pragma once
#include <iostream>

class WrongAnimal
{
  protected:
	std::string type;

  public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &cpy);
	WrongAnimal &operator=(const WrongAnimal &cpy);
	void makeSound() const;
	std::string getType() const;
};
