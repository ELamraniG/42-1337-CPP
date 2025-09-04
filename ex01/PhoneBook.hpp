#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contacts.hpp"

class PhoneBook 
{
	private:
		Contacts cts[8];
		int counter;
		void increase_counter();
		int get_counter();
	public:
		PhoneBook();
		void print_contacts();
		void add_contact(Contacts ct);
		bool search_for();

};

#endif