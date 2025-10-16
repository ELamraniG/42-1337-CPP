#pragma once
#include <exception>
#include <fstream>
#include <iostream>

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
        std::string getName();
        int getGrade();
        void increment_buro();
        void decrement_buro();
};
// add << later

std::ostream & operator<<(std::ostream & o, Bureaucrat & buro)
{
    o << "Bureaucrat " << buro.getName() << ", grade " << buro.getGrade();
    return o;
}