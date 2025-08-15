/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookApp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:34:48 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 17:24:58 by cwon             ###   ########.fr       */
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
  size_t count = phonebook.Count();
  size_t starting_index = phonebook.Start();

  PrintHeader();
  for (size_t i = 0; i < count; i++) {
    const Contact& c = phonebook.ContactAt((starting_index + i) % 8);
    std::cout << std::setw(10) << i + 1 << "|"
              << std::setw(10) << FormatField(c.FirstName()) << "|"
              << std::setw(10) << FormatField(c.LastName()) << "|"
              << std::setw(10) << FormatField(c.Nickname()) << "\n";
  }
}

static void PrintContact(const Contact& c) {
  std::cout << "First Name: " << c.FirstName() << "\n";
  std::cout << "Last Name: " << c.LastName() << "\n";
  std::cout << "Nickname: " << c.Nickname() << "\n";
  std::cout << "Phone Number: " << c.PhoneNumber() << "\n";
  std::cout << "Darkest Secret: " << c.DarkestSecret() << std::endl;
}

void SearchInteractive(PhoneBook& phonebook) {
  PrintContacts(phonebook);  
  std::string input = PromptUserNumber("Index");

  try {
    size_t index = StringToSizeT(input);

    if (index == 0 || index > phonebook.Count()) {
      std::cout << "Invalid index: out of range" << std::endl;
      return;
    }

    PrintContact(phonebook.ContactAt((phonebook.Start() + index - 1) % 8));
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
