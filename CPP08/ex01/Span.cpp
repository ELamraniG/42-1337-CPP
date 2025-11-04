#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span() : arr_size(0), arr_length(0)
{
}
Span::Span(unsigned int n) : arr_size(n), arr_length(0)
{
}
Span::~Span()
{
}
Span::Span(Span &cpy)
{
	arr_size = cpy.get_arr_size();
	array = cpy.get_array();
}
Span &Span::operator=(Span &cpy)
{
	arr_size = cpy.get_arr_size();
	array = cpy.get_array();
	return *this;
}
int Span::shortestSpan()
{
	if (arr_length == 0 || arr_length == 1)
		return -1;
	std::vector<int> tmp = array;
	std::sort(tmp.begin(),tmp.end());
	long shortest = *(tmp.begin() + 1) - *(tmp.begin());
	for (std::vector<int>::iterator i = tmp.begin() + 1;i != tmp.end() - 1; i++)
	{
		if (*(i + 1) - *i < shortest)
			shortest = *(i + 1) - *i;
	}
	return shortest;
}
int Span::longestSpan()
{
	if (arr_length == 0 || arr_length == 1)
		return -1;
	std::vector<int>::iterator max = std::max_element(array.begin(),array.end());
	std::vector<int>::iterator min = std::min_element(array.begin(),array.end());
	return *max - *min;
}
void Span::addNumber(int n)
{
	if (arr_size == arr_length)
	{
		std::cout<<"array is full1"<<std::endl;
		return;
	}
	array.push_back(n);
	arr_length++;
}


unsigned int Span::get_arr_size()
{
	return (arr_size);
}
unsigned int Span::get_arr_length()
{
	return (arr_length);
}
std::vector<int> Span::get_array()
{
	return (array);
}