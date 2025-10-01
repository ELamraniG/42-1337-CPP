#pragma once
#include "AMateria.hpp"
#include <iostream>

struct LinkedLista
{
  private:
	AMateria *lmateriel;
	LinkedLista *next;
  public:
	LinkedLista();
	~LinkedLista();
	void add_end(AMateria *materiela);
	void clear_lista();
};
