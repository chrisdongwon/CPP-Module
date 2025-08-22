/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:15:05 by cwon              #+#    #+#             */
/*   Updated: 2025/08/22 12:44:51 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "ScavTrap " << name_ << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << "ScavTrap " << name_ << " copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  ClapTrap::operator=(other);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name_ << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (hit_points_ <= 0 || energy_points_ <= 0) {
    std::cout << "ScavTrap " << name_ << " does not have enough hit points "
              << "or energy points to attack " 
              << target << "!" << std::endl;
  } else {
    --energy_points_;
    std::cout << "ScavTrap " << name_ << " attacks " << target
              << ", causing " << attack_damage_ << " points of damage!"
              << std::endl;
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name_ << " is now in Gate Keeper mode!"
            << std::endl;
}
