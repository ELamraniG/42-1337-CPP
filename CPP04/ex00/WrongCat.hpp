
#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &cpy);
	WrongCat &operator=(const WrongCat &cpy);
	virtual void makeSound() const;
	std::string getType() const;
};