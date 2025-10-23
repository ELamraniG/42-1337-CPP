
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	AForm	*forma;
	Intern	in;
	forma = NULL;
	srand(time(NULL));
	try
	{
		Bureaucrat buro("buro1", 5);
		forma = in.makeForm("presidential pardonForm", "getem");
		buro.signForm(*forma);
    forma->execute(buro);
    delete forma;
	forma = NULL;
		forma = in.makeForm("robotomy request", "getem2");
		buro.signForm(*forma);
    forma->execute(buro);
    delete forma;
	forma = NULL;
		forma = in.makeForm("shrubbery creation", "getem2");
		buro.signForm(*forma);
    forma->execute(buro);
    delete forma;
	forma = NULL;
	
	forma = in.makeForm("robotomy requesT", "getem2");
	}
	catch (std::exception &e)
	{
		if (forma)
    		delete forma;
		std::cout << e.what() << std::endl;
	}
}
