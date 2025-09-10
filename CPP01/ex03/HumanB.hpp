
#pragma once
#include "Weapon.hpp"

class HumanB
{
    private :
        std::string name;
        Weapon *weaponB;
    public :
        HumanB(std::string str);
        ~HumanB();
        void set_weapon(Weapon &wep);
        void attack();
};