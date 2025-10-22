#pragma once
#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
	private :
		std::string target;
	public :
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		virtual void execute(Bureaucrat const & executor) const;
		std::string get_target() const;
};