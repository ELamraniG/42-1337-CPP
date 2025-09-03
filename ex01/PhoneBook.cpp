#include "PhoneBook.hpp"

void PhoneBook::add_contact(Contacts ct){
	int index;
	if (counter < 8)
		index = counter;
	else
		index = counter % 8;
	cts[counter] = ct;
	cts->set_index(index);
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
	std::cout<<"index     |first name|last name |nickname  "<<std::endl;
	for (int i = 0; i < get_counter();i++)
		cts[i].print_contact();
}