#include "Contacts.hpp"
#include <iostream>
//◦ The contact fields are: first name, last name, nickname, phone number, and
//darkest secret. A saved contact can’t have empty fields.
	
	void Contacts::set_first_name(std::string s)
	{
		first_name = s;
	}
	std::string Contacts::get_first_name()
	{
		return first_name;
	}