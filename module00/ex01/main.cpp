/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:54:50 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 10:25:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>

void MyAwesomePhoneBook() {
  std::string command;

  while (true) {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    if (command == "ADD") {
      std::cout << "You chose to ADD a contact." << std::endl;
    } else if (command == "SEARCH") {
      std::cout << "You chose to SEARCH contacts." << std::endl;
    } else if (command == "EXIT") {
      break;
    }
  }
}

int main() {
  MyAwesomePhoneBook();
  return 0;
}
