#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>

bool	check_char(std::string string)
{
	if (string.length() != 1 || std::isdigit(string[0]))
		return (false);
	return (true);
}

bool	check_int(std::string s)
{
	unsigned long i;

	i = 0;
	if (s[0] != '-' && !std::isdigit(s[0]))
	{
		return (false);
	}
	if (s[0] == '-')
		i++;
	if (i == s.length())
	{
		return (false);
	}
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}
bool	check_flaot(std::string s)
{
	unsigned long		i;
	bool	doted;
	unsigned long		len;

	std::string science_stuff[3] = {"-inf", "+inf", "nan"};
	for (int j = 0; j < 3; j++)
	{
		if (science_stuff[j] == s)
			return (true);
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
		return (false);
	while (i < s.length() - 1)
	{
		if (s[i] == '.')
		{
			if (doted == true || !std::isdigit(s[i + 1]))
				return (false);
			doted = true;
		}
		else if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	if (s[i] != 'f' || s.length() <= len || !doted)
		return (false);
	return (true);
}
bool	check_double(std::string s)
{
	unsigned long		i;
	bool	doted;
	unsigned long		len;

	std::string science_stuff[3] = {"-inf", "+inf", "nan"};
	for (int j = 0; j < 3; j++)
	{
		if (science_stuff[j] == s)
			return (true);
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
		return (false);
	while (i < s.length())
	{
		if (s[i] == '.')
		{
			if (doted == true || !std::isdigit(s[i + 1]))
				return (false);
			doted = true;
		}
		else if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	if (s.length() <= len || !doted)
		return (false);
	return (true);
}
void	print_all(double d);
void ScalarConverter::convert(std::string s)
{
	double	d;

	if (check_char(s) == true)
	{
		d = static_cast<char>(s[0]);
	}
	else if (check_int(s))
	{
		d = std::strtod(s.c_str(), NULL);
	}
	else if (check_flaot(s))
	{
		d = std::atof(s.c_str());
	}
	else if (check_double(s))
	{
		d = std::strtod(s.c_str(), NULL);
	}
	else
	{
		std::cout<<"either a literal ABzc... or number 42/42.25f/52.25"<<std::endl;
		return;
	}
	print_all(d);
}

void	print_char(double d);
void	print_int(double d);
void	print_float(double d);
void	print_double(double d);

void	print_all(double d)
{
	print_char(d);
	print_int(d);
	print_float(d);
	print_double(d);

}

void	print_char(double d)
{
	char	c = static_cast<char>(d);
	if (static_cast<int>(d) < 0 || static_cast<int>(d) > 255)
	{
		std::cout << "char : impossible" << std::endl;
	}
	else if (!std::isprint(c))
	{
		std::cout << "char : not displayble" << std::endl;
	}
	else
	{
		std::cout << "char : " << c << std::endl;
	}
}
void	print_int(double d)
{
	int n = static_cast<int>(d);
	if (d != d)
		std::cout<<"int : impossible"<<std::endl;
	else if (d < INT_MIN || d > INT_MAX)
	{
		std::cout << "int : impossible" << std::endl;
	}
	else
	{
		std::cout << "int : " << n<<std::endl;
	}
}
void	print_float(double d)
{
	float f = static_cast<float>(d);
	bool is_inf = (d == std::numeric_limits<float>::infinity() || d == -std::numeric_limits<float>::infinity());
	if (d != d)
		std::cout<<"float : nanf"<<std::endl;
	else if (is_inf)
	{
		if (d > 0)
			std::cout<<"float : +inff"<<std::endl;
		else
			std::cout<<"float : -inff"<<std::endl;
	}
	else
		std::cout << "float : " << std::fixed << std::setprecision(1)<<f <<"f" <<std::endl;
}
void	print_double(double d)
{
	bool is_inf = (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity());
	if (d != d)
		std::cout<<"double : nan"<<std::endl;
	else if (is_inf)
	{
		if (d > 0)
			std::cout<<"double : +inf"<<std::endl;
		else
			std::cout<<"double : -inf"<<std::endl;
	}
	else
		std::cout << "double : " << std::fixed << std::setprecision(1)<< d << std::endl;
}