/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:07:04 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 10:12:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index_(0) {}

const Contact& PhoneBook::GetContactAt(int index) const {
  return contacts_[index];
}

void PhoneBook::AddContact(const Contact& contact) {
  contacts_[(index_++) % 8] = contact;
}
