#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
	PhoneBook	phonebook;
	Contact 	contact;
	std::string arg;
	while (1)
	{
		if (std::cin.eof())
			break;
		std::cout << "What do you want to do : ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, arg);
	    if (std::cin.eof())
			break;
		if (arg == "EXIT")
			break;
		else if (arg == "ADD")
			phonebook.add_contact();
		else if (arg == "SEARCH")
			phonebook.search_contacts();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}