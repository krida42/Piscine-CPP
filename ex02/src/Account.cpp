#include <iostream>
#include "Account.hpp"


int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(Account::_nbAccounts), _amount(0),
						_nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	std::cout << "nb accouynts: " << Account::_nbAccounts;
	
}

Account::Account(int initial_deposit) {
	Account();
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
				<< ";created" << std::endl;
}

Account::~Account(void) {
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts--;
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
	std::cout << "Display Accounts infos.. ";
}



void	Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		return true;
	}
	return false;
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	//std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
			//<< ";";  
}


void    Account::_displayTimestamp(void) {
	std::cout << "[Timestamp] ";
}

