/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:34:48 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 16:45:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"
#include <iostream>
#include <string>

void MyAwesomePhoneBook( void ) {
  PhoneBook phonebook;
  std::string command;

  while (true) {
    std::cout << "Command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    if (command == "ADD") {
      Add(&phonebook);
    } else if (command == "SEARCH") {
      Search(&phonebook);
    } else if (command == "EXIT") {
      return;
    }
  }
}
