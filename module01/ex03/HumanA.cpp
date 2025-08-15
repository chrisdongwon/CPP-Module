/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:06:45 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:07:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name_(name),
      weapon_(weapon) {}

void HumanA::attack( void ) const {
  std::cout << name_ << " attacks with their "
            << weapon_.getType() << std::endl;
}
