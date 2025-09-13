#include "Harl.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
         std::cout<<"only 4 levels available : DEBUG - INFO - WARNING - ERROR"<<std::endl;
        return 0;
    }
    Harl harlito;
    harlito.complain(av[1]);
    return 0;
}