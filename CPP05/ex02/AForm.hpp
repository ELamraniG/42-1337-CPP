#pragma once
#include <iostream>

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	const int grade_to_sign;
	const int grade_to_excute;
	bool is_signed;

  public:
    class GradeTooLowException :  public  std::exception
	{
		const char * what() const throw(); 
	};
    class GradeTooHighException : public   std::exception
	{
		const char * what() const throw(); 
	};
	Form();
	~Form();
	Form(std::string name, int grade_to_excute, int grade_to_sign);
	Form(const Form &cpy);
	Form &operator=(const Form &cpy);
	std::string get_name() const ;
	bool get_is_signed() const;
	int get_grade_to_sign() const;
	int get_grade_to_excute() const;
	void beSigned(const Bureaucrat &buro);
};

std::ostream & operator<<(std::ostream &e,Form &f);