#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "ice default const called" << std::endl;
}
Ice::~Ice()
{
	std::cout << "ice default deconst called" << std::endl;
}
Ice::Ice(const Ice &cpy)
{
	std::cout << "ice copy const called" << std::endl;
	*this = cpy;
}
Ice &Ice::operator=(const Ice &cpy)
{
	std::cout << "ice copy assign called" << std::endl;
	this->type = cpy.getType();
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice;
}
void Ice::use(ICharacter &target)
{
	std::cout<<"shoots an ice bolt at "<<target.getName()<<std::endl;
}