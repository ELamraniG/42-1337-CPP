#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "cure default const called" << std::endl;
}
Cure::~Cure()
{
	std::cout << "cure default deconst called" << std::endl;
}
Cure::Cure(const Cure &cpy)
{
	std::cout << "cure copy const called" << std::endl;
	*this = cpy;
}
Cure &Cure::operator=(const Cure &cpy)
{
	std::cout << "cure copy assign called" << std::endl;
	this->type = cpy.getType();
	return (*this);
}

AMateria *Cure::clone() const
{
	return new Cure;
}

void Cure::use(ICharacter &target)
{
	std::cout<<"heals "<<target.getName()<<"’s wounds"<<std::endl;
}