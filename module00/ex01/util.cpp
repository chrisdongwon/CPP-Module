/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:39:43 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 17:12:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.hpp"

#include <iostream>
#include <sstream>

static bool IsAllDigits(const std::string& input) {
  for (size_t i = 0; i < input.length(); ++i) {
    if (!std::isdigit(static_cast<unsigned char>(input[i]))) {
      return false;
    }
  }
  return true;
}

const std::string PromptUserInput(const std::string field_type) {
  std::string response;

  while (true)
  {
    std::cout << field_type << ": ";
    std::getline(std::cin, response);
    if (!response.empty())
      break;
    std::cout << "Error: " << field_type 
              << " cannot be empty. Please try again." << std::endl;
  }
  return response;
}

const std::string PromptUserNumber(const std::string field_type) {
  std::string response;

  while (true) {
    response = PromptUserInput(field_type);
    if (IsAllDigits(response))
      break;
    std::cout << "Error: " << field_type
              << " must contain only digits (0–9). Please try again."
              << std::endl;
  }
  return response;
}

size_t StringToSizeT(const std::string& str) {
    size_t result;
    std::stringstream ss(str);

    ss >> result;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Expected a non-negative integer (size_t)");
    }
    return result;
}
