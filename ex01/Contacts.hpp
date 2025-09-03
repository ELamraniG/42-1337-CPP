#ifndef CONTACTS_HPP
# define CONTACTS_HPP
#include <iostream>
class Contacts{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		int idx;
	public:
		void set_first_name(std::string s);
		std::string get_first_name();
		void set_last_name(std::string s);
		std::string get_last_name();
		void set_nick_name(std::string s);
		std::string get_nick_name();
		void set_phone_number(std::string s);
		std::string get_phone_number();
		void set_darkest_secret(std::string s);
		std::string get_darkest_secret();
		void set_index(int i);
		int get_index();
		void print_contact();
		void print_contact_helper(std::string s);
};

#endif



