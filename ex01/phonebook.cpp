/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:34:10 by furizalex         #+#    #+#             */
/*   Updated: 2025/09/03 14:18:35 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	this->i = 0;
	this->maxContacts = 0;
	this->numberOfContacts = 0;
}

void PhoneBook::determineRange() {
	if (i >= 0 && i < maxContacts)
		printContacts(i);
	else
		handleErrors(4);
}

void	PhoneBook::handleErrors(int type) {
	switch (type) {
		case 0:
			std::cout << RED << "End of file detected, Exiting Program" << RESET << std::endl;
			std::cin.clear();
			std::exit(0);
			break;
		case 1:
			std::cout << RED << "Empty Value" << RESET << std::endl;
			break;
		case 2:
			std::cout << RED << "Invalid Response" << RESET << std::endl;
			break;
		case 3:
			std::cout << RED << "Invalid Index" << RESET << std::endl;
			break;
		case 4:
			std::cout << RED << "Index out of range" << RESET << std::endl;
			break;
		case 5:
			std::cout << RED << "There is no contact in the phonebook" << RESET << std::endl;
			std::cout << CYAN << "Please add a contact to the phonebook!" << RESET << std::endl;
			break;
		default:
			return;
	}
}

void	PhoneBook::welcomeMessage() {
	std::cout << GREEN << '\n';
	std::cout << WHITE << "Welcome to our crappy phonebook!!" << std::endl;
	std::cout << WHITE << "In this phonebook, it only accepts" << BLUE << " ➕ ADD 🔍 SEARCH & 🚪 EXIT\n" << std::flush;
	std::cout << WHITE << "Please enter a command" << RESET << '\n' << std::flush;
	std::cout << BLUE << "--- Command ---" << RESET << '\n' << std::flush;
}

void	PhoneBook::addDisplayContents(int Index) {
	std::cout << YELLOW << "First Name : " << BLUE << contacts[Index].getFirstName() << std::endl;
	std::cout << YELLOW << "Last Name : " << BLUE << contacts[Index].getLastName() << std::endl;
	std::cout << YELLOW << "Nickname : " << BLUE << contacts[Index].getNickname() << std::endl;
	std::cout << YELLOW << "Phone Number : " << BLUE << contacts[Index].getPhoneNumber() << std::endl;
	std::cout << YELLOW << "Darkest Secret : " << BLUE << contacts[Index].getDarkestSecret() << std::endl;
}

void	PhoneBook::getContactInfo(std::string Info[5]) {
	std::string Prompts[] = {
		"First Name : ",
		"Last Name : ",
		"Nickname : ",
		"Phone Number : ",
		"Darkest Secret : ",
	};
	for (int Index = 0; Index < 5; Index++) {
		std::cout << BLUE << Prompts[Index] << RESET;
		if (!std::getline(std::cin, Info[Index]))
			handleErrors(0);
		else if (invalidContacts(Info[Index])) {
			handleErrors(2);
			Index--;
		}
	}
}

void	PhoneBook::promptContact() {
	std::cout << GREEN << "Please enter the index you'd like to display" << RESET;
	if (!(std::cin >> i)) {
		if (std::cin.eof())
			handleErrors(0);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		handleErrors(3);
		return;
	}
	determineRange();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool	PhoneBook::invalidContacts(std::string Information) {
	if (Information.empty())
		return true;
	for (size_t Index = 0; Information.length() > Index; Index++) {
		if (Information[Index] != ' ' && Information[Index] != '\t')
			return false;
	}
	return true;
}

void	PhoneBook::addContact() {
	Contact newContact;
	std::string Info[5];
	
	getContactInfo(Info);
	newContact = addInfo(Info);
	i = numberOfContacts % 8;
	this->contacts[i] = newContact;
	numberOfContacts++;
	if (maxContacts < 8)
		maxContacts++;
}

Contact	PhoneBook::addInfo(std::string Info[5]) {
	Contact newContact;

	newContact.setFirstName(Info[0]);
	newContact.setLastName(Info[1]);
	newContact.setNickname(Info[2]);
	newContact.setPhoneNumber(Info[3]);
	newContact.setDarkestSecret(Info[4]);
	return newContact;
}

void	PhoneBook::searchContact()
{
	if (numberOfContacts == 0) {
		handleErrors(5);
		return;
	}
	printChart();
	printContactTable();
	printContacts(i);
}