#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *deads = new Zombie[N];
    while (--N >= 0)
        deads[N].set_name(name);
    return deads;
}
