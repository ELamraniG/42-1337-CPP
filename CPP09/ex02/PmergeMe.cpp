#include "PmergeMe.hpp"

void PmergeMe::insert(int n) 
{
	our_vec.push_back(n);
}


std::vector<int> PmergeMe::get_our_vec() const
{
	return our_vec;
}

std::ostream &operator<<(std::ostream &o, const std::vector<int> &tmp)
{
	for(unsigned long i = 0; i < tmp.size();i++)
	{
		o << tmp[i];
		if (i != tmp.size() - 1)
		o << " ";
	}
	return o;	
}

void PmergeMe::print() const
{
	std::cout<<our_vec<<std::endl;
}