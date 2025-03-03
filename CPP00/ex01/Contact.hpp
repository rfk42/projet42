#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
private:
	static Contact contact[8];
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();

};

Contact::Contact()
{
}

Contact::~Contact()
{
}


#endif