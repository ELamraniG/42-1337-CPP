#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat a("bob", 149);
    std::cout << a.getName() << " " << a.getGrade() << std::endl;
    a.increment_buro();
    std::cout << a.getName() << " " << a.getGrade() << std::endl;
    try
    {
        a.increment_buro();
        std::cout<<"will work fine"<<std::endl;  
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("alice", -1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
     try
    {
        Bureaucrat b("alice", 1231);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}