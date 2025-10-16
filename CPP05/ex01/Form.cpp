#include "Bureaucrat.hpp"
Form::Form() : name("useless"), grade_to_sign(20),grade_to_excute(12) ,
	is_signed(false)
{
}
Form::~Form()
{
}
Form::Form(std::string name, int grade_to_excute, int grade_to_sign,
	bool is_signed) : name(name), grade_to_sign(grade_to_sign),grade_to_excute(grade_to_excute),
	 is_signed(is_signed)
{
}
Form::Form(const Form &cpy) : name(cpy.get_name()), is_signed(cpy.get_is_signed()) ,
	grade_to_excute(cpy.get_grade_to_excute()), grade_to_sign(cpy.get_grade_to_sign())
{
	cpy.get_is_signed();
	this->get_grade_to_excute();
	*this = cpy;
}
Form &Form::operator=(const Form &cpy)
{
	this->is_signed = cpy.get_is_signed();
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
	return (grade_to_sign);
}
int Form::get_grade_to_excute() const
{
	return (grade_to_excute);
}

void Form::beSigned(const Bureaucrat &buro)
{
	if (buro.getGrade() >= get_grade_to_sign())
	{
		this->is_signed = true;
		std::cout << buro.getName() << " signed " << this->get_name();
		return ;
	}
	std::cout << buro.getName() << " couldn’t sign " << this->get_name() << "because his grade is low" << std::endl;
}

// later add << and gradetoo..