#include "Character.hpp"
#include "AMateria.hpp"
#include "LinkedLista.hpp"

Character::Character() : name("nameless_bonobo"), materiel_size(0)
{
	std::cout << "Character default const called" << std::endl;
	lista = new LinkedLista();
	for (int i = 0; i < 4; i++)
		this->materiels[i] = NULL;
}
Character::~Character()
{
	std::cout << "Character default deconst called" << std::endl;
	this->lista.clear_lista();
	delete lista;
}
Character::Character(std::string name) : name(name), materiel_size(0)
{
	std::cout << "Character named const called" << std::endl;
	lista = new LinkedLista();
	for (int i = 0; i < 4; i++)
		this->materiels[i] = NULL;
}
std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	if (materiel_size == 4)
	{
		this->lista->add_end(m);
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->materiels[i] == NULL)
		{
			this->materiels[i] = m;
			break ;
		}
	}
	this->lista->add_end(m);
	this->materiel_size++;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->materiels[idx] == NULL)
		return ;
	this->materiels[idx] = NULL;
	this->materiel_size--;
}
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->materiels[idx] != NULL)
		this->materiels[idx]->use(target);
}

// add the rest of canonial form later

Character::Character(const Character &cpy)
{
	std::cout << "cop const called" << std::endl;
	this->lista = new LinkedLista();
	*this = cpy;
}

Character &Character::operator=(const Character &cpy)
{
	 if (this == &cpy)
        return *this;
	lista->clear_lista();
	delete lista;
	lista = new LinkedLista();
	this->materiel_size = 0;
	AMateria *tmp;
	this->name = cpy.name;
	for(int i = 0; i< 4;i++)
	{
		if (cpy.materiels[i] != NULL)
		{
			tmp = cpy.materiels[i]->clone();
			this->materiels[i] = tmp;
			lista->add_end(tmp);
			this->materiel_size++;
		}
		else
			this->materiels[i] = NULL;
	}
	return *this;
}