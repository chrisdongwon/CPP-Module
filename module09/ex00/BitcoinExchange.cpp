/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:01:17 by cwon              #+#    #+#             */
/*   Updated: 2026/05/17 20:35:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cctype>
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

void BitcoinExchange::loadDatabase(const std::string& filename) {
  std::ifstream file(filename.c_str());

  if (!file.is_open()) {
    std::cerr << "Error: could not open database." << std::endl;
    exit(1);
  }

  std::string line;

  getline(file, line);
  if (line != "date,exchange_rate") {
    std::cerr << "Error: bad database file header." << std::endl;
    file.close();
    exit(1);
  }

  while (getline(file, line)) {
    if (line.empty())
      continue;

    std::stringstream ss(line);

    std::string date, rateStr;

    if (!getline(ss, date, ',') || !getline(ss, rateStr)) {
      std::cerr << "Error: bad database line => " << line << std::endl;
      continue;
    }

    if (!isValidDate(date)) {
      std::cerr << "Error: invalid database date => " << line << std::endl;
      continue;
    }

    std::stringstream rateStream(rateStr);
    float rate;

    rateStream >> rate;
    if (rateStream.fail() || !rateStream.eof()) {
      std::cerr << "Error: bad database rate => " << line << std::endl;
      continue;
    }
    database_[date] = rate;
  }

  file.close();
}

void BitcoinExchange::process(const std::string& filename) {
  std::ifstream file(filename.c_str());

  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  getline(file, line);

  if (line != "date | value") {
    std::cerr << "Error: bad input file header." << std::endl;
    file.close();
    return;
  }

  while (getline(file, line)) {
    if (line.empty())
      continue;

    size_t index = line.find(" | ");

    if (index == std::string::npos) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::string date = line.substr(0, index);
    std::string valueStr = line.substr(index + 3);

    if (!isValidDate(date)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    float value;

    if (!parseValue(valueStr, value, line))
      continue;

    std::cout << date << " => " << value << " = " << value * getRate(date)
              << std::endl;
  }

  file.close();
}

bool BitcoinExchange::isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  for (size_t i = 0; i < date.length(); i++) {
    if (i != 4 && i != 7 && !isdigit(date[i]))
      return false;
  }

  int y = std::atoi(date.substr(0, 4).c_str());
  int m = std::atoi(date.substr(5, 2).c_str());
  int d = std::atoi(date.substr(8, 2).c_str());

  return (m >= 1 && m <= 12 && d >= 1 && d <= daysInMonth(y, m));
}

bool BitcoinExchange::parseValue(const std::string& str, float& value,
                                 const std::string& line) {
  if (str.empty()) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }

  std::stringstream ss(str);
  ss >> value;

  if (ss.fail() || !ss.eof()) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return false;
  }

  if (value < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }

  if (value > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return false;
  }

  return true;
}

float BitcoinExchange::getRate(const std::string& date) {
  std::map<std::string, float>::iterator it = database_.lower_bound(date);

  if (it == database_.begin())
    return 0;
  if (it != database_.end() && it->first == date)
    return it->second;
  return (--it)->second;
}

int BitcoinExchange::daysInMonth(int year, int month) {
  static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return days[month - 1] + (isLeapYear(year) && month == 2);
}
