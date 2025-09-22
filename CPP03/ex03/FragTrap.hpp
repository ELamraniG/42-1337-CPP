#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public :
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &cpy);
		FragTrap &operator=(const FragTrap &cpy);
		void highFivesGuys(void);
};