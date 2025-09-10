
#include "Weapon.hpp"

Weapon::Weapon(std::string str) : type(str)
{
    
}
Weapon::~Weapon() 
{

}
const std::string &Weapon::getType() 
{
    return this->type;
}
void Weapon::setType(std::string str) 
{
    this->type = str;
}
