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
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy)
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
	is_excutable(executor);
	std::cout<<get_target()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}	


std::string PresidentialPardonForm::get_target() const
{
	return this->target;
}