#include "Contacts.hpp"
#include <iostream>

void Contacts::set_first_name(std::string s)
{
	first_name = s;
}
std::string Contacts::get_first_name()
{
	return first_name;
}

void Contacts::set_last_name(std::string s)
{
	last_name = s;
}
std::string Contacts::get_last_name()
{
	return last_name;
}

void Contacts::set_nick_name(std::string s)
{
	nick_name = s;
}
std::string Contacts::get_nick_name()
{
	return nick_name;
}

void Contacts::set_phone_number(std::string s)
{
	phone_number = s;
}
std::string Contacts::get_phone_number()
{
	return phone_number;
}

void Contacts::set_darkest_secret(std::string s)
{
	darkest_secret = s;
}
std::string Contacts::get_darkest_secret()
{
	return darkest_secret;
}

void Contacts::set_index(int i)
{
	idx = i;
}
int Contacts::get_index()
{
	return idx;
}

void Contacts::print_contact_helper(std::string s)
{
	if (s.size() < 10)
	{
		for(int i = 0; i < 10 - (int)s.size();i++)
			std::cout<<" ";
	}
	else if (s.size() > 10)
	{
		s = s.substr(0,9);
		s.append(".");
	}
	std::cout<<s;
}

void Contacts::print_contact(){
	std::cout<<"         ";
	std::cout<<idx;
	std::cout<<"|";
	print_contact_helper(get_first_name());
	std::cout<<"|";
	print_contact_helper(get_last_name());
	std::cout<<"|";
	print_contact_helper(get_nick_name());
	std::cout<<std::endl;
}