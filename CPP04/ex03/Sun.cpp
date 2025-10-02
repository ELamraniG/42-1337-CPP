#include "Sun.hpp"

Sun::Sun() : AMateria("sun")
{
	std::cout << "Sun default const called" << std::endl;
}
Sun::~Sun()
{
	std::cout << "Sun default deconst called" << std::endl;
}
Sun::Sun(const Sun &cpy)
{
	std::cout << "Sun copy const called" << std::endl;
	*this = cpy;
}
Sun &Sun::operator=(const Sun &cpy)
{
	std::cout << "Sun copy assign called" << std::endl;
	this->type = cpy.getType();
	return (*this);
}

AMateria *Sun::clone() const
{
	return (new Sun);
}
void Sun::use(ICharacter &target)
{
	std::cout << "Has Burned " << target.getName() << " into ashes" << std::endl;
}