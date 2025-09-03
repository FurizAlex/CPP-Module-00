/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:50:58 by furizalex         #+#    #+#             */
/*   Updated: 2025/09/02 16:08:52 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

static void argumentCase(int argumentCounter) {
	if (argumentCounter > 0) {
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

static void	upperTransform(std::string command) { // This literally exist cuz apparently i can't use <algorithm> wtf
	for (size_t Index = 0; Index < command.length(); Index++) {
		if (command[Index] >= 97 && command[Index] <= 122)
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
		if (command.compare("ADD") == 0)
			addCommand(phonebook);
		else if (command.compare("SEARCH") == 0)
			searchCommand(phonebook);
		else if (command.compare("EXIT") == 0)
			exitCommand();
	}
	return (0);
}