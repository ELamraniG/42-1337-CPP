#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
	private :
		std::string name;
	public :
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &cpy);
		DiamondTrap & operator=(const DiamondTrap &cpy);
		void whoAmI();


	public :

};