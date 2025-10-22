#pragma  once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
	public :
	AForm* makeForm(std::string name, std::string target);
	Intern();
	~Intern();
	Intern(Intern &cpy);
	Intern& operator=(Intern &cpy);

};