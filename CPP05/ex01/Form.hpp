#pragma once
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	const int grade_to_sign;
	const int grade_to_excute;
	bool is_signed;

  public:
	Form();
	~Form();
	Form(std::string name, int grade_to_excute, int grade_to_sign,
		bool is_signed);
	Form(const Form &cpy);
	Form &operator=(const Form &cpy);
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	std::string get_name() const ;
	bool get_is_signed() const;
	int get_grade_to_sign() const;
	int get_grade_to_excute() const;
	void beSigned(const Bureaucrat &buro);
};