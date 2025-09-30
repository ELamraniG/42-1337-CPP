
#include "WrongCat.hpp"
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default const called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat default deconst called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &cpy)
{
	std::cout << "WrongCat cpy const called" << std::endl;
	*this = cpy;
}
WrongCat &WrongCat::operator=(const WrongCat &cpy)
{
	std::cout << "WrongCat cpy assign called" << std::endl;
	this->type = cpy.type;
	return (*this);
}
void WrongCat::makeSound() const
{
	std::cout<<"MAW MAW MAW"<<std::endl;
}

std::string WrongCat::getType() const
{
	return this->type;
}