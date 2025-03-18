#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string &value)
{
	this->first_name = value;
}

std::string Contact::getFirstName() const
{
	return this->first_name;
}

void Contact::setLastName(const std::string &value)
{
	this->last_name = value;
}

std::string Contact::getLastName() const
{
	return this->last_name;
}

void Contact::setNickname(const std::string &value)
{
	this->nickname = value;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}

void Contact::setPhoneNumber(const std::string &value)
{
	this->phone_number = value;
}

std::string Contact::getPhoneNumber() const
{
	return this->phone_number;
}

void Contact::setDarkestSecret(const std::string &value)
{
	this->darkest_secret = value;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkest_secret;
}

bool is_alpha(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++) 
	{
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}

bool is_numbers(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++) 
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void Contact::init_first_name()
{
	std::string input;

	while (1)
	{
		std::cout << "Enter first name: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input.empty())
			std::cout << "Error: Field cannot be empty!" << std::endl;
		else if (is_alpha(input))
		{
			this->setFirstName(input);
			break;
		}
		else
			std::cout << "Error: Only letters are allowed!" << std::endl;
	}
}

void Contact::init_last_name()
{
	std::string input;

	while (1)
	{
		std::cout << "Enter last name: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input.empty())
			std::cout << "Error: Field cannot be empty!" << std::endl;
		else if (is_alpha(input))
		{
			this->setLastName(input);
			break;
		}
		else
			std::cout << "Error: Only letters are allowed!" << std::endl;
	}
}

void Contact::init_nickname()
{
	std::string input;

	while (1)
	{
		std::cout << "Enter Nickname: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;		
		if (input.empty())
			std::cout << "Error: Field cannot be empty!" << std::endl;
		else
		{
			this->setNickname(input);
			break;
		}
	}
}

void Contact::init_phone_number()
{
	std::string input;

	while (1)
	{
		std::cout << "Enter Phone Number: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;		
		if (input.empty())
			std::cout << "Error: Field cannot be empty!" << std::endl;
		else if (is_numbers(input))
		{
			this->setPhoneNumber(input);
			break;
		}
		else
			std::cout << "Error: Only numbers are allowed!" << std::endl;
	}
}

void Contact::init_darkest_secret()
{
	std::string input;

	while (1)
	{
		std::cout << "Enter your darkest secret: " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;		
		if (input.empty())
			std::cout << "Error: Field cannot be empty!" << std::endl;
		else
		{
			this->setDarkestSecret(input);
			break;
		}
	}
}

void	Contact::set_contact()
{
	this->init_first_name();
	if (std::cin.eof()) 
		return;
	this->init_last_name();
	if (std::cin.eof()) 
		return;
	this->init_nickname();
	if (std::cin.eof()) 
		return;
	this->init_phone_number();
	if (std::cin.eof()) 
		return;
	this->init_darkest_secret();
	if (std::cin.eof()) 
		return;
}
