#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contacts.hpp"

class PhoneBook 
{
	private:
		Contacts cts[8];
	public:
	void add_contact(Contacts ct,int count);
};
#endif