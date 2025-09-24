#include "ScavTrap.hpp"
int main() {
	ClapTrap test0("ae");
	std::cout<<"------------------\n";
	ScavTrap test1;
	std::cout<<"------------------\n";
	ClapTrap *test1ptr = &test1; // possible uses func dyal claptrap because of the type
	std::cout<<"------------------\n";
	test1ptr->attack("kapa");
	std::cout<<"------------------\n";
	//ScavTrap *test0ptr = &test0;// not possible
	std::cout<<"------------------\n";
	ScavTrap test2("rapa");
	std::cout<<"------------------\n";
	test2.guardGate();
	std::cout<<"------------------\n";
	test2.attack("ropo");
	std::cout<<"------------------\n";
	test2.beRepaired(55);
	std::cout<<"------------------\n";
	test2.takeDamage(5000);
	std::cout<<"------------------\n";
	test2.beRepaired(55);
	std::cout<<"------------------\n";
	ScavTrap test3 = test2;
	std::cout<<"------------------\n";
	ScavTrap test4(test3);
	std::cout<<"------------------\n";
	test4.attack("keke");
	std::cout<<"------------------\n";
	ScavTrap test5(test1);
	std::cout<<"------------------\n";
	test5.attack("last");
	std::cout<<"------------------\n";
	test5.guardGate();
	std::cout<<"------------------\n";
	test5.beRepaired(9000);
	std::cout<<"------------------\n";

	return 0;
}