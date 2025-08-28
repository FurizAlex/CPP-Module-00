/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:33:53 by furizalex         #+#    #+#             */
/*   Updated: 2025/08/28 11:56:21 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void setFirstName(std::string& String);
		void setLastName(std::string& String);
		void setNickname(std::string& String);
		void setPhoneNumber(std::string& String);
		void setDarkestSecret(std::string& String);

		std::string& getFirstName();
		std::string& getLastName();
		std::string& getNickname();
		std::string& getPhoneNumber();
		std::string& getDarkestSecret();
};

#endif