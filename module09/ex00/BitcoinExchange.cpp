/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:01:17 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:01:40 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  database_ = other.database_;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other)
    database_ = other.database_;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validDate(const std::string& date) {
  if (date.length() != 10)
    return false;

  if (date[4] != '-' || date[7] != '-')
    return false;

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  return true;
}

bool BitcoinExchange::validValue(float value) {
  if (value < 0) {
    std::cout << "Error: not a positive number." << std::endl;
    return false;
  }

  if (value > 1000) {
    std::cout << "Error: too large a number." << std::endl;
    return false;
  }

  return true;
}

float BitcoinExchange::getRate(const std::string& date) {
  std::map<std::string, float>::iterator it = database_.lower_bound(date);

  if (it != database_.end() && it->first == date)
    return it->second;

  if (it == database_.begin())
    return 0;

  --it;
  return it->second;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
  std::ifstream file(filename.c_str());

  if (!file.is_open()) {
    std::cout << "Error: could not open database." << std::endl;
    return;
  }

  std::string line;
  getline(file, line);  // skip header

  while (getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    std::string rate;

    getline(ss, date, ',');
    getline(ss, rate);

    float price = std::atof(rate.c_str());

    database_[date] = price;
  }

  file.close();
}

void BitcoinExchange::processInput(const std::string& filename) {
  std::ifstream file(filename.c_str());

  if (!file.is_open()) {
    std::cout << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  getline(file, line);  // skip header

  while (getline(file, line)) {
    if (line.empty())
      continue;

    std::stringstream ss(line);

    std::string date;
    std::string valueStr;

    if (!getline(ss, date, '|') || !getline(ss, valueStr)) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (date[date.length() - 1] == ' ')
      date.erase(date.length() - 1);

    if (valueStr[0] == ' ')
      valueStr.erase(0, 1);

    if (!validDate(date)) {
      std::cout << "Error: bad input => " << date << std::endl;
      continue;
    }

    float value = std::atof(valueStr.c_str());

    if (!validValue(value))
      continue;

    float rate = getRate(date);

    std::cout << date << " => " << value << " = " << value * rate << std::endl;
  }

  file.close();
}
