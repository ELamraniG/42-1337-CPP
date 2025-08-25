#include "PhoneBook.hpp"

void PhoneBook::add_contact(Contacts ct,int count){
		if (count < 8)
			cts[count] = ct;
		else
			cts[count % 8] = ct;
}
