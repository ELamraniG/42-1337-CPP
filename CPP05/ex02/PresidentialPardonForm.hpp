#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
	private :
		std::string target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		virtual void execute(Bureaucrat const & executor) const;
		std::string get_target() const;
};