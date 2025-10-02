#include "Fire.hpp"

Fire::Fire() : AMateria("fire")
{
	std::cout << "Fire default const called" << std::endl;
}
Fire::~Fire()
{
	std::cout << "Fire default deconst called" << std::endl;
}
Fire::Fire(const Fire &cpy)
{
	std::cout << "Fire copy const called" << std::endl;
	*this = cpy;
}
Fire &Fire::operator=(const Fire &cpy)
{
	std::cout << "Fire copy assign called" << std::endl;
	this->type = cpy.getType();
	return *this;
}

AMateria *Fire::clone() const
{
	return new Fire;
}
void Fire::use(ICharacter &target)
{
	std::cout<<"BOMBARDS "<<target.getName()<< " with FIREBALLS" <<std::endl;
}