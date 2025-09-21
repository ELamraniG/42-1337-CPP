#include "ScavTrap.hpp"
int main() {
	ClapTrap lopo0("ae");
	std::cout<<"------------------\n";
	ScavTrap lopo1;
	std::cout<<"------------------\n";
	ClapTrap *lopo1ptr = &lopo1; // possible uses func dyal claptrap because of the type
	std::cout<<"------------------\n";
	lopo1ptr->attack("kapa");
	std::cout<<"------------------\n";
	//ScavTrap *lopo0ptr = &lopo0;// not possible
	std::cout<<"------------------\n";
	ScavTrap lopo2("rapa");
	std::cout<<"------------------\n";
	lopo2.guardGate();
	std::cout<<"------------------\n";
	lopo2.attack("ropo");
	std::cout<<"------------------\n";
	lopo2.beRepaired(55);
	std::cout<<"------------------\n";
	lopo2.takeDamage(5000);
	std::cout<<"------------------\n";
	lopo2.beRepaired(55);
	std::cout<<"------------------\n";
	ScavTrap lopo3 = lopo2;
	std::cout<<"------------------\n";
	ScavTrap lopo4(lopo3);
	std::cout<<"------------------\n";
	lopo4.attack("keke");
	std::cout<<"------------------\n";
	ScavTrap lopo5(lopo1);
	std::cout<<"------------------\n";
	lopo5.attack("last");
	std::cout<<"------------------\n";
	lopo5.guardGate();
	std::cout<<"------------------\n";
	lopo5.beRepaired(9000);
	std::cout<<"------------------\n";

	return 0;
}