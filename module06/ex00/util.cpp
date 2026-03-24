/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:05:54 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 08:12:43 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>

bool ScalarConverter::isChar(const std::string& s) {
  return (s.length() == 1 && !isdigit(s[0]));
}

bool ScalarConverter::isDouble(const std::string& s) {
  if (s == "-inf" || s == "+inf" || s == "nan")
    return true;
  char* end;
  std::strtod(s.c_str(), &end);
  return (*end == '\0');
}

bool ScalarConverter::isInt(const std::string& s) {
  char* end;
  std::strtol(s.c_str(), &end, 10);
  return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string& s) {
  if (s == "-inff" || s == "+inff" || s == "nanf")
    return true;
  if (s[s.length() - 1] != 'f')
    return false;
  char* end;
  std::strtof(s.c_str(), &end);
  return (*end == 'f' && *(end + 1) == '\0');
}
