#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout<<"accounts:"<<getNbAccounts;
    std::cout<<";total:"<<getTotalAmount();
    std::cout<<";deposites:"<<getNbDeposits();
    std::cout<<"withdrawals:"<<getNbWithdrawals();
}

Account::Account( int initial_deposit)
{
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";";
    std::cout<<"amount"<<_amount<<";";
    std::cout<<"created:"<<std::endl;
    _accountIndex = _nbAccounts++;
    _nbAccounts++;
    _totalAmount += _amount;
}
Account::~Account( void )
{

}

void	Account::makeDeposit( int deposit )
{
    //[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";";
    std::cout<<";p_amount"<<_amount;
    std::cout<<";deposit:"<<deposit;
    std::cout<<";amount:"<<_amount + deposit;
    _nbDeposits++;
    std::cout<<";nb_deposits:"<<_nbDeposits;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    if (checkAmount() < withdrawal)
    {

    }
}
int		Account::checkAmount( void ) const
{
    return _amount;
}
void	Account::displayStatus( void ) const
{

}


void	Account::_displayTimestamp( void )
{
    time_t timestamp;
    time(&timestamp);
    std::cout<<"["<<ctime(&timestamp)<<"] ";
}

Account::Account( void )
{

}

