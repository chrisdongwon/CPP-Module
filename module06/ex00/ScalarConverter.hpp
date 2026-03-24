/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:54:12 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 09:28:59 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP_
#define SCALARCONVERTER_HPP_

#include <string>

class ScalarConverter {
 public:
  static void convert(const std::string& literal);

 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();

  static bool isChar(const std::string& s);
  static bool isDouble(const std::string& s);
  static bool isFloat(const std::string& s);
  static bool isInt(const std::string& s);
};

#endif  // SCALARCONVERTER_HPP_
