/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:15:05 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 12:40:38 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
  std::cout << "FragTrap " << name_ << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap " << name_ << " copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  ClapTrap::operator=(other);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name_ << " destructed!" << std::endl;
}

void FragTrap::highFivesGuys( void ) {
  std::cout << "FragTrap " << name_ << " requests positive high fives!"
            << std::endl;
}
