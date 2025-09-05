#include "Account.hpp"
#include <iostream>


int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;


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
    std::cout<<"accounts:"<<getNbAccounts();
    std::cout<<";total:"<<getTotalAmount();
    std::cout<<";deposits:"<<getNbDeposits();
    std::cout<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

Account::Account( int initial_deposit)
{
    _amount = initial_deposit;
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout<<"index:"<<_accountIndex<<";";
    std::cout<<"amount:"<<_amount<<";";
    std::cout<<"created"<<std::endl;
    _nbAccounts++;
    _totalAmount += _amount;
}
Account::~Account( void )
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";amount:"<<_amount;
    std::cout<<";closed"<<std::endl;
}

void	Account::makeDeposit( int deposit )
{
    //[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";p_amount:"<<_amount;
    std::cout<<";deposit:"<<deposit;
    std::cout<<";amount:"<<_amount + deposit;
    _nbDeposits++;
    std::cout<<";nb_deposits:"<<_nbDeposits<<std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    if (checkAmount() < withdrawal)
    {
        _displayTimestamp();
        std::cout<<"index:"<<_accountIndex;
        std::cout<<";p_amount:"<<_amount;
        std::cout<<";withdrawal:"<<"refused"<<std::endl;
        return false;
    }
    else
    {
        _displayTimestamp();
        std::cout<<"index:"<<_accountIndex;
        std::cout<<";p_amount:"<<_amount;
        std::cout<<";withdrawal:"<<withdrawal;
        std::cout<<";amount:"<<_amount - withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        std::cout<<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
        return true;
    }
}
int		Account::checkAmount( void ) const
{
    return _amount;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";amount:"<<_amount;
    std::cout<<";deposits:"<<_nbDeposits;
    std::cout<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}


void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(NULL);
    struct tm  *t_info = localtime(&t);
    std::cout<<"[";
    std::cout<<t_info->tm_year + 1900;
    t_info->tm_mon >= 10 ? std::cout<<t_info->tm_mon + 1 : std::cout<<"0"<<t_info->tm_mon + 1;
    t_info->tm_mday >= 10 ? std::cout<<t_info->tm_mday : std::cout<<"0"<<t_info->tm_mday;
    std::cout<<"_";
    t_info->tm_hour >= 10 ? std::cout<<t_info->tm_hour : std::cout<<"0"<<t_info->tm_hour;
    t_info->tm_min >= 10 ? std::cout<<t_info->tm_min : std::cout<<"0"<<t_info->tm_min;
    t_info->tm_sec >= 10 ? std::cout<<t_info->tm_sec : std::cout<<"0"<<t_info->tm_sec;
    std::cout<<"] ";
}

Account::Account( void )
{

}

