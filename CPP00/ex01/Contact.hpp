#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

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


	void set_contact();
	void init_first_name();
	void setFirstName(const std::string &value);
	std::string getFirstName() const;
	
	void init_last_name();
	void setLastName(const std::string &value);
	std::string getLastName() const;
	
	void init_nickname();
	void setNickname(const std::string &value);
	std::string getNickname() const;

	void init_phone_number();
	void setPhoneNumber(const std::string &value);
	std::string getPhoneNumber() const;

	void init_darkest_secret();
	void setDarkestSecret(const std::string &value);
	std::string getDarkestSecret() const;
};

#endif