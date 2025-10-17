#include "Bureaucrat.hpp"
#include <fstream>
#include <ostream>
Form::Form() : name("useless"), grade_to_sign(20),grade_to_excute(12) ,
	is_signed(false)
{
	if (grade_to_sign < 1 || grade_to_excute < 1)
		throw(Form::GradeTooHighException());
	if (grade_to_sign > 150 || grade_to_excute > 150)
		throw(Form::GradeTooLowException());
}
Form::~Form()
{
}
Form::Form(std::string name, int grade_to_excute, int grade_to_sign) : 
name(name), grade_to_sign(grade_to_sign),grade_to_excute(grade_to_excute),
	 is_signed(false)
{
}
Form::Form(const Form &cpy) : 
name(cpy.get_name()), 
 grade_to_sign(cpy.get_grade_to_sign()),
 grade_to_excute(cpy.get_grade_to_excute()), 
 is_signed(cpy.get_is_signed()) 
{
}
Form &Form::operator=(const Form &cpy)
{
	this->is_signed = cpy.get_is_signed();
    return *this;
}

std::string Form::get_name() const
{
	return (this->name);
}
bool Form::get_is_signed() const
{
	return (this->is_signed);
}
int Form::get_grade_to_sign() const
{
	return (this->grade_to_sign);
}
int Form::get_grade_to_excute() const
{
	return (this->grade_to_excute);
}

void Form::beSigned(const Bureaucrat &buro)
{
	if (buro.getGrade() <= get_grade_to_sign())
	{
		this->is_signed = true;
		return ;
	}
	throw (Form::GradeTooLowException());
}


const char* Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream & operator<<(std::ostream &o,Form &f)
{
	o <<"Form "<<f.get_name()<<" grade to excute: "<< f.get_grade_to_excute()<<" grade to sign: "<< f.get_grade_to_sign()<< " is signed: "<<(f.get_is_signed() == true ? "true" : "false");
	return o;
}