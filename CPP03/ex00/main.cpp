#include "ClapTrap.hpp"
int main() {
	ClapTrap test0("first clap");
	std::cout<<"------------------\n";
	ClapTrap test1;
	std::cout<<"------------------\n";
	test1.attack("kapa");
	std::cout<<"------------------\n";
	ClapTrap test2("rapa");
	std::cout<<"------------------\n";
	test2.attack("lopo");
	std::cout<<"------------------\n";
	test2.beRepaired(55);
	std::cout<<"------------------\n";
	test2.takeDamage(5000);
	std::cout<<"------------------\n";
	test2.beRepaired(55);
	std::cout<<"------------------\n";
	ClapTrap test3 = test2;
	std::cout<<"------------------\n";
	ClapTrap test4(test3);
	std::cout<<"------------------\n";
	test4.attack("someth");
	std::cout<<"------------------\n";
	ClapTrap test5(test1);
	std::cout<<"------------------\n";
	test5.attack("last");
	std::cout<<"------------------\n";
	test5.beRepaired(9000);
	std::cout<<"------------------\n";

	return 0;
}