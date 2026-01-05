#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <map>

class BitcoinExchange {
private:
  std::string input_file_name;
  std::map<std::string, std::string> map_csv;
  bool open_files(std::ifstream &file_txt, std::ifstream &file_csv);
  bool parse_map();
  bool parse_input();
  bool validate_dates(std::string s);
  bool validate_format(std::string s, std::string splitter);
  bool all_numbers_checker(std::string s);

public:
  BitcoinExchange();
  BitcoinExchange(std::string);
  ~BitcoinExchange();
  BitcoinExchange(BitcoinExchange &cpy);
  BitcoinExchange &operator=(const BitcoinExchange &cpy);
  void parse_the_bitc();
  std::string get_file_name() const;
  std::map<std::string, std::string> get_file_map() const;
};
