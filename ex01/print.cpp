/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:51:12 by furizalex         #+#    #+#             */
/*   Updated: 2025/09/02 14:35:50 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string truncater(std::string String)
{
	std::string newString;

	if (String.length > 10) {
		newString = String.substr(0, 9);
		newString.append(".");
		return newString;
	}
	return String;
}

void	PhoneBook::printChart() {
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|";
	std::cout << '\n' << std::flush;
}

void	PhoneBook::printContactTable() {
	for (int Index = 0; Index < maxContacts; Index++) {
		std::cout << std::setw(10) << std::right << j << "|";
		std::cout << std::setw(10) << std::right << truncater(contacts[Index].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << truncater(contacts[Index].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << truncater(contacts[Index].getNickname()) << "|";
		std::cout << std::endl;
	}
}