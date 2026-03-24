/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:56:26 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 08:13:41 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

static void printChar(double value) {
  std::cout << "char: ";
  if (std::isnan(value) || value < 0 || value > 127)
    std::cout << "impossible\n";
  else if (!isprint(static_cast<int>(value)))
    std::cout << "Non displayable\n";
  else
    std::cout << "'" << static_cast<char>(value) << "'\n";
}

static void printDouble(double value) {
  std::cout << "double: ";
  if (std::isnan(value))
    std::cout << "nan\n";
  else if (std::isinf(value))
    std::cout << (value > 0 ? "+inf\n" : "-inf\n");
  else {
    std::cout << value;
    if (value == static_cast<int>(value))
      std::cout << ".0";
    std::cout << "\n";
  }
}

static void printInt(double value) {
  std::cout << "int: ";
  if (std::isnan(value) || value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(value) << "\n";
}

static void printFloat(double value) {
  std::cout << "float: ";
  float f = static_cast<float>(value);
  if (std::isnan(f))
    std::cout << "nanf\n";
  else if (std::isinf(f))
    std::cout << (f > 0 ? "+inff\n" : "-inff\n");
  else {
    std::cout << f;
    if (f == static_cast<int>(f))
      std::cout << ".0";
    std::cout << "f\n";
  }
}

void ScalarConverter::convert(const std::string& literal) {
  double result = 0.0;

  if (isChar(literal)) {
    result = static_cast<double>(literal[0]);
  } else if (isInt(literal)) {
    result = static_cast<double>(std::atoi(literal.c_str()));
  } else if (isFloat(literal)) {
    result = static_cast<double>(std::strtof(literal.c_str(), NULL));
  } else if (isDouble(literal)) {
    result = std::strtod(literal.c_str(), NULL);
  } else {
    std::cout << "Invalid literal\n";
    return;
  }

  printChar(result);
  printInt(result);
  printFloat(result);
  printDouble(result);
}
