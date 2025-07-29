/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:45:31 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 10:32:11 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {}
Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int		Account::getNbAccounts(void)		{ return (_nbAccounts); }
int		Account::getTotalAmount(void)		{ return (_totalAmount); }
int		Account::getNbDeposits(void)		{ return (_totalNbDeposits); }
int		Account::getNbWithdrawals(void)		{ return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int		oldAmount;

	oldAmount = _amount;
	_amount += deposit;
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << oldAmount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int makeWithdrawal)
{
	int		oldAmount;

	oldAmount = _amount;
	_amount -= makeWithdrawal;
	_nbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << oldAmount << ";";
	if (_amount < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		_amount = oldAmount;
		_nbWithdrawals--;
		return (false);
	}
	std::cout << "withdrawal:" << makeWithdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	_totalAmount -= makeWithdrawal;
	_totalNbWithdrawals++;

	return (true);
}

int		Account::checkAmount(void) const	{ return (_amount); }

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t			timestamp = time(NULL);
	struct std::tm		*timeInfo = std::localtime(&timestamp);
	char				buffer[80];

	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeInfo);

	std::cout << buffer;
}
