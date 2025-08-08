/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:55:28 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 10:00:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : darkest_secret_(),
      first_name_(),
      last_name_(),
      nickname_(),
      phone_number_() {}

Contact::Contact(const std::string& darkest_secret,
                 const std::string& first_name,
                 const std::string& last_name,
                 const std::string& nickname,
                 const std::string& phone_number)
    : darkest_secret_(darkest_secret),
      first_name_(first_name),
      last_name_(last_name),
      nickname_(nickname),
      phone_number_(phone_number) {}

const std::string& Contact::DarkestSecret() const {
  return darkest_secret_;
}

const std::string& Contact::FirstName() const {
  return first_name_;
}

const std::string& Contact::LastName() const {
  return last_name_;
}

const std::string& Contact::Nickname() const {
  return nickname_;
}

const std::string& Contact::PhoneNumber() const {
  return phone_number_;
}
