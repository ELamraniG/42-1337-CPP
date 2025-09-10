#pragma once
#include <iostream>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon(std::string str);
        ~Weapon();
        const std::string& getType();
        void setType(std::string str);
};
