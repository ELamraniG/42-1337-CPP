#include "Cat.hpp"
#include "Brain.hpp"
Cat::Cat()
{
	std::cout << "Cat default const called" << std::endl;
	this->b = new Brain();
	this->type = "Cat";
}
Cat::~Cat()
{
	delete this->b;
	std::cout << "Cat default deconst called" << std::endl;
}
Cat::Cat(const Cat &cpy)
{
	std::cout << "Cat cpy const called" << std::endl;
	this->b = NULL;
	*this = cpy;
}
Cat &Cat::operator=(const Cat &cpy)
{
	std::cout << "Cat cpy assign called" << std::endl;
	if (this == &cpy)
		return (*this);
	this->type = cpy.type;
	if (this->b != NULL)
		delete this->b;
	this->b = new Brain(*cpy.b);
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
