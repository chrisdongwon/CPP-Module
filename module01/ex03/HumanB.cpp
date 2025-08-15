/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:09:17 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:12:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string& name)
    : name_(name),
      weapon_(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
  weapon_ = &weapon;
}

void HumanB::attack( void ) const {
  if (weapon_) {
    std::cout << name_ << " attacks with their "
              << weapon_->getType() << std::endl;
  }
}
