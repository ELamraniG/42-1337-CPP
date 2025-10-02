#include "AMateria.hpp"

class Zeus : public AMateria
{
  private:
  //
  public:
	Zeus();
	~Zeus();
	Zeus(const Zeus &cpy);
	Zeus &operator=(const Zeus &cpy);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};
