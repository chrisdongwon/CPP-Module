/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:41:37 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 07:47:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();

  const Contact& GetContactAt(int index) const;
  void AddContact(const Contact& contact);

 private:
  Contact contacts_[8];
  int index_;
};

#endif  // PHONEBOOK_HPP_
