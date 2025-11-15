#include "BitcoinExchange.hpp"

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
	//later
	(void)cpy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	//later
	(void)cpy;
	return *this;
}

bool BitcoinExchange::validate_files()
{
	file_txt.open("input.txt");
	if (file_txt.is_open() == false)
	{
		std::cout<<"error in the input file"<<std::endl;
		return false;
	}
	file_csv.open("data.csv");
	if(file_csv.is_open() == false)
	{
		file_csv.open("input.csv");
			if(file_csv.is_open() == false)
			{
				std::cout<<"error in the csv file"<<std::endl;
				return false;
			}
		
	}
	return true;
}

bool BitcoinExchange::all_numbers_checker(std::string s)
{
	for (int i = 0; i < s.length();i++)
		if(!std::isdigit(s[i]))
			return false;
	return true;
}
bool BitcoinExchange::validate_format(std::string s,std::string splitter)
{
	int after_splitter_pos;
	// check size and " | "
	if (splitter == " | ")
	{
		if (s.length() < 14)
			return false;
		std::string f_tmp = s.substr(10,3);
		if (f_tmp != splitter)
			return  false;
		after_splitter_pos = 10 + 3;
	}
	// check size and ","
	if (splitter == ",")
	{
		if (s.length() < 12)
			return false;
		if (s[10] != ',')
			return false;
		after_splitter_pos = 10 + 1;
	}
	if (s[4] != '-' || s[7] != '-')
		return false;
	std::string value_checker = s.substr(after_splitter_pos,s.length() - after_splitter_pos);
	int is_doted = 0;
	for (int i = 0;i < value_checker.length(); i++)
	{
		if (!std::isdigit(value_checker[i]) && value_checker[i] != '.')
			return false;
		else if (value_checker[i] == '.')
		{
			if (value_checker.length() == 1)
				return false;
			if (is_doted == 1)
				return false;
			is_doted = 1;
		}
	}
	std::string tmp_year = s.substr(0,4);
	std::string tmp_month = s.substr(5,2);
	std::string tmp_day = s.substr(8,2);
	if (all_numbers_checker(tmp_year) == false || all_numbers_checker(tmp_month)  == false|| all_numbers_checker(tmp_day)  == false)
		return false;
	return true;
}

bool  BitcoinExchange::parse_map()
{
	std::string s;
	std::getline(file_csv,s);
	if (s != "date,exchange_rate")
	{
		std::cout<<"error in csv file"<<std::endl;
		return(false);
	}
	while (std::getline(file_csv,s))
	{
		if (validate_format(s,",") == false)
		{
			std::cout<<"error in the csv fromat"<<std::endl;
			return false;
		}
		map_csv[s.substr(0,10)] = s.substr(11,s.length() - 11);
	}
	return true;
}

bool  BitcoinExchange::parse_input()
{
	std::string s;
	std::getline(file_txt,s);
	if (s != "date | value")
	{
		std::cout<<"error in txt file"<<std::endl;
		return(false);
	}
	while (std::getline(file_csv,s))
	{
		if (validate_format(s,",") == false || validate_dates(s, " | ") == false)
		{
			std::cout<<"Error: bad input => "<<s<<std::endl;
			continue;
		}
		
	}
	return true;
}
bool BitcoinExchange::excute_calculations(std::string s,std::string splitter)
{

}
void BitcoinExchange::parse_the_bitc()
{
	validate_files();
	if (parse_map() == false)
		return ;

}