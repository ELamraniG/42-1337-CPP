#include "PhoneBook.hpp"

std::string get_line_wraper(std::string message)
{
	std::string s;
	std::cout<<message<<std::endl;
	if (!std::getline(std::cin, s))
			return "";
	if (s.empty())
	{
		std::cout<<"line cannot be empty please enter a valid value:"<<std::endl;
		return get_line_wraper(message);
	}
	return s;
}

bool handle_add(Contacts *cont)
{
	std::string s;

	s = get_line_wraper("enter your first name:");
	if (s.empty())
		return false;
	cont->set_first_name(s);


	s = get_line_wraper("enter your last name:");
	if (s.empty())
		return false;
	cont->set_last_name(s);


	s = get_line_wraper("enter your nickname:");
	if (s.empty())
		return false;
	cont->set_nick_name(s);


	s = get_line_wraper("enter your phone number:");
	if (s.empty())
		return false;
	cont->set_phone_number(s);

	s = get_line_wraper("darkest secret");
	if (s.empty())
		return false;
	cont->set_darkest_secret(s);
	return true;
}

int main(void)
{
	std::string s;
	PhoneBook booke;
	Contacts cont;
	while (1337)
	{
		if (!std::getline(std::cin, s))
			break;
		if (s.compare("ADD") == 0)
		{
			if (handle_add(&cont) == false)
				break;
			booke.add_contact(cont);
		}
		else if (s.compare("SEARCH") == 0)
		{
			booke.print_contacts();
			std::cout<<"enter the index you want to search for"<<std::endl;
			if (booke.search_for() == false)
				return 0;
		}
		else if (s.compare("EXIT") == 0)
			return 0;
	}
	return 0;
}
