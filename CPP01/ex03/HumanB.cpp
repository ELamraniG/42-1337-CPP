#include "HumanB.hpp"

    HumanB::HumanB(std::string str)
    {
        this->name = str;
    }
    HumanB::~HumanB()
    {

    }

    void HumanB::set_weapon(Weapon &wep)
    {
        this->weaponB = wep;
    }
    void HumanB::attack()
    {
        std::cout<<name<<" attacks with their "<<weaponB.getType()<<std::endl;
    }
