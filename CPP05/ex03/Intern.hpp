#pragma  once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

class Intern 
{
	public :
		class FormDoesntExistException : public std::exception
		{
			const char* what() const throw();
		};
		AForm* makeForm(std::string name, std::string target);
		Intern();
		~Intern();
		Intern(Intern &cpy);
		Intern& operator=(Intern &cpy);

};