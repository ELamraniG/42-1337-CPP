#pragma once
#include "Weapon.hpp"

class HumanA
{
    private :
        std::string name;
        Weapon &weaponA;
    public :
        HumanA(std::string str, Weapon &wep);
        ~HumanA();
        void attack();
};