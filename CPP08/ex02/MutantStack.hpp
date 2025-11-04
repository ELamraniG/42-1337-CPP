#pragma once
#include <iostream>
#include <iterator>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
  	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack(){};
	~MutantStack(){};
	MutantStack(MutantStack &cpy)
	{

		iterator beg2 = cpy.begin();
		while (beg2 != cpy.end())
		{
			this->push(*beg2);
			beg2++;
		}	
	};
	MutantStack &operator=(MutantStack &cpy)
	{
		if (this == &cpy)
			return *this;
		iterator beg = this->begin();
		while (beg != this->end())
		{
			this->pop();
		}
		iterator beg2 = cpy.begin();
		while (beg2 != cpy.end())
		{
			this->push(*beg2);
			beg2++;
		}
		return *this;
	};
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};