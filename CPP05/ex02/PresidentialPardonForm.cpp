#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5) , target("hadak0")
{

}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25,5) , target(target)
{

}
PresidentialPardonForm::~PresidentialPardonForm()
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm("PresidentialPardonForm",25,5)
{
	*this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	this->target = cpy.get_target();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (is_excutable(executor) == false)
		return;
	std::cout<<get_target()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}	


std::string PresidentialPardonForm::get_target() const
{
	return this->target;
}