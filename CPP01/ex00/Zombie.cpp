#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) 
{  
    std::cout<<"zombie created: "<<get_name()<<std::endl;
}

Zombie::~Zombie() 
{  
    std::cout<<"zombie deleted "<<get_name()<<std::endl;
}

std::string Zombie::get_name()
{
    return this->name;
}

void Zombie::announce( void )
{
    std::cout<<get_name()<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
