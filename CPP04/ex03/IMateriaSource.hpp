#pragma once
#include "Cure.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "Zeus.hpp"
#include "Sun.hpp"
class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};