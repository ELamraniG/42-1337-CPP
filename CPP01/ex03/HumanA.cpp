#include "HumanA.hpp"

    HumanA::HumanA(std::string str, Weapon &wep) : weaponA(wep)
    {
        this->name = str;
    }
    HumanA::~HumanA()
    {

    }

    void HumanA::attack()
    {
        std::cout<<name<<" attacks with their "<<weaponA.getType()<<std::endl;
    }