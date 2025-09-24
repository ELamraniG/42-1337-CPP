#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("slak_clap_name") ,ScavTrap(), FragTrap(), name("slak") 
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name") , FragTrap(name + "_clap_name") , name(name)
{ 
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}
DiamondTrap::~DiamondTrap()
{
	std::cout<<"Diamond Trap deconst called"<<std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &cpy)
{
	*this = cpy;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy)
{
	ClapTrap::name = cpy.ClapTrap::name;
	this->name = cpy.name;
	this->energy_points = cpy.energy_points;
	this->hit_points = cpy.hit_points;
	this->attack_damage = cpy.attack_damage;
	return *this;
}
void DiamondTrap::whoAmI()
{
	std::cout<<"i am: "<<this->name<<" + "<<ClapTrap::name<<std::endl;
}