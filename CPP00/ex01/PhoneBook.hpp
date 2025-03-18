#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];	
	int  	nb_contact;
	int		index;

public:
	PhoneBook();
	~PhoneBook();

	void add_contact();
	void search_contacts() const;
	void display_contact_list() const;
	void display_contact_details(int index) const;

};

#endif