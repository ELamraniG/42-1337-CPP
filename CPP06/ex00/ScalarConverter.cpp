#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>

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

void ScalarConverter::convert(std::string s)
{
	char c;
	int n;
	float f;
	double d;
	if (check_char(s) == true)
	{
		c = static_cast<cd >()
	}
	if (check_int(s))
	{
		c = static_cast<char>(s[0]);
		n = static_cast<int>(s[0]);
		f = static_cast<float>(s[0]);
		d = static_cast<double>(s[0]);
	}

}
