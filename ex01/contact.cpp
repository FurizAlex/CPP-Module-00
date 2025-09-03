/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: furizalex <furizalex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:33:58 by furizalex         #+#    #+#             */
/*   Updated: 2025/09/02 17:31:35 by furizalex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(std::string String) { firstName = String; }
void Contact::setLastName(std::string String) { lastName = String; }
void Contact::setNickname(std::string String) { nickname = String; }
void Contact::setPhoneNumber(std::string String) { phoneNumber = String; }
void Contact::setDarkestSecret(std::string String) { darkestSecret = String; }

std::string Contact::getFirstName() { return firstName; }
std::string Contact::getLastName() { return lastName; }
std::string Contact::getNickname() { return nickname; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getDarkestSecret() { return darkestSecret; }