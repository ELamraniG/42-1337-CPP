#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contacts.hpp"

class PhoneBook 
{
	private:
		Contacts cts[8];
		int counter;
	public:
	PhoneBook()
	{
		counter = 0;
	};
	void add_contact(Contacts ct);
	void increase_counter();
	int get_counter();
	void print_contacts();
	bool search_for();
};

#endif