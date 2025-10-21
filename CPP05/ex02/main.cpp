
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>



int main(void) {
  srand(time(NULL));
  AForm *forma = NULL;
  try {
    Bureaucrat buro("buro1", 5);

      forma = new PresidentialPardonForm("hadak");
      buro.signForm(*forma);
      buro.executeForm(*forma);
      delete forma;

      forma = new RobotomyRequestForm("hadak2");
      buro.signForm(*forma);
      buro.executeForm(*forma);
      delete forma;

      forma = new ShrubberyCreationForm("hadak3");
      buro.signForm(*forma);
      buro.executeForm(*forma);
      delete forma;
      
      forma = new ShrubberyCreationForm("hadak4");
      Bureaucrat buro2("usless", 150);
      buro2.signForm(*forma);
      buro2.executeForm(*forma);
      delete forma;
      forma = NULL;
  } 
  catch (std::exception &e)
{
    delete forma;
    std::cout << e.what() << std::endl;
  }
}
