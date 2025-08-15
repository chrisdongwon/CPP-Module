/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:01:32 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:06:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include <string>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(const std::string& name, Weapon& weapon);

  void attack( void ) const;

 private:
  std::string name_;
  Weapon& weapon_;
};

#endif  // HUMANA_HPP_
