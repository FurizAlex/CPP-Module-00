/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alechin <alechin@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:02:54 by alechin           #+#    #+#             */
/*   Updated: 2025/09/30 10:29:36 by alechin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

int Account::checkAmount(void) const {
	return _totalAmount;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts " << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused";
		std::cout << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << _amount;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return true;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " accounts " << _accountIndex;
	std::cout << ";total:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t now = std::time(NULL);
	std::tm* local_time = std::localtime(&now);
	char buffer[70];
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buffer;
}