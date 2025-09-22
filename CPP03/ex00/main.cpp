#include "ClapTrap.hpp"
int main() {
	ClapTrap lopo0("ae");
	std::cout<<"------------------\n";
	ClapTrap lopo1;
	std::cout<<"------------------\n";
	lopo1.attack("kapa");
	std::cout<<"------------------\n";
	ClapTrap lopo2("rapa");
	std::cout<<"------------------\n";
	lopo2.attack("ropo");
	std::cout<<"------------------\n";
	lopo2.beRepaired(55);
	std::cout<<"------------------\n";
	lopo2.takeDamage(5000);
	std::cout<<"------------------\n";
	lopo2.beRepaired(55);
	std::cout<<"------------------\n";
	ClapTrap lopo3 = lopo2;
	std::cout<<"------------------\n";
	ClapTrap lopo4(lopo3);
	std::cout<<"------------------\n";
	lopo4.attack("keke");
	std::cout<<"------------------\n";
	ClapTrap lopo5(lopo1);
	std::cout<<"------------------\n";
	lopo5.attack("last");
	std::cout<<"------------------\n";
	lopo5.beRepaired(9000);
	std::cout<<"------------------\n";

	return 0;
}