#ifndef CONTACTS_HPP
# define CONTACTS_HPP
#include <iostream>
//◦ The contact fields are: first name, last name, nickname, phone number, and
//darkest secret. A saved contact can’t have empty fields.

class Contacts{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_string;
	public:
		void set_first_name(std::string s);
		std::string get_first_name();
};

#endif