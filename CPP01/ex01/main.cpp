#include "Zombie.hpp"


int main()
{
    Zombie *zombies;
    int n = 15;
    zombies = zombieHorde(n, "deads");
    for (int i = 0; i < n; i++)
        zombies[i].announce();
    delete []zombies;

        return (0);
}

