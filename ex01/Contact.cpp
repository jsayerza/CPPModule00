/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:30:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/09/08 20:30:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string &firstName)
{
	this->_firstName = firstName;
}
void Contact::setLastName(const std::string &lastName)
{
	this->_lastName = lastName;
}
void Contact::setNickname(const std::string &nickname)
{
    this->_nickname = nickname;
}
void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}
std::string Contact::getLastName() const
{
	return (this->_lastName);
}
std::string Contact::getNickname() const
{
	return (this->_nickname);
}
std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}
std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

bool Contact::isEmpty() const
{
	return (_firstName.empty() && _lastName.empty() && _nickname.empty()
		&& _phoneNumber.empty() && _darkestSecret.empty());
}
void Contact::displayContactInfo() const
{
	std::cout << "Nom: " << _firstName << std::endl;
	std::cout << "Cognoms: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Num. telf.: " << _phoneNumber << std::endl;
	std::cout << "Secret obscur: " << _darkestSecret << std::endl;
}
void Contact::displayContactSummary(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << truncateString(_firstName);
	std::cout << "|" << std::setw(10) << truncateString(_lastName);
	std::cout << "|" << std::setw(10) << truncateString(_nickname);
	std::cout << "|" << std::endl;
}
std::string Contact::truncateString(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
