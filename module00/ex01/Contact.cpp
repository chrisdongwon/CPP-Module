/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:55:28 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 13:30:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
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

const std::string& Contact::darkest_secret( void ) const {
  return darkest_secret_;
}

const std::string& Contact::first_name( void ) const {
  return first_name_;
}

const std::string& Contact::last_name( void ) const {
  return last_name_;
}

const std::string& Contact::nickname( void ) const {
  return nickname_;
}

const std::string& Contact::phone_number( void ) const {
  return phone_number_;
}
