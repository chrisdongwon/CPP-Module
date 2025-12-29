/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:28:06 by cwon              #+#    #+#             */
/*   Updated: 2025/12/29 18:51:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      FragTrap(name),
      ScavTrap(name),
      name_(name) {
  hit_points_ = FragTrap::hit_points_;
  energy_points_ = ScavTrap::energy_points_;
  attack_damage_ = FragTrap::attack_damage_;
  std::cout << "DiamondTrap " << name_ << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      FragTrap(other),
      ScavTrap(other),
      name_(other.name_) {
  std::cout << "DiamondTrap " << name_ << "copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    name_ = other.name_;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name_ << " destructed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am DiamondTrap " << name_
            << " and my ClapTrap name is " << ClapTrap::name_ << "!"
            << std::endl;
}
