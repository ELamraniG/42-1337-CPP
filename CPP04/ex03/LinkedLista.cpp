#include "AMateria.hpp"
#include "LinkedLista.hpp"

LinkedLista::LinkedLista() : lmateriel(NULL),  next(NULL)
{
	
}
LinkedLista::~LinkedLista()
{
	
}

void LinkedLista::add_end(AMateria *materiela)
{
	LinkedLista	*tmp;

	if (materiela == NULL)
	{
		std::cout << "enter a valid materiela" << std::endl;
		return ;
	}
	if (this->lmateriel == NULL)
		this->lmateriel = materiela;
	else
	{
		tmp = this;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LinkedLista;
		tmp->next->lmateriel = materiela;
		tmp->next->next = NULL;
	}
}
void LinkedLista::clear_lista()
{
	LinkedLista *tmp = this->next;
	LinkedLista *prev = NULL;
	if (this->lmateriel != NULL)
		delete this->lmateriel;
	while (tmp != NULL)
	{
		if (prev != NULL)
			delete prev;
		delete tmp->lmateriel;
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev != NULL)
		delete prev;
}