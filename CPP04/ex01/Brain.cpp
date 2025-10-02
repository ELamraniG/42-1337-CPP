#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default const called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "tmp";
}
Brain::~Brain()
{
	std::cout << "Brain deconst called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "tmp";
}
Brain::Brain(const Brain &cpy)
{
	std::cout << "Brain copy const called" << std::endl;
	*this = cpy;
}
Brain &Brain::operator=(const Brain &cpy)
{
	std::cout << "copy assign called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cpy.ideas[i];
	return (*this);
}

void	Brain::set_ideas(std::string ideat)
{
	for(int i  = 0;i < 100;i++)
		this->ideas[i] = ideat;
}
void	Brain::print_ideas(void)
{
	std::cout<<"5 just to show"<<std::endl;
	for(int i  = 0;i < 5;i++)
		std::cout<<this->ideas[i]<<std::endl;
}