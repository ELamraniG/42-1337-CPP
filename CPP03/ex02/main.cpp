#include "FragTrap.hpp"
int main() {
	ClapTrap test0("first_clap");
	std::cout<<"------------------\n";
	FragTrap test1;
	std::cout<<"------------------\n";
	ClapTrap *test1ptr = &test1;
	std::cout<<"------------------\n";
	test1ptr->attack("kapa");
	std::cout<<"------------------\n";
	std::cout<<"------------------\n";
	FragTrap test2("rapa");
	std::cout<<"------------------\n";
	test2.highFivesGuys();
	std::cout<<"------------------\n";
	test2.attack("ropo");
	std::cout<<"------------------\n";
	test2.beRepaired(55);
	std::cout<<"------------------\n";
	test2.takeDamage(5000);
	std::cout<<"------------------\n";
	test2.beRepaired(55);
	std::cout<<"------------------\n";
	FragTrap test3 = test2;
	std::cout<<"------------------\n";
	FragTrap test4(test3);
	std::cout<<"------------------\n";
	test4.attack("lopo");
	std::cout<<"------------------\n";
	FragTrap test5(test1);
	std::cout<<"------------------\n";
	test5.attack("last");
	std::cout<<"------------------\n";
	test5.highFivesGuys();
	std::cout<<"------------------\n";
	test5.beRepaired(9000);
	std::cout<<"------------------\n";

	return 0;
}