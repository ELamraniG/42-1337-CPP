#include "Intern.hpp"
#include "AForm.hpp"

AForm	*create_president(std::string target)
{
	PresidentialPardonForm	*tmp;

	tmp = new PresidentialPardonForm(target);
	return tmp;
}
AForm	*create_robot(std::string target)
{
	RobotomyRequestForm	*tmp;

	tmp = new RobotomyRequestForm(target);
	return tmp;
}
AForm	*create_shrubery(std::string target)
{
	ShrubberyCreationForm	*tmp;

	tmp = new ShrubberyCreationForm(target);
	return tmp;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"presidential pardonForm", "robotomy request",
		"shrubbery creation"};
	AForm	*(*f[3])(std::string target);
	f[0] = create_president;
	f[1] = create_robot;
	f[2] = create_shrubery;
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout<<"Intern creates "<<name<<std::endl;
			return f[i](target);
		}
	}
	throw(Intern::FormDoesntExistException());
	return NULL;
}

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(Intern &cpy)
{
	(void)cpy;
}
Intern &Intern::operator=(Intern &cpy)
{
	(void)cpy;
	return *this;
}

const char * Intern::FormDoesntExistException::what() const throw()
{
	return "FormDoesn'tExist";
}