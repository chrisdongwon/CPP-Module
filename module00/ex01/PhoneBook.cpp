/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:07:04 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 13:31:56 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
    : count_(0),
      index_(0),
      start_(0) {}

const Contact& PhoneBook::contacts(size_t index) const {
  return contacts_[index];
}

size_t PhoneBook::count( void ) const {
  return count_;
}

size_t PhoneBook::start( void ) const {
  return start_;
}

void PhoneBook::AddContact(const Contact& contact) {
  contacts_[(index_++) % 8] = contact;
  if (++count_ > 8) {
    count_ = 8;
    start_ = (start_ + 1) % 8;
  }
}
