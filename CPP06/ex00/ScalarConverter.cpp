#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <climits>


bool	check_char(std::string string)
{
	if (string.length() != 1 || std::isdigit(string[0]))
		return false;
	return true;
}

bool	check_int(std::string s)
{
	int	i;
	int	n;

	i = 0;
	if (s[0] != '-' && !std::isdigit(s[0]))
	{
		return false;
	}
	if (s[0] == '-')
		i++;
	if (i == s.length())
	{
		return false;
	}
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
		{
			return false;
		}
		i++;
	}
	return true;
}
bool	check_flaot(std::string s)
{
	int		i;
	bool	doted;
	int		len;
	float	f;

	std::string science_stuff[3] = {"-inf", "+inf", "nan"};
	for (int j = 0; j < 3; j++)
	{
		if (science_stuff[j] == s)
			return true;
	}
	i = 0;
	doted = false;
	len = 2;
	if (s[0] == '-')
	{
		len++;
		i++;
	}
	if (i == s.length())
		return false;
	while (i < s.length() - 1)
	{
		if (s[i] == '.')
		{
			if (doted == true || !std::isdigit(s[i + 1]))
				return false;
			doted = true;
		}
		else if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	if (s[i] != 'f' || s.length() <= len || !doted)
		return false;
	return true;
}
bool	check_double(std::string s)
{
	int		i;
	bool	doted;
	int		len;
	double	d;

	std::string science_stuff[3] = {"-inf", "+inf", "nan"};
	for (int j = 0; j < 3; j++)
	{
		if (science_stuff[j] == s)
			return true;
	}
	i = 0;
	doted = false;
	len = 1;
	if (s[0] == '-')
	{
		len++;
		i++;
	}
	if (i == s.length())
		return false;
	while (i < s.length())
	{
		if (s[i] == '.')
		{
			if (doted == true || !std::isdigit(s[i + 1]))
				return false;
			doted = true;
		}
		else if (!std::isdigit(s[i]))
			return false;
		i++;
	}
	if (s.length() <= len || !doted)
		return false;
	return true;
}
void print_all(double d);
void ScalarConverter::convert(std::string s)
{
	
	
	double d;
	if (check_char(s) == true)
	{
		d = static_cast<char>(s[0]);
	}
	else if (check_int(s))
	{
		d = (std::atoi(s.c_str()));
	}
	else if (check_flaot(s))
	{
		d = std::atof(s.c_str());
	}
	else if (check_double(s))
	{
		d = std::strtof(s.c_str(), NULL);
	}
	print_all(d);

}





void print_all(double d)
{
	char c = static_cast<char>(d);
	if (static_cast<int>(d) < 0 || static_cast<int>(d) > 255)
	{
		std::cout<<"char : impossible"<<std::endl;
	}
	else if (c <= static_cast<char>(13) || c == static_cast<char>(130))
	{
		std::cout<<"char : not displayble"<<std::endl;
	}
	if (static_cast<int>(d) < INT_MIN || static_cast<int>(d) > INT_MIN)
	{
		std::cout<<"int : impossible"<<std::endl;
	}
}