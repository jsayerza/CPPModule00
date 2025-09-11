/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:30:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/09/11 18:30:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook
{
	private:
		static const int MAX_CONTACTS = 3;
		Contact _contacts[MAX_CONTACTS];
		int _currentIndex;
		int _totalContacts;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContacts();
		void displayMenu();
		void run();

	private:
		std::string readInput(const std::string &prompt);
		bool isValidInput(const std::string &input);
		void displayContactsTable();
		void displayContactDetails(int index);
		int getValidIndex();
};


#endif
