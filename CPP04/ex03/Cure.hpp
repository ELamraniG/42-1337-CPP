#include "AMateria.hpp"

class Cure : AMateria
{
  private:
  //
  public:
	Cure();
	~Cure();
	Cure(const Cure &cpy);
	Cure &operator=(const Cure &cpy);
};