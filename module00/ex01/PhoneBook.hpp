/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:41:37 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 16:45:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook( void );

  const Contact& ContactAt(size_t index) const;
  size_t Count( void ) const;
  size_t Start( void ) const;

  void AddContact(const Contact& contact);

 private:
  Contact contacts_[8];
  size_t count_;
  size_t index_;
  size_t start_;
};

#endif  // PHONEBOOK_HPP_
