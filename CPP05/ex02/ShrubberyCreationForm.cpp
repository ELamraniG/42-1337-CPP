#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137), target("hadak0000")
{

}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145,137) , target(target)
{

}	
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy)
{
	*this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	this->target = cpy.get_target();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	is_excutable(executor);
	std::string namee = get_target() + "_shrubbery";
	std::ofstream file(namee.c_str());
	if (file.fail())
	{
		std::cout<<"problem in opening the file"<<std::endl;
		return;
	}
	std::string treee = "      *\n    *****\n  *********\n ***********\n      *\n      *\n      *\n      *\n      *\n*************\n";
	file<<treee;
	file.close();
}	


std::string ShrubberyCreationForm::get_target() const
{
	return this->target;
}