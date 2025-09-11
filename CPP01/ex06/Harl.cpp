#include "Harl.hpp"

void Harl::debug( void)
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}
void Harl::info( void)
{
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}
void Harl::warning( void)
{
    std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."<<std::endl;
}
void Harl::error( void)
{
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain( std::string level )
{
    std::string harls[4];
    void (Harl::*f[4])(void);
    f[0] = &Harl::debug;
    f[1] = &Harl::info;
    f[2] = &Harl::warning;
    f[3] = &Harl::error;
    harls[0] = "DEBUG";
    harls[1] = "INFO";
    harls[2] = "WARNING";
    harls[3] = "ERROR";
    int i = 0;
    while (i < 4 && harls[i] != level)
        i++;
    switch (i)
    {
        case 4:
            std::cout<<"only 4 levels available : DEBUG - INFO - WARNING - ERROR"<<std::endl;
            break;
        case 0:
           ( this->*f[0])();
        case 1:
            ( this->*f[1])();
        case 2:
            ( this->*f[2])();
        case 3:
            ( this->*f[3])();
    }
}
