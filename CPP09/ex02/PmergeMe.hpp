#pragma once
#include <iostream>
#include <ostream>
#include <vector>
class PmergeMe
{
	private :
		std::vector<int> our_vec;
	public :
		std::vector<int> get_our_vec() const;
		void insert(int n) ;
		void print() const;
};

std::ostream &operator<<(std::ostream &o, PmergeMe &sorting_stuff);