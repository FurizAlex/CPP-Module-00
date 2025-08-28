/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:34:10 by furizalex         #+#    #+#             */
/*   Updated: 2025/08/28 16:57:19 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	this->i = 0;
	this->contacts = 0;
	this->numberOfContacts = 0;
}

void	PhoneBook::welcomeMessage() {
	std::cout << GREEN << '\n' << '\n';
	std::cout << WHITE << "Welcome to our crappy phonebook!!" << std::endl;
	std::cout << WHITE << "In this phonebook, it only accepts" << BLUE << "➕ADD 🔍SEARCH & 🚪EXIT\n" << std::flush;
	std::cout << WHITE << "Please enter a command" << RESET << '\n' << std::flush;
	std::cout << BLUE << " < Command  >" << RESET << '\n' << std::flush;
}

void	PhoneBook::addDisplayContents(int Index) {
	std::cout << YELLOW << "First Name :" << BLUE << contacts[Index].getFirstName << std::endl;
	std::cout << YELLOW << "Last Name :" << BLUE << contacts[Index].getLastName << std::endl;
	std::cout << YELLOW << "Nickname :" << BLUE << contacts[Index].getNickname << std::endl;
	std::cout << YELLOW << "Phone Number :" << BLUE << contacts[Index].getPhoneNumber << std::endl;
	std::cout << YELLOW << "Darkest Secret :" << BLUE << contacts[Index].getDarkestSecret << std::endl;
}

bool	PhoneBook::invalidContacts(std::string& Information)
{
	if (Information.empty())
		return true;
	for (int i = 0; Information.length() > i; i++;) {
		if (Information[i] != ' ' && Information[i] != '\t')
			return false;
	}
	return true;
}

void	PhoneBook::addContact() {
	Contact maxContacts;
	std::string Info[4];
	
	
}

Contact	PhoneBook::addInfo(std::string& Info[4]) {
	Contact newContact;

	newContact.setFirstName(Info[0]);
	newContact.setLastName(Info[1]);
	newContact.setNickname(Info[2]);
	newContact.setPhoneNumber(Info[3]);
	newContact.setFirstName(Info[4]);
	return newContact;
}

void	search() {
	return;
}

void	exit() {
	return;
}

void	Phonebook() {
	return;
}