#include "Account.hpp"
#include <iostream>
#include <ctime>


int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void){return _nbAccounts;}
int	Account::getTotalAmount(void){return _totalAmount;}
int	Account::getNbDeposits(void){return _totalNbDeposits;}
int	Account::getNbWithdrawals(void){return _totalNbWithdrawals;}

void Account::_displayTimestamp(void)
{
    std::time_t time = std::time(NULL);
    std::tm *tld = std::localtime(&time);

    std::cout << "[" << 1900 + tld->tm_year;
    if (tld->tm_mon < 9)
        std::cout << "0" << tld->tm_mon + 1;
    else
        std::cout << tld->tm_mon + 1;
    if (tld->tm_mday < 9)
        std::cout << "0" << tld->tm_mday + 1;
    else
        std::cout << tld->tm_mday + 1;
    std::cout << "_";
    if (tld->tm_hour < 9)
        std::cout << "0" << tld->tm_hour + 1;
    else
        std::cout << tld->tm_hour + 1;
    if (tld->tm_min < 9)
        std::cout << "0" << tld->tm_min + 1;
    else
        std::cout << tld->tm_min + 1;
    if (tld->tm_sec < 9)
        std::cout << "0" << tld->tm_sec + 1 << "]";
    else
        std::cout << tld->tm_sec + 1 << "]";
}

void Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << "-total:" << getTotalAmount() << "-deposits:" << getNbDeposits() << "-withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_desposit): _amount(initial_desposit), _nbDeposits(0), _nbWithdrawals(0){
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_desposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << "-amount:" << this->_amount << "-created" << std::endl;
}

Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << "-amount:" << this->_amount << "-closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index :" << this->_accountIndex << "-previous amount : " << this->_amount << "-deposit : " << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_totalAmount += deposit;
    std::cout << "-new amount : " << this->_amount << "-number of deposit : " << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
    _displayTimestamp();
    std::cout << "index :" << this->_accountIndex << "-previous amount : " << this->_amount;
    if (this->_amount >= withdrawal)
    {
        this->_amount -= withdrawal;
        std::cout << "-withdrawal : " << withdrawal;
    }
    else
    {
        std::cout << "-withdrawal refused" << std::endl;
        return 0;
    }
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_totalAmount -= withdrawal;
    std::cout << "-new amount : " << this->_amount << "-number of withdrawals : " << this->_nbWithdrawals << std::endl;
    return 1;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::displayStatus(void) const{
    _displayTimestamp();
    std::cout << "index : " << _accountIndex << "-amount : " << _amount << "-deposits : " << _nbDeposits << "-withdrawals : " << _nbWithdrawals << std::endl;
}