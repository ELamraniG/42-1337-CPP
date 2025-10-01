#include "AMateria.hpp"

AMateria::AMateria() : type("no_type")
{
	std::cout << "amateria default const called";
}
AMateria::~AMateria()
{
	std::cout << "amateria default deconst called";
}
AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "amateria named const called";
}
AMateria::AMateria(AMateria const &cpy)
{
	std::cout << "amateria copy const called";
	*this = cpy;
}

AMateria &AMateria::operator=(AMateria const &cpy)
{
	std::cout << "amateria copy assign called";
	this->type = cpy.type;
	return *this;
}
std::string const &AMateria::getType() const
{
	return this->type;
}
void		AMateria::use(ICharacter &target)
{
	(void)target; //later
}