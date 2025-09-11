/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:45:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/09/11 18:45:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::run()
{
	std::string command;

	std::cout << "=== 42 PhoneBook del Sayer ===" << std::endl;
	displayMenu();
	while (true)
	{
		std::cout << "\n --> Entra comanda: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nAdeu!" << std::endl;
			break ;
		}
		if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "\nAdeu!" << std::endl;
			break ;
		}
		else if (command.empty())
			continue ;
		else
		{
			std::cout << "Comanda no vàlida! Ús: [ADD] Afegir, [SEARCH] Cercar, [EXIT] Sortir" << std::endl;
			// displayMenu();
		}
	}
}

void PhoneBook::displayMenu()
{
	std::cout << "\nComandes:" << std::endl;
	std::cout << " ADD    - Afegir contacte" << std::endl;
	std::cout << " SEARCH - Cercar contacte" << std::endl;
	std::cout << " EXIT   - Sortir del PhoneBook" << std::endl;
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "\n--- Afegir nou contacte ---" << std::endl;

	input = readInput("Entra el nom: ");
	if (!isValidInput(input))
		return ;
	newContact.setFirstName(input);

	input = readInput("Entra els cognoms: ");
	if (!isValidInput(input))
		return ;
	newContact.setLastName(input);

	input = readInput("Entra el nickname: ");
	if (!isValidInput(input))
		return ;
	newContact.setNickname(input);

	input = readInput("Entra el telèfon: ");
	if (!isValidInput(input))
		return ;
	newContact.setPhoneNumber(input);

	input = readInput("Entra el secret obscur: ");
	if (!isValidInput(input))
		return ;
	newContact.setDarkestSecret(input);

	_contacts[_currentIndex] = newContact;
	_currentIndex = (_currentIndex + 1) % MAX_CONTACTS;
	// std::cout << "_currentIndex: " << _currentIndex << std::endl;

	if (_totalContacts < MAX_CONTACTS)
		_totalContacts++;

	std::cout << "Contacte afegit!" << std:: endl;
}

void PhoneBook::searchContacts()
{
	if (_totalContacts == 0)
	{
		std::cout << "No hi ha contactes al PhoneBook" << std::endl;
		return ;
	}

	std::cout << "\n--- Llista de contactes ---" << std::endl;
	displayContactsTable();

	int index;
	while (true)
	{
		std::cout << "\nEntra l'índex del contacte: ";
		index = getValidIndex();

		if (index < 0 || index > _totalContacts - 1)
			std::cout << "Índex no vàlid!" << std::endl;
		else
		{
			displayContactDetails(index);
			break ;
		}
	}
}


std::string PhoneBook::readInput(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nOK, anem a Menú principal" << std::endl;
			return ("");
		}
		if (!input.empty())
			break ;
		std::cout << "El camp s'ha d'omplir, si et plau" << std::endl;
	}
	return (input);
}

bool PhoneBook::isValidInput(const std::string &input)
{
	return (!input.empty());
}

void PhoneBook::displayContactsTable()
{
	std::cout << "|" << std::setw(11) << "Índex";
	std::cout << "|" << std::setw(10) << "Nom";
	std::cout << "|" << std::setw(10) << "Cognoms";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < _totalContacts; i++)
	{
		_contacts[i].displayContactSummary(i);
	}
}

void PhoneBook::displayContactDetails(int index)
{
	std::cout << "\n--- Detall del contacte ---" << std::endl;
	_contacts[index].displayContactInfo();
}

int PhoneBook::getValidIndex()
{
	std::string input;
	int index;

	if (!std::getline(std::cin, input))
		return (-1);
	
	std::stringstream ss(input);
	if (!(ss >> index) || !ss.eof())
		return (-1);
	
	return (index);
}
