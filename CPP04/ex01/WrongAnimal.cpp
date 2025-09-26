
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default const called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default deconst called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	std::cout << "Cat cpy const called" << std::endl;
	*this = cpy;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy)
{
	std::cout << "Cat cpy assign called" << std::endl;
	this->type = cpy.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout<<"earth is flat"<<std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}