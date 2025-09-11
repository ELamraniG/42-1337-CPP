#include "HumanB.hpp"

    HumanB::HumanB(std::string str)
    {
        this->name = str;
        this->weaponB = NULL;
    }
    HumanB::~HumanB()
    {

    }

    void HumanB::setWeapon(Weapon &wep)
    {
        this->weaponB = &wep;
    }
    void HumanB::attack()
    {
        if(this->weaponB == NULL)
        {
            std::cout<<name<<" give me a weapon!"<<std::endl;
            return ;
        }
        std::cout<<name<<" attacks with their "<<weaponB->getType()<<std::endl;
    }
