/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:33:21 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 15:42:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
    : _accountIndex(_nbAccounts++),
      _amount(0),
      _nbDeposits(0),
      _nbWithdrawals(0) {}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  _totalAmount += _amount;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created" << std::endl;
}

Account::~Account(void) {
  _nbAccounts--;
  _totalAmount -= _amount;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
  return _nbAccounts;
}

int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts
            << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals
            << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount
            << ";deposit:" << deposit;

  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;

  std::cout << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits
            << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount
            << ";withdrawal:";

  if (withdrawal > _amount) {
    std::cout << "refused" << std::endl;
    return false;
  }

  _amount -= withdrawal;
  _nbWithdrawals++;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;

  std::cout << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals
            << std::endl;

  return true;
}

int Account::checkAmount(void) const {
  return _amount;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t t = std::time(NULL);
  std::tm* now = std::localtime(&t);

  std::cout << '['
            << (now->tm_year + 1900)
            << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
            << std::setw(2) << std::setfill('0') << now->tm_mday
            << '_'
            << std::setw(2) << std::setfill('0') << now->tm_hour
            << std::setw(2) << std::setfill('0') << now->tm_min
            << std::setw(2) << std::setfill('0') << now->tm_sec
            << "] ";
}
