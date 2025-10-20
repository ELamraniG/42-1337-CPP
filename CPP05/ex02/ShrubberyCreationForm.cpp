#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
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
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm("ShrubberyCreationForm",145,137)
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
	if (is_excutable(executor) == false)
		return;
	std::string namee = get_target() + "_shrubbery";
	std::ofstream file(namee.c_str());
	if (file.fail())
		std::cout<<"problem in opening the file"<<std::endl;
	std::string treee = "     *\n   *****\n *********\n***********\n     *\n     *\n     *\n     *\n     *\n";
	file<<treee;
	return ;
}	


std::string ShrubberyCreationForm::get_target() const
{
	return this->target;
}