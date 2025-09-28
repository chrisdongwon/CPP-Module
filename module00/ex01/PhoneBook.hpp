/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:41:37 by cwon              #+#    #+#             */
/*   Updated: 2025/09/28 14:50:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#define SIZE 8

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook( void );

  const Contact& contacts(size_t index) const;
  size_t count( void ) const;

  void AddContact(const Contact& contact);

 private:
  Contact contacts_[SIZE];
  size_t count_;
  size_t index_;
};

#endif  // PHONEBOOK_HPP_
