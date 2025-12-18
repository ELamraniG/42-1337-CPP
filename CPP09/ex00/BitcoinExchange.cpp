#include "BitcoinExchange.hpp"
#include <fstream>
#include <ostream>

BitcoinExchange::BitcoinExchange() : input_file_name("input.txt")
{
}
BitcoinExchange::BitcoinExchange(std::string s)
{
	input_file_name = s;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &cpy)
{
	map_csv = cpy.get_file_map();
	input_file_name = cpy.get_file_name();
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	map_csv = cpy.get_file_map();
	input_file_name = cpy.get_file_name();
	return *this;
}

bool BitcoinExchange::open_files(std::ifstream &file_txt,std::ifstream &file_csv)
{
	file_txt.open(input_file_name);
	if (file_txt.is_open() == false)
	{
		std::cout << "error in the input file" << std::endl;
		return (false);
	}
	file_csv.open("data.csv");
	if (file_csv.is_open() == false)
	{
			std::cout << "error in the data.csv file" << std::endl;
			return (false);
	}
	return (true);
}

bool BitcoinExchange::all_numbers_checker(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		if (!std::isdigit(s[i]))
			return (false);
	return (true);
}
bool BitcoinExchange::validate_format(std::string s, std::string splitter)
{
	int	after_splitter_pos;
	int	is_doted;

	// check size and " | "
	if (splitter == " | ")
	{
		if (s.length() < 14)
		{
			return (false);
		}
		std::string f_tmp = s.substr(10, 3);
		if (f_tmp != splitter)
			return (false);
		after_splitter_pos = 10 + 3;
	}
	// check size and ","
	if (splitter == ",")
	{
		if (s.length() < 12)
			return (false);
		if (s[10] != ',')
			return (false);
		after_splitter_pos = 10 + 1;
	}
	if (s[4] != '-' || s[7] != '-')
		return (false);
	std::string value_checker = s.substr(after_splitter_pos, s.length()
			- after_splitter_pos);
	is_doted = 0;
	unsigned int i = 0;
	if (value_checker[0] == '-')
		i++;
	unsigned int size_to_check = i;
	while (i < value_checker.length())
	{
		if (!std::isdigit(value_checker[i]) && value_checker[i] != '.')
			return (false);
		else if (value_checker[i] == '.')
		{
			if (value_checker.length() == size_to_check + 1)
				return (false);
			if (is_doted == 1)
				return (false);
			is_doted = 1;
		}
		i++;
	}
	std::string tmp_year = s.substr(0, 4);
	std::string tmp_month = s.substr(5, 2);
	std::string tmp_day = s.substr(8, 2);
	if (all_numbers_checker(tmp_year) == false
		|| all_numbers_checker(tmp_month) == false
		|| all_numbers_checker(tmp_day) == false)
		return (false);
	return (true);
}

bool BitcoinExchange::parse_map()
{
	std::ifstream file_txt;
	std::ifstream file_csv;
	if (!open_files(file_txt, file_csv))
		return false;
	std::string s;
	std::getline(file_csv, s);
	if (s != "date,exchange_rate")
	{
		std::cout << "error in csv file" << std::endl;
		return (false);
	}
	int i = 0;
	while (std::getline(file_csv, s))
	{
		if (validate_format(s, ",") == false)
		{
			std::cout << "error in the csv fromat" << std::endl;
			return (false);
		}
		map_csv[s.substr(0, 10)] = s.substr(11, s.length() - 11);
		i++;
	}
	if (i == 0)
	{
		std::cout<<"file has no values"<<std::endl;
		return false;
	}
	file_csv.close();
	file_txt.close();
	return (true);
}

bool BitcoinExchange::validate_dates(std::string s)
{
	int	arr[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::string tmp_year = s.substr(0, 4);
	std::string tmp_month = s.substr(5, 2);
	std::string tmp_day = s.substr(8, 2);
	int year, month, day;
	year = std::atoi(tmp_year.c_str());
	month = std::atoi(tmp_month.c_str());
	day = std::atoi(tmp_day.c_str());
	if (year % 4 == 0)
	{
		if ((year % 100 == 0 && year % 400 != 0))
			(void)s;
		else
			arr[2] = 29;
	}
	if (year < 2009 || year > 3000 || month < 1 || month > 12)
		return (false);
	if (day < 1 || day > arr[month])
		return (false);
	return (true);
}

bool BitcoinExchange::parse_input()
{
	std::ifstream file_txt;
	std::ifstream file_csv;
	if (!open_files(file_txt, file_csv))
		return false;
	std::string s;
	std::getline(file_txt, s);
	if (s != "date | value")
	{
		std::cout << "error in txt file" << std::endl;
		return (false);
	}
	
	while (std::getline(file_txt, s))
	{
		if (validate_format(s, " | ") == false || validate_dates(s.substr(0, 10)) == false)
		{
			std::cout << "Error: bad input => " << s << std::endl;
		}
		else
		{
			
		std::string date = s.substr(0, 10);
		std::string value = s.substr(13, s.length() - 13);
			if (map_csv.find(date) != map_csv.end())
			{
				double new_val =  std::atof(map_csv[date].c_str());
				double old_val =  std::atof(value.c_str());
				if (old_val > 1000.0)
					std::cout<<"Error: too large a number."<<std::endl;
				else if (new_val < 0.0 || old_val < 0.0)
					std::cout<<"Error: not a positive number."<<std::endl;
				else
				{
					
				float res = new_val * old_val;
				std::cout << date << " => " << s.substr(13, s.length() - 13) << " = " << res << std::endl;		
				}
			}
			else
			{
				file_csv.clear(); 
				file_csv.seekg(0);
				std::string tmp;
				std::string new_str;
				std::string new_value;
				getline(file_csv,new_str);
				getline(file_csv,new_str);
				tmp = new_str;
				while (getline(file_csv,new_str))
				{
					std::string date2 =new_str.substr(0,10);
					if (date2 > date)
						break;
					tmp = new_str;
				}
				new_value = tmp.substr(11, s.length() - 1);
				double new_val =  std::atof(new_value.c_str());
				double old_val =  std::atof(value.c_str());
				if (old_val > 1000.0)
					std::cout<<"Error: too large a number."<<std::endl;
				else if (new_val < 0.0 || old_val < 0.0)
					std::cout<<"Error: not a positive number."<<std::endl;
				else
				{
					
				float res = new_val * old_val;
				std::cout << date << " => " << s.substr(13, s.length() - 13) << " = " << res << std::endl;	
				}
				
			}
		}
	}
	file_csv.close();
	file_txt.close();
	return (true);
}


std::string BitcoinExchange::get_file_name() const
{
	return input_file_name;
}
	std::unordered_map<std::string, std::string> BitcoinExchange::get_file_map() const
	{
		return map_csv;
	}


	void BitcoinExchange::parse_the_bitc()
{
	if (parse_map() == false)
		return ;

	if (parse_input() == false)
		return ;
}
