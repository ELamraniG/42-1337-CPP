#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int	main(void)
{
	std::cout << "try 1 creating invalide grade : 0" << std::endl;
	try
	{
		Bureaucrat a("manga", 0);
		std::cout << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "try 2 creating invalide grade : 155" << std::endl;
	try
	{
		Bureaucrat a("7ama9a", 155);
		std::cout << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "try 3 creating valide grade : 149" << std::endl;
	try
	{
		Bureaucrat a("lil2asaf", 149);
		std::cout << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "------------------------\n\n" << std::endl;
	Bureaucrat test1("test1", 1);
	std::cout << "incrementing grade 1 >> will fail" << std::endl;
	try
	{
		test1.increment_buro();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "------------------------\n" << std::endl;

	std::cout << "trying to create invalide forms" << std::endl;
	try
	{
		Form froma("froma", 1222, 10);
        std::cout<<froma<<"lopo\n\n\n\n\n\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	try
	{
		Form froma("froma", 12, -15);
        std::cout<<froma<<"lopo\n\n\n\n\n\n";
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "------------------------\n" << std::endl;

	Bureaucrat buro1("buro1", 143);
	Form form1("form1", 120, 10);
	std::cout << buro1 << std::endl;
	std::cout << form1 << std::endl;
    buro1.signForm(form1);
    std::cout << "------------------------" << std::endl;
    std::cout << "------------------------" << std::endl;
	try
	{
		for (int i = 0; i < 140; i++)
			buro1.increment_buro();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	buro1.signForm(form1);
	std::cout << form1 << std::endl;
}