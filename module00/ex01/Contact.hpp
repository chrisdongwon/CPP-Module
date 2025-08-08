/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:26:02 by cwon              #+#    #+#             */
/*   Updated: 2025/08/08 09:53:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

class Contact {
 public:
  Contact();
  Contact(const std::string& darkest_secret,
          const std::string& first_name,
          const std::string& last_name,
          const std::string& nickname,
          const std::string& phone_number);

  const std::string& DarkestSecret() const;
  const std::string& FirstName() const;
  const std::string& LastName() const;
  const std::string& Nickname() const;
  const std::string& PhoneNumber() const;

 private:
  std::string darkest_secret_;
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
};

#endif  // CONTACT_HPP_
