#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : counter(0)
{
	std::cout << "MateriaSource default const caleld" << std::endl;
}


MateriaSource::~MateriaSource() 
{
	std::cout << "MateriaSource default deconst caleld" << std::endl;
	for (int i = 0;i < this->counter;i++)
	{
		delete this->to_learn[i];
	}

}

MateriaSource::MateriaSource(const MateriaSource &cpy) : counter(0)
{
	std::cout << "MateriaSource copy const caleld" << std::endl;
	*this = cpy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
	std::cout << "MateriaSource copy assign	 caleld" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (this->to_learn[i])
		{
			delete this->to_learn[i];
			this->to_learn[i] = NULL;
			this->counter--;
		}
		i++;
	}
	for(i = 0; i < cpy.counter; i++)
	{
		this->to_learn[i] = cpy.to_learn[i]->clone();
		this->counter++;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (mat == NULL)
		return;
	if (counter == 4) 
	{
		delete mat;
		return;
	}
	this->to_learn[this->counter] = mat;
	this->counter++;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0;i < this->counter;i++)
	{
		if (this->to_learn[i]->getType() == type)
			return this->to_learn[i]->clone();
	}
	return 0;
}