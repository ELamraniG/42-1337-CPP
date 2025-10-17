#pragma once
#include "AForm.hpp"

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        class GradeTooHighException : public std::exception
        {
            public :
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                const char *what() const throw();
        };
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat & operator=(const Bureaucrat &cpy);
        std::string getName() const;
        int getGrade() const;
        void increment_buro();
        void decrement_buro();
        void signForm(Form &f);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & buro);