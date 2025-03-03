#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
	PhoneBook phonebook;
	std::string arg;
	while (1)
	{	
		std::cout << "What do you want to do : ADD, SEARCH or EXIT" << std::endl;
		std::cin >> arg;
		if (arg == "EXIT")
			break;
		else if (arg == "ADD")
		{
			;
		}
		else if (arg == "SEARCH")
			
	}
	return 0;
}