/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:34:04 by furizalex         #+#    #+#             */
/*   Updated: 2025/09/02 17:30:54 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

class PhoneBook {
	private:
		Contact contacts[8];
		int		numberOfContacts;
		int		maxContacts;
		int		i;
	public:
		PhoneBook();
		void	handleErrors(int type);
		void	welcomeMessage();
		void	determineRange();
		void	addDisplayContents(int Index);
		void	getContactInfo(std::string Info[5]);
		void	promptContact();
		void	addContact();
		void	searchContact();
		void	printChart();
		void	printContactTable();
		void	printContacts(int Index);
		bool	invalidContacts(std::string Information);
		Contact	addInfo(std::string Info[5]);
};

#endif