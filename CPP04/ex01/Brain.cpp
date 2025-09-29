#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default const called" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain deconst called" << std::endl;
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
		return *this;
}