#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

   Bureaucrat::Bureaucrat() : name("useless mofo"), grade(150)
   {
   }
    Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
    {
            if (grade > 150)
                throw(Bureaucrat::GradeTooLowException());
            if (grade < 1)
                throw(Bureaucrat::GradeTooHighException());
        this->grade = grade;
    }
     Bureaucrat::~Bureaucrat()
    {

    }
        Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name)
        {
            *this = cpy;
        }
        Bureaucrat & Bureaucrat::operator=(const Bureaucrat &cpy)
        {
            if (this != &cpy)
                this->grade = cpy.grade;
            return *this;
        }
        int Bureaucrat::getGrade() const
        {
            return this->grade;
        }
        void Bureaucrat::increment_buro()
        {
            if (grade - 1 == 0)
                throw(Bureaucrat::GradeTooHighException());
            this->grade--;
        }
        void Bureaucrat::decrement_buro()
        {
            if (grade + 1 == 151)
                throw(Bureaucrat::GradeTooLowException());
            this->grade++;
        }

     std::string Bureaucrat::getName() const
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

    void signForm(Form &f)
    {
        f.beSigned(*this);
    }