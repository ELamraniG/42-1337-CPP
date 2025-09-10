#include "Zombie.hpp"


int main()
{
    Zombie zombie1("main_stack_zombie");
    randomChump("RandomChump zombie");
    Zombie *zombie2 = new Zombie("main_heap_zombie");
    Zombie *zombie3 =newZombie("newzombie_heap_zombie");
    delete zombie3;
    delete zombie2;

        return (0);
}

