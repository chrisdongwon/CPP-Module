/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:07:04 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 14:47:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
    : count_(0),
      index_(0) {}

const Contact& PhoneBook::contacts(size_t index) const {
  return contacts_[index];
}

size_t PhoneBook::count( void ) const {
  return count_;
}

void PhoneBook::AddContact(const Contact& contact) {
  contacts_[(index_++) % SIZE] = contact;
  if (++count_ > SIZE) {
    count_ = SIZE;
  }
}
