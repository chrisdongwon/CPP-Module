/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:01:17 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:06:48 by cwon             ###   ########.fr       */
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

std::string BitcoinExchange::trim(const std::string& str) {
  size_t start = str.find_first_not_of(" \t");
  size_t end = str.find_last_not_of(" \t");

  if (start == std::string::npos)
    return "";

  return str.substr(start, end - start + 1);
}

bool BitcoinExchange::isLeapYear(int year) {
  if (year % 400 == 0)
    return true;
  if (year % 100 == 0)
    return false;
  if (year % 4 == 0)
    return true;
  return false;
}

int BitcoinExchange::daysInMonth(int year, int month) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month == 2 && isLeapYear(year))
    return 29;

  return days[month - 1];
}

bool BitcoinExchange::validDate(const std::string& date) {
  if (date.length() != 10)
    return false;

  if (date[4] != '-' || date[7] != '-')
    return false;

  for (size_t i = 0; i < date.length(); i++) {
    if (i == 4 || i == 7)
      continue;

    if (!isdigit(date[i]))
      return false;
  }

  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());

  if (month < 1 || month > 12)
    return false;

  if (day < 1 || day > daysInMonth(year, month))
    return false;

  return true;
}

bool BitcoinExchange::parseValue(const std::string& str, float& value) {
  std::stringstream ss(str);
  ss >> value;

  if (ss.fail() || !ss.eof())
    return false;

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
    exit(1);
  }

  std::string line;
  getline(file, line);

  while (getline(file, line)) {
    std::stringstream ss(line);

    std::string date;
    std::string rateStr;

    getline(ss, date, ',');
    getline(ss, rateStr);

    float rate;
    std::stringstream rateStream(rateStr);
    rateStream >> rate;

    database_[date] = rate;
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
  getline(file, line);

  if (line != "date | value") {
    std::cout << "Error: bad input file header." << std::endl;
    return;
  }

  while (getline(file, line)) {
    if (line.empty())
      continue;

    size_t pipe = line.find('|');

    if (pipe == std::string::npos) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string date = trim(line.substr(0, pipe));
    std::string valueStr = trim(line.substr(pipe + 1));

    if (!validDate(date)) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    float value;

    if (!parseValue(valueStr, value))
      continue;

    float rate = getRate(date);

    std::cout << date << " => " << value << " = " << value * rate << std::endl;
  }

  file.close();
}
