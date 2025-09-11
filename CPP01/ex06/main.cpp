#include "Harl.hpp"

int main()
{
    Harl harlito;
    harlito.complain("DEBUG");
    std::cout<<"---------------------------"<<std::endl;
    harlito.complain("INFO");
    std::cout<<"---------------------------"<<std::endl;
    harlito.complain("WARNING");
    std::cout<<"---------------------------"<<std::endl;
    harlito.complain("ERROR");
    std::cout<<"---------------------------"<<std::endl;
    harlito.complain("just bs");
    std::cout<<"---------------------------"<<std::endl;
    return 0;
}