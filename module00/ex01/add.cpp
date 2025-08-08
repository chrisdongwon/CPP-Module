/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:28:56 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 18:15:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

void Add(PhoneBook* phonebook) {
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
  phonebook->AddContact(new_contact);
}
