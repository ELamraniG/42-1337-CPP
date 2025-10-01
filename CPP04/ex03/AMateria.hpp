#pragma once
#include <iostream>
#include "ICharacter.hpp"
class AMateria
{
  protected:
	std::string type;
  public:
	AMateria();
	virtual ~AMateria();
	AMateria(AMateria const &cpy);
	AMateria(std::string const &type);
	AMateria &operator=(AMateria const &cpy);



	//
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};