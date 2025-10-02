#include "Dog.hpp"
#include "Brain.hpp"
Dog::Dog()
{
	std::cout << "Dog default const called" << std::endl;
	this->type = "Dog";
	this->b = new Brain();
}
Dog::~Dog() 
{
	delete this->b;
	std::cout << "Dog default deconst called" << std::endl;
}
Dog::Dog(const Dog &cpy)
{
	std::cout << "Dog cpy const called" << std::endl;
	this->b = NULL; 
	*this = cpy;
}
Dog &Dog::operator=(const Dog &cpy)
{
	
	std::cout << "Dog cpy assign called" << std::endl;
	if (this == &cpy)
		return (*this);
	this->type = cpy.type;
	if (this->b != NULL)
		delete this->b;
	this->b = new Brain(*cpy.b);
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

	void Dog::print_ideas()
	{
		b->print_ideas();
	}

	void Dog::set_brain(Brain *d)
	{
		if (d == NULL)
			return ;
		delete this->b;
		this->b = d;
	}