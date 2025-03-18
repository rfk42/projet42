/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:04 by rhamini           #+#    #+#             */
/*   Updated: 2025/03/06 16:52:24 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() : nb_contact(0), index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact()
{
	if (nb_contact < 8)
		nb_contact++;
	
	contacts[index].set_contact();
	if (std::cin.eof())
		return;
	std::cout << "Contact added at index " << index << std::endl;

	index = (index + 1) % 8;
}

std::string format_column(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::display_contact_list() const
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	std::cout	<< "---------------------------------------------" << std::endl;

	int i = 0;
	while (i < nb_contact)
	{
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << format_column(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << format_column(contacts[i].getLastName()) << "|"
					<< std::setw(10) << format_column(contacts[i].getNickname()) << std::endl;
		i++;
	}
}

void PhoneBook::display_contact_details(int index) const
{
	if (index < 0 || index >= nb_contact)
	{
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
		return;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::search_contacts() const
{
	int index;
	std::string input;

	if (nb_contact == 0)
	{
		std::cout << "No contacts saved yet." << std::endl;
		return;
	}
	
	display_contact_list();

	std::cout << "Enter the index of the contact to display: " << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	std::istringstream conversion(input);
	if (!(conversion >> index) || index < 0 || index >= nb_contact)
	{
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
		return;
	}
	display_contact_details(index);
}
