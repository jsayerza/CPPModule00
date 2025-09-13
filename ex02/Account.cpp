/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/09/13 11:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount + initial_deposit;

	Account::_displayTimestamp();
	std::cout	<< "index"		<< this->_accountIndex
				<< ";amount"	<< this->_amount
				<< ";created"	<< std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;

	Account::_displayTimestamp();
	std::cout	<< "index"		<< this->_accountIndex
				<< ";amount"	<< this->_amount
				<< ";closed"	<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts"		<< _nbAccounts
				<< ";total"			<< _totalAmount
				<< ";deposits"		<< _totalNbDeposits
				<< ";withdrawals"	<< _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout	<< "index"			<< this->_accountIndex
				<< ";p_amount"		<< p_amount
				<< ";deposit"		<< deposit
				<< ";amount"		<< this->_amount
				<< ";nb_deposits"	<< this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount = this->_amount;
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		Account::_displayTimestamp();
		std::cout	<< "index"			<< this->_accountIndex
					<< ";p_amount"		<< p_amount
					<< ";withdrawal"	<< withdrawal
					<< ";amount"		<< this->_amount
					<< ";nb_withdrawals"<< this->_nbWithdrawals
					<< std::endl;
	}
	else
	{
		Account::_displayTimestamp();
		std::cout	<< "index"			<< this->_accountIndex
					<< ";p_amount"		<< p_amount
					<< ";withdrawal:refused"
					<< std::endl;
	}
	return (true);
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm* timeinfo = std::localtime(&now);

	std::cout	<< "[" << (timeinfo->tm_year + 1900)
				<< std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
				<< std::setfill('0') << std::setw(2) << timeinfo->tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(0) << timeinfo->tm_hour
				<< std::setfill('0') << std::setw(0) << timeinfo->tm_min
				<< std::setfill('0') << std::setw(0) << timeinfo->tm_sec
				<< "]";
}