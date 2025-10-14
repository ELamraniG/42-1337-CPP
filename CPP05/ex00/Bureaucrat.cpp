#include "Bureaucrat.hpp"
#include <exception>

   
    Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
    {
            if (grade > 150)
                throw(Bureaucrat::GradeTooHighException());
            if (grade < 0)
                throw(Bureaucrat::GradeTooLowException());
        this->grade = grade;
    }
     Bureaucrat::~Bureaucrat()
     {

     }
        Bureaucrat::Bureaucrat(Bureaucrat &cpy)
        {

        }
        Bureaucrat & Bureaucrat::operator=(Bureaucrat &cpy)
        {

        }
        int Bureaucrat::getGrade()
        {
            return this->grade;
        }
        void Bureaucrat::increment_buro()
        {

        }
        void Bureaucrat::decrement_buro()
        {

        }

     std::string Bureaucrat::getName()
    {
        return this->name;
    }

    const char* Bureaucrat::GradeTooHighException::what() const throw()
    {
        return "GradeTooHighException";
    }










    const char *Bureaucrat::GradeTooLowException::what() const throw()
    {
        return "GradeTooLowException";
    }