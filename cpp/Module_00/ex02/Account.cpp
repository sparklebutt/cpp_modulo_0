/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:44 by araveala          #+#    #+#             */
/*   Updated: 2024/11/28 11:19:49 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/**
 * Since the Account class will be always a seperate instance in a vector
 * we should set the variables to 0 to start with on each instance.
 * This global method does not decrease the saftey of the private memebrs according to my research.
 */
int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * Constructor sets initial values
 * increasing nb accounts and index as linked values 
 * summing totalamount
 */
Account::Account( int deposit ) : _accountIndex(Account::_nbAccounts), _amount(deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();	
	std::cout<<"index:"<<_accountIndex<<";"<<_amount<<":created"<<std::endl;
	_totalAmount += deposit;
	_nbAccounts += 1;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
	_accountIndex--;
}

int	Account::getNbAccounts( void ){return Account::_nbAccounts;}
int	Account::getTotalAmount( void ){return Account::_totalAmount;}
int	Account::getNbDeposits( void ){return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals( void ){return Account::_totalNbWithdrawals;}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(nullptr);
	std::tm* local = localtime(&now);
	std::cout<<std::put_time(local, "[%Y%m%d_%H%M%S]");
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";deposits:"<<this->_nbDeposits;
	std::cout<<";withdrawls:"<<this->_nbWithdrawals<<std::endl;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout<<"accounts:"<<Account::getNbAccounts();
	std::cout<<";total:"<<Account::getTotalAmount();
	std::cout<<";deposits:"<<Account::getNbDeposits();
	std::cout<<";withdrawls:"<<Account::getNbWithdrawals()<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	checkAmount();
	std::cout<<";deposit:"<<deposit;
	this->_amount += deposit;
	++this->_nbDeposits;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	if (checkAmount() < withdrawal)
	{
		std::cout<<";withdrawal:refused"<<std::endl;
		return false;
	}
	std::cout<<";withdrawal:"<<withdrawal;
	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	return true;
}

/**
 * NOTE: evaluator please tell me how i could have utalized this fucntion better, i would consider
 * this function obsolete under the given information. Function value could ofcourse be linked to 
 * potential future usage not based on given information. 
 */
int		Account::checkAmount( void ) const
{
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";p_amount:"<<this->_amount;
	return this->_amount;
}