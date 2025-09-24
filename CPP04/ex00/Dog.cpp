#include "Dog.hpp"
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default const called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog default deconst called" << std::endl;
}
Dog::Dog(const Dog &cpy)
{
	std::cout << "Dog cpy const called" << std::endl;
	*this = cpy;
}
Dog &Dog::operator=(const Dog &cpy)
{
	std::cout << "Dog cpy assign called" << std::endl;
	this->type = cpy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout<<"Woof Woof Woof"<<std::endl;
}
std::string Dog::getType() const
{
	return this->type;
}