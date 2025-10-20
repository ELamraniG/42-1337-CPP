#pragma once
#include <iostream>

class Bureaucrat;

class AForm
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
	AForm();
	virtual ~AForm();
	AForm(std::string name,int grade_to_sign, int grade_to_excute);
	AForm(const AForm &cpy);
	AForm &operator=(const AForm &cpy);
	std::string get_name() const ;
	bool get_is_signed() const;
	int get_grade_to_sign() const;
	int get_grade_to_excute() const;
	void beSigned(const Bureaucrat &buro);
	bool is_excutable(const Bureaucrat &buro) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream &e,AForm &f);