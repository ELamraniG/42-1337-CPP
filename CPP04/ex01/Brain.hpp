#pragma once
#include <iostream>

class Brain
{
  protected:
	std::string ideas[100];

  public:
	Brain();
	~Brain();
	Brain(const Brain &cpy);
	Brain &operator=(const Brain &cpy);
};