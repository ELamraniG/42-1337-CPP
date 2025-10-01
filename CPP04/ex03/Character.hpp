#pragma once
#include "ICharacter.hpp"
#include "LinkedLista.hpp"

class Character : public ICharacter
{
  private:
	std::string name;
	int materiel_size;
	AMateria *materiels[4];
	LinkedLista lista;
  public:
	Character();
	Character(std::string name);
	~Character();
	// Character(const Character &cpy);
	// Character &operator=(const Character &cpy);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};