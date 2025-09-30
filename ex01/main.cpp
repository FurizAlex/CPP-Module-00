/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:50:58 by furizalex         #+#    #+#             */
/*   Updated: 2025/09/30 11:17:11 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

static void argumentCase(int argumentCounter) {
	if (argumentCounter > 1) {
		std::cout << "Can't input arguments" << std::endl;
		return;
	}
}

static void addCommand(PhoneBook& phonebook) {
	std::cout << GREEN << "➕ ADD CONTACT" << std::endl;
	phonebook.addContact();
}

static void searchCommand(PhoneBook& phonebook) {
	std::cout << GREEN << "🔎 SEARCH CONTACT" << std::endl;
	phonebook.searchContact();
}

static void exitCommand() {
	std::cout << GREEN << "🚪 EXIT" << RESET << std::endl;
	std::exit(0);
}

static void	upperTransform(std::string& command) { // This literally exist cuz apparently i can't use <algorithm> wtf
	for (size_t Index = 0; Index < command.length(); Index++) {
		if (command[Index] >= 'a' && command[Index] <= 'z')
			command[Index] = (char)toupper(command[Index]);
	}
}

int	main(int argumentCounter, char *argumentVector[]) {
	PhoneBook		phonebook;
	std::string		command;

	(void)argumentVector;
	argumentCase(argumentCounter);
	while (1) {
		phonebook.welcomeMessage();
		if (!std::getline(std::cin, command))
			exitCommand();
		upperTransform(command);
		if (command.compare("ADD") == 0 || command.compare("A") == 0)
			addCommand(phonebook);
		else if (command.compare("SEARCH") == 0 || command.compare("S") == 0)
			searchCommand(phonebook);
		else if (command.compare("EXIT") == 0 || command.compare("E") == 0)
			exitCommand();
	}
	return (0);
}