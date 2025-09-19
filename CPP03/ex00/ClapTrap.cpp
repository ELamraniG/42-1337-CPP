#include "ClapTrap.hpp"
    ClapTrap::ClapTrap() : name("slak") ,    hit_points(10), energy_points(10),
        attack_damage(0)
    {
        std::cout<<"default const called"<<std::endl;
    }
    ClapTrap::~ClapTrap()
    {
        std::cout<<"default deconst called"<<std::endl;
    }
    ClapTrap::ClapTrap(const ClapTrap &cpy)
    {
        std::cout<<"copy const called, from: "<<cpy.name<<std::endl;
        *this = cpy; 
    }
    ClapTrap & ClapTrap::operator=(const ClapTrap &cpy)
    {
        std::cout<<"copy assignment called, from: "<<cpy.name<<std::endl;
        this->hit_points = cpy.hit_points;
        this->energy_points = cpy.energy_points;
        this->attack_damage = cpy.attack_damage;
        this->name = cpy.name;
        return *this;
    }

        
        
        void ClapTrap::attack(const std::string &target)
        {
            if (this->hit_points == 0)
            {
                std::cout<<"ClapTrap "<<this->name<<" is dead and cannot attack!"<<std::endl;
                return;
            }
            if (this->energy_points == 0)
            {
                std::cout<<"ClapTrap "<<this->name<<" has no energy to attack!"<<std::endl;
                return;
            }
            this->energy_points--;
            std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attack_damage<<" damage"<<std::endl;
            std::cout<<"Energy points left: "<<this->energy_points<<std::endl;
        }
        void ClapTrap::takeDamage(unsigned int amount)
        { 
            std::cout<<"ClapTrap "<<this->name<<" took "<<amount<<" points"<<std::endl;
            if ((long long)this->hit_points - (long long)amount < 0)
                this->hit_points = 0;
            else
                 this->hit_points -= amount;
            std::cout<<"new hit points = "<<this->hit_points<<" hit points"<<std::endl;

        }
        void ClapTrap::beRepaired(unsigned int amount)
        {
            if (this->hit_points == 0)
            {
                std::cout<<"ClapTrap "<<this->name<<" is dead and cannot be repaired!"<<std::endl;
                return;
            }
            if (this->energy_points == 0)
            {
                std::cout<<"ClapTrap "<<this->name<<" has no energy to repair!"<<std::endl;
                return;
            }
            this->energy_points--;
            
            if ((unsigned long)this->hit_points + (unsigned long)amount > 4294967295U)
            {
                std::cout<<"ClapTrap "<<this->name<<" got back "<<amount<<" points (capped at max)"<<std::endl;
                this->hit_points = 4294967295U;
            }
            else
            { 
                this->hit_points += amount;  // FIX: Was subtracting instead of adding!
                std::cout<<"ClapTrap "<<this->name<<" got back "<<amount<<" points"<<std::endl;
            }
            std::cout<<"new hit points = "<<this->hit_points<<" hit points"<<std::endl;
            std::cout<<"Energy points left: "<<this->energy_points<<std::endl;
        }
