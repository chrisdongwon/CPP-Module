/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:07:57 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:09:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include <string>

#include "Weapon.hpp"

class HumanB {
 public:
  explicit HumanB(const std::string& name);

  void setWeapon(Weapon& weapon);
  void attack( void ) const;

 private:
  std::string name_;
  Weapon* weapon_;
};

#endif  // HUMANB_HPP_
