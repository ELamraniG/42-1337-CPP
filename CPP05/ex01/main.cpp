#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat a("bob", 149);
    std::cout << a.getName() << " " << a.getGrade() << std::endl;
     try
    {
        a.increment_buro();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << a.getName() << " " << a.getGrade() << std::endl;
   
    Form f("lopo",100,10);
    a.signForm(f);
    std::cout<<f<<std::endl;
    try 
    {
    for(int i = 0; i < 140; i++)
    {
        a.increment_buro();   
    }
    } catch (const std::exception &e) {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<a<<std::endl;
    a.signForm(f);
    std::cout<<f<<std::endl;
}