#include "AMateria.hpp"

class Cure : public AMateria
{
  private:
  //
  public:
	Cure();
	~Cure();
	Cure(const Cure &cpy);
	Cure &operator=(const Cure &cpy);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};