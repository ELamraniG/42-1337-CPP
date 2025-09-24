#include "DiamondTrap.hpp"
int main() {
	std::cout<<"---------------------\n";
	DiamondTrap test1("eee");
	test1.whoAmI();
	test1.guardGate();
	test1.highFivesGuys();
	test1.attack("3tih");
	test1.takeDamage(1000);
	test1.attack("ok");
	std::cout<<"---------------------\n";
	DiamondTrap test2(test1);
	test2.whoAmI();
	test2.guardGate();
	test2.highFivesGuys();
	test2.attack("second");
	test2.takeDamage(1000);
	test2.attack("ok");
	std::cout<<"---------------------\n";
	DiamondTrap test3 = test2;
	test3.whoAmI();
	test3.guardGate();
	test3.highFivesGuys();
	test3.attack("second");
	test3.takeDamage(1000);
	test3.attack("ok");
	std::cout<<"---------------------\n";
	DiamondTrap last;
	last.whoAmI();
	last.guardGate();
	last.highFivesGuys();
	last.attack("lastest");
	last.takeDamage(5);
	return 0;
}
