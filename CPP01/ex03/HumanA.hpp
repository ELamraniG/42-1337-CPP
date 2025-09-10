#pragma once
#include "Weapon.hpp"

class HumanA
{
    private :
        std::string name;
        Weapon weaponA;
    public :
        HumanA();
        ~HumanA();
        void attack();
};