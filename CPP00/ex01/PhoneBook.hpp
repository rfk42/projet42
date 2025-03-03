#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];	
	int nb_contact;

	public:
	PhoneBook();
	~PhoneBook();
};

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}



#endif