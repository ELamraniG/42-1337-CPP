#pragma once
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	MutantStack(){};
	~MutantStack(){};
	MutantStack(MutantStack &cpy)
	{
		dynamic_cast<std::stack<T>>(this) = dynamic_cast<std::stack<T>>(cpy);
		;
	};
	MutantStack &operator=(MutantStack &cpy)
	{
		dynamic_cast<std::stack<T>>(this) = dynamic_cast<std::stack<T>>(cpy);
		;
	};
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};