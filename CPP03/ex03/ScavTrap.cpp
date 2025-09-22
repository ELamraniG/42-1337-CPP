#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
	std::cout << "ScavTrap default const called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap named const called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap default deconst called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap copy const called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &cpy)
{
	std::cout << "ScavTrap copy assignement called" << std::endl;
	this->name = cpy.name;
	this->hit_points = cpy.hit_points;
	this->energy_points = cpy.energy_points;
	this->attack_damage = cpy.attack_damage;
	return *this;
}
void ScavTrap::attack(const std::string &target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead :(" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ",causing " << this->attack_damage << " damage" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}