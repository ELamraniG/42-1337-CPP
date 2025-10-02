#include "AMateria.hpp"

class Fire : public AMateria
{
  private:
  //
  public:
	Fire();
	~Fire();
	Fire(const Fire &cpy);
	Fire &operator=(const Fire &cpy);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};
