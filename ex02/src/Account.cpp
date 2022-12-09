#include <iostream>
#include "Account.hpp"


int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

//Account::Account(void) {}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit),
									_nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";amount:"
				<< this->_amount << ";created" << std::endl;

}

Account::~Account(void) {
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";amount:"
				<< this->_amount << ";closed" << std::endl;
}

int     Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int     Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int     Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int     Account::getNbWithdrawals(void) {
	return Account::_totalNbDeposits;
}

void   Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
				<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl; 
}



void	Account::makeDeposit(int deposit) {
	int	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	 std::cout 	<< "index:" << this->_accountIndex << ";p_amount:" << p_amount
	 			<<";deposit:" << deposit << ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	
	int p_amount = this->_amount;
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout 	<< "index:" << this->_accountIndex << ";p_amount:"
					<< p_amount << ";withdrawal:" << withdrawal << ";amount:"
					<< this->_amount << ";nb_withdrawals:" 
					<< this->_nbWithdrawals << std::endl;

		return true;
	}
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";p_amount:" 
				<< p_amount << ";withdrawal:refused" << std::endl;
	return false;
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<<  "index:" << this->_accountIndex << ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits << ";withdrawals:" 
				<< this->_nbWithdrawals << std::endl;

}


void    Account::_displayTimestamp(void) {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout 	<< "[" << timeinfo->tm_year + 1900
				<< timeinfo->tm_mon + 1
				<< timeinfo->tm_mday << "_"
				<< timeinfo->tm_hour
				<< timeinfo->tm_min
				<< timeinfo->tm_sec << "] ";
}

