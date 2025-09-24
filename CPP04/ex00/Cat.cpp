#include "Cat.hpp"
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default const called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat default deconst called" << std::endl;
}
Cat::Cat(const Cat &cpy)
{
	std::cout << "Cat cpy const called" << std::endl;
	*this = cpy;
}
Cat &Cat::operator=(const Cat &cpy)
{
	std::cout << "Cat cpy assign called" << std::endl;
	this->type = cpy.type;
	return (*this);
}
void Cat::makeSound() const
{
	std::cout<<"MAW MAW MAW"<<std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}