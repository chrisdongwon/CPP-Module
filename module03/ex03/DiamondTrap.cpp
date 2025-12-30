/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:28:06 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 12:39:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(),
      FragTrap(),
      name_(name) {
  hit_points_ = FragTrap::kHitPoints;
  energy_points_ = ScavTrap::kEnergyPoints;
  attack_damage_ = FragTrap::kAttackDamage;
  std::cout << "DiamondTrap " << name_ << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      ScavTrap(),
      FragTrap() {
  name_ = other.name_;
  hit_points_ = other.hit_points_;
  energy_points_ = other.energy_points_;
  attack_damage_ = other.attack_damage_;
  std::cout << "DiamondTrap " << name_ << " copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
  if (this != &other) {
    ClapTrap::operator=(other);
    name_ = other.name_;
    hit_points_ = other.hit_points_;
    energy_points_ = other.energy_points_;
    attack_damage_ = other.attack_damage_;
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
