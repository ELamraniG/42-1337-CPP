#include "AForm.hpp"
 #include <stdlib.h>
 #include <time.h>
class RobotomyRequestForm : public AForm
{
	private :
		std::string target;
	public :
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		 virtual void execute(Bureaucrat const & executor) const;
		std::string get_target() const;
};