#include "AMateria.hpp"

class Sun : public AMateria
{
  private:
  //
  public:
	Sun();
	~Sun();
	Sun(const Sun &cpy);
	Sun &operator=(const Sun &cpy);
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};
