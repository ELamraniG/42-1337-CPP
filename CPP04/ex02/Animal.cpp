#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default const called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal default deconst called" << std::endl;
}
Animal::Animal(const Animal &cpy)
{
	std::cout << "Animal cpy const called" << std::endl;
	*this = cpy;
}
Animal &Animal::operator=(const Animal &cpy)
{
	std::cout << "Animal cpy assign called" << std::endl;
	this->type = cpy.type;
	return (*this);
}



std::string Animal::getType() const
{
	return this->type;
}

