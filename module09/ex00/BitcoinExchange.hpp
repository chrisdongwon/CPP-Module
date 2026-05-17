/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:53:50 by cwon              #+#    #+#             */
/*   Updated: 2026/05/17 20:22:40 by cwon             ###   ########.fr       */
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
  void process(const std::string& filename);

 private:
  bool isLeapYear(int year);
  bool isValidDate(const std::string& date);
  bool parseValue(const std::string& str, float& value,
                  const std::string& line);
  float getRate(const std::string& date);
  int daysInMonth(int year, int month);

  std::map<std::string, float> database_;
};

#endif  // BITCOINEXCHANGE_HPP_
