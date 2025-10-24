#pragma once
#include <iostream>

class ScalarConverter
{
	private :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter &cpy);
		ScalarConverter &operator=(ScalarConverter &cpy);
	public :
		static void convert(std::string s);
};