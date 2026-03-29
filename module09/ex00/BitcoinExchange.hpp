/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:53:50 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:05:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <map>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  void loadDatabase(const std::string& filename);
  void processInput(const std::string& filename);

 private:
  std::string trim(const std::string& str);
  bool validDate(const std::string& date);
  bool isLeapYear(int year);
  int daysInMonth(int year, int month);

  bool parseValue(const std::string& str, float& value);
  float getRate(const std::string& date);

  std::map<std::string, float> database_;
};

#endif  // BITCOINEXCHANGE_HPP_
