#include "AMateria.hpp"

class Ice : public AMateria
{
  private:
  //
  public:
	Ice();
	~Ice();
	Ice(const Ice &cpy);
	Ice &operator=(const Ice &cpy);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};
