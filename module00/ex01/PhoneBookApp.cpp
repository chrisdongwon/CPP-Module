/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:34:48 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 14:48:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookApp.hpp"

#include <iomanip>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "util.hpp"

static std::string FormatField(const std::string& str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}

static void PrintHeader( void ) {
  std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First name" << "|"
            << std::setw(10) << "Last name" << "|"
            << std::setw(10) << "Nickname" << "\n";
}

static void PrintContacts(const PhoneBook& phonebook) {
  size_t count = phonebook.count();

  PrintHeader();
  for (size_t i = 0; i < count; ++i) {
    const Contact& c = phonebook.contacts(i % SIZE);
    std::cout << std::setw(10) << i + 1 << "|"
              << std::setw(10) << FormatField(c.first_name()) << "|"
              << std::setw(10) << FormatField(c.last_name()) << "|"
              << std::setw(10) << FormatField(c.nickname()) << "\n";
  }
}

static void PrintContact(const Contact& c) {
  std::cout << "First Name: " << c.first_name() << "\n";
  std::cout << "Last Name: " << c.last_name() << "\n";
  std::cout << "Nickname: " << c.nickname() << "\n";
  std::cout << "Phone Number: " << c.phone_number() << "\n";
  std::cout << "Darkest Secret: " << c.darkest_secret() << std::endl;
}

void SearchInteractive(PhoneBook& phonebook) {
  PrintContacts(phonebook);  
  std::string input = PromptUserNumber("Index");

  try {
    size_t index = StringToSizeT(input);

    if (index == 0 || index > phonebook.count()) {
      std::cout << "Invalid index: out of range" << std::endl;
      return;
    }

    PrintContact(phonebook.contacts((index - 1) % SIZE));
  } catch (const std::exception& e) {
    std::cout << "Invalid input: expected a non-negative integer (size_t)"
              << std::endl;
  }
}

static void AddContactInteractive(PhoneBook& phonebook) {
  std::string first_name = PromptUserInput("First name");
  std::string last_name = PromptUserInput("Last name");
  std::string nickname = PromptUserInput("Nickname");
  std::string phone_number = PromptUserNumber("Phone Number");
  std::string darkest_secret = PromptUserInput("Darkest secret");
  Contact new_contact = Contact(darkest_secret,
                                 first_name,
                                 last_name,
                                 nickname,
                                 phone_number);
  phonebook.AddContact(new_contact);
}

void RunPhoneBook( void ) {
  PhoneBook phonebook;
  std::string command;

  while (true) {
    std::cout << "Command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    if (command == "ADD") {
      AddContactInteractive(phonebook);
    } else if (command == "SEARCH") {
      SearchInteractive(phonebook);
    } else if (command == "EXIT") {
      return;
    }
  }
}
