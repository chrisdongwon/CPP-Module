/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:53:50 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 15:01:02 by cwon             ###   ########.fr       */
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
  bool validDate(const std::string& date);
  bool validValue(float value);
  float getRate(const std::string& date);

  std::map<std::string, float> database_;
};

#endif  // BITCOINEXCHANGE_HPP_
