#include "PhoneBook.hpp"

void PhoneBook::add_contact(Contacts ct){
	int index;
	if (counter < 8)
		index = counter;
	else
		index = counter % 8;
	ct.set_index(index);
	cts[index] = ct;
	increase_counter();
}

void PhoneBook::increase_counter()
{
	counter++;
}

int PhoneBook::get_counter()
{
	return (counter);
}

void PhoneBook::print_contacts()
{
	std::cout<<"     index|first name| last name|  nickname"<<std::endl;
	for (int i = 0; i < get_counter() && i < 8;i++)
		cts[i].print_contact();
}

bool PhoneBook::search_for()
{
	std::string s;
	if (!std::getline(std::cin, s))
			return false;
	if (s.empty())
	{
		std::cout<<"index can't be empty try again: "<<std::endl;
		return search_for();
	}
	for (int i = 0; i < s.size();i++)
	{
		if (!std::isdigit(s[i]))
		{
			std::cout<<"the index has to be a valid number try again: "<<std::endl;
			return search_for();
		}
	}
	int index = std::stoi(s);
	if (index < 0 || index >= counter || index > 7)
	{
		std::cout<<"this index doesn't exist"<<std::endl;
		return true;
	}
	std::cout<<"first name: "<<cts[index].get_first_name()<<std::endl;
	std::cout<<"last name: "<<cts[index].get_last_name()<<std::endl;
	std::cout<<"nick name: "<<cts[index].get_nick_name()<<std::endl;
	std::cout<<"phone number: "<<cts[index].get_phone_number()<<std::endl;
	std::cout<<"darkest secret: "<<cts[index].get_darkest_secret()<<std::endl;
	return true;
}
PhoneBook::PhoneBook()
{
	counter = 0;
};