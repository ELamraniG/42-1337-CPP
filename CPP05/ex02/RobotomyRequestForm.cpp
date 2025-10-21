#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72,45) , target("hadak00")
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{

}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",72,45) , target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy)
{
	*this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	this->target = cpy.get_target();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	is_excutable(executor);
	std::cout<<"zzzzzzzznnnnnnnn"<<std::endl;
	int n = rand() % 2;
	if (n == 0)
		std::cout<<get_target()<<" has been robotomized"<<std::endl;
	else
		std::cout<<"failed to robotomized "<<get_target()<<std::endl;
}	


std::string RobotomyRequestForm::get_target() const
{
	return this->target;
}