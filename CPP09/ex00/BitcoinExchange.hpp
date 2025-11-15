#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <unordered_map>

class BitcoinExchange
{
  private:
	std::string input_file_name;
	std::ifstream file_txt;
	std::ifstream file_csv;
	bool validate_files();
	bool parse_map();
	bool parse_input();
	bool validate_dates(std::string s);
	bool validate_format(std::string s,std::string splitter);
	bool excute_calculations(std::string s,std::string splitter);
	bool all_numbers_checker(std::string s);

  public:
	std::unordered_map<std::string, std::string> map_csv;
	BitcoinExchange();
	BitcoinExchange(std::string);
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &cpy);
	void parse_the_bitc();
};
