#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() : name("useless"), grade_to_sign(20),grade_to_excute(12) ,
	is_signed(false)
{
	if (this->grade_to_sign > 150 || this->grade_to_excute > 150)
		throw(AForm::GradeTooLowException());
	if (this->grade_to_sign < 1 || this->grade_to_excute < 1)
		throw(AForm::GradeTooHighException());
}
AForm::~AForm()
{
}
AForm::AForm(std::string name, int grade_to_sign, int grade_to_excute) : 
name(name), grade_to_sign(grade_to_sign),grade_to_excute(grade_to_excute),
	 is_signed(false)
{
	if (this->grade_to_sign > 150 || this->grade_to_excute > 150)
		throw(AForm::GradeTooLowException());
	if (this->grade_to_sign < 1 || this->grade_to_excute < 1)
		throw(AForm::GradeTooHighException());
}
AForm::AForm(const AForm &cpy) : 
name(cpy.get_name()), 
 grade_to_sign(cpy.get_grade_to_sign()),
 grade_to_excute(cpy.get_grade_to_excute()), 
 is_signed(cpy.get_is_signed()) 
{
}
AForm &AForm::operator=(const AForm &cpy)
{
	this->is_signed = cpy.get_is_signed();
    return *this;
}

std::string AForm::get_name() const
{
	return (this->name);
}
bool AForm::get_is_signed() const
{
	return (this->is_signed);
}
int AForm::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}
int AForm::get_grade_to_excute() const
{
	return (this->grade_to_excute);
}

void AForm::beSigned(const Bureaucrat &buro)
{
	if (buro.getGrade() <= get_grade_to_sign())
	{
		this->is_signed = true;
		return ;
	}
	throw (AForm::GradeTooLowException());
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "NotSignedException";
}

std::ostream & operator<<(std::ostream &o,AForm &f)
{
	o <<"AForm "<<f.get_name()<<" grade to excute: "<< f.get_grade_to_excute()<<" grade to sign: "<< f.get_grade_to_sign()<< " is signed: "<<(f.get_is_signed() == true ? "true" : "false");
	return o;
}

void AForm::is_excutable(const Bureaucrat &buro) const
{
	if (this->get_is_signed() == false)
		throw(AForm::NotSignedException());
	if (buro.getGrade() > get_grade_to_excute())
		throw(AForm::GradeTooLowException());
}