#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
	AMateria *to_learn[4];
	int counter;

  public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &cpy);
	MateriaSource &operator=(const MateriaSource &cpy);
	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};