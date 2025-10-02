#include "AMateria.hpp"

AMateria::AMateria() : type("no_type")
{
	std::cout << "amateria default const called"<<std::endl;
}
AMateria::~AMateria()
{
	std::cout << "amateria default deconst called"<<std::endl;
}
AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "amateria named const called"<<std::endl;
}
AMateria::AMateria(AMateria const &cpy)
{
	std::cout << "amateria copy const called"<<std::endl;
	*this = cpy;
}

AMateria &AMateria::operator=(AMateria const &cpy)
{
	std::cout << "amateria copy assign called"<<std::endl;
	this->type = cpy.type;
	return *this;
}
std::string const &AMateria::getType() const
{
	return this->type;
}
void		AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout<<"will never"<<std::endl;
}