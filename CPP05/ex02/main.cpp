
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	try {
		Bureaucrat buro("buro1",5);
		AForm *forma = new PresidentialPardonForm("hadak");
		buro.signForm(*forma);
		buro.executeForm(*forma);

		delete forma;
		forma = new RobotomyRequestForm("hadak2");
		buro.signForm(*forma);
		buro.executeForm(*forma);

		delete forma;
		forma = new ShrubberyCreationForm("hadak3");
		buro.signForm(*forma);
		buro.executeForm(*forma);

		Bureaucrat buro2("usless",150);
		buro2.signForm(*forma);
		buro.executeForm(*forma);
		delete forma;


	}
	catch (std::exception &e)
	{
		e.what();
	}
}