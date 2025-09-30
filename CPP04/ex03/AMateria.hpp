#pragma once
#include <iostream>
#include "ICharacter.hpp"
class AMateria
{
  protected:
	std::string type;

  public:
	AMateria();
	~AMateria();
	AMateria(AMateria const &cpy);
	AMateria(std::string const &type);
	AMateria &operator=(AMateria const &cpy);
	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};