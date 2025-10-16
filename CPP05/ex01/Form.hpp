#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
class Form {
private:
  const std::string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_excute;

public:
  Form();
  ~Form();
  Form(std::string name, int grade_to_excute, int grade_to_sign, bool is_signed);
  Form(const Form &cpy);
  Form &operator=(const Form &cpy);
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  const std::string get_name();
  bool get_is_signed();
  const int get_grade_to_sign();
  const int get_grade_to_excute();
  void beSigned(Bureaucrat &buro);
};