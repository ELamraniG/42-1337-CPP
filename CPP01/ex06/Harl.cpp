#include "Harl.hpp"

void Harl::debug( void)
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}
void Harl::info( void)
{
    std::cout<<"I cannot believe adding extra bacon costs more money."<<std::endl<<"You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}
void Harl::warning( void)
{
    std::cout<<"I think I deserve to have some extra bacon for free."<<std::endl<<"I’ve been coming for years, whereas you started working here just last month."<<std::endl;
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
            std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
            break;
        case 0:
            std::cout<<"[ DEBUG ]"<<std::endl;
           (this->*f[0])();
           std::cout<<std::endl;
           // fall through
        case 1:
           std::cout<<"[ INFO ]"<<std::endl;
           (this->*f[1])();
           std::cout<<std::endl;
           // fall through
        case 2:
           std::cout<<"[ WARNING ]"<<std::endl;
           (this->*f[2])();
           std::cout<<std::endl;
           // fall through
        case 3:
            std::cout<<"[ ERROR ]"<<std::endl;
            (this->*f[3])();
            std::cout<<std::endl;
            break;
    }
}
