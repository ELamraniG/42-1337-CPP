#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default const called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap named const called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap default deconst called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap copy const called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &cpy)
{
	std::cout << "FragTrap copy assignement called" << std::endl;
	this->name = cpy.name;
	this->hit_points = cpy.hit_points;
	this->energy_points = cpy.energy_points;
	this->attack_damage = cpy.attack_damage;
	return (*this);
}
void FragTrap::attack(const std::string &target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "FragTrap " << this->name << " is dead :(" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ",causing " << this->attack_damage << " damage" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "LETS HIGH FIVE !!!!!  :))))))))" << std::endl;
}