#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("slak_clap_name") , name("slak") 
{

}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") , name(name)
{ 
	
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