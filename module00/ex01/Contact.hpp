/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:26:02 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 13:30:14 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
#define CONTACT_HPP_

#include <string>

class Contact {
 public:
  Contact( void );
  Contact(const std::string& darkest_secret,
          const std::string& first_name,
          const std::string& last_name,
          const std::string& nickname,
          const std::string& phone_number);

  const std::string& darkest_secret( void ) const;
  const std::string& first_name( void ) const;
  const std::string& last_name( void ) const;
  const std::string& nickname( void ) const;
  const std::string& phone_number( void ) const;

 private:
  std::string darkest_secret_;
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
};

#endif  // CONTACT_HPP_
