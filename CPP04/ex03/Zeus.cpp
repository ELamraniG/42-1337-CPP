#include "Zeus.hpp"

Zeus::Zeus() : AMateria("zeus")
{
	std::cout << "Zeus default const called" << std::endl;
}
Zeus::~Zeus()
{
	std::cout << "Zeus default deconst called" << std::endl;
}
Zeus::Zeus(const Zeus &cpy)
{
	std::cout << "Zeus copy const called" << std::endl;
	*this = cpy;
}
Zeus &Zeus::operator=(const Zeus &cpy)
{
	std::cout << "Zeus copy assign called" << std::endl;
	this->type = cpy.getType();
	return *this;
}

AMateria *Zeus::clone() const
{
	return new Zeus;
}
void Zeus::use(ICharacter &target)
{
	std::cout<<"Has electrecuted "<<target.getName()<< " with Thunder" <<std::endl;
}