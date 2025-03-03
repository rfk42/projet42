#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

void initialize_contact(Contact &contact)
{
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
	contact.set_first_name(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.last_name(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.nickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.phone_number(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact.darkest_secret(input);
}

void set_contact()
{
    Contact contact;
    initialize_contact(contact);
    // Other code to handle the contact
}

