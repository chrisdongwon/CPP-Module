/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:09:38 by cwon              #+#    #+#             */
/*   Updated: 2025/12/29 21:05:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name_(name),
      hit_points_(10),
      energy_points_(10),
      attack_damage_(0) {
  std::cout << "ClapTrap " << name_ << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  *this = other;
  std::cout << "ClapTrap " << name_ << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    name_ = other.name_;
    hit_points_ = other.hit_points_;
    energy_points_ = other.energy_points_;
    attack_damage_ = other.attack_damage_;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name_ << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (hit_points_ <= 0 || energy_points_ <= 0) {
    std::cout << "ClapTrap " << name_ << " does not have enough hit points "
              << "or energy points to attack " 
              << target << "!" << std::endl;
  } else {
    --energy_points_;
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing "
              << attack_damage_ << " points of damage!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit_points_ <= 0) {
    std::cout << "ClapTrap " << name_ << " is already destroyed!" << std::endl;
  } else {
    hit_points_ -= amount;
    if (hit_points_ < 0) {
      hit_points_ = 0;
    }
    std::cout << "ClapTrap " << name_ << " takes " << amount
              << " points of damage! Remaining hit points: "
              << hit_points_ << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hit_points_ <= 0 || energy_points_ <= 0) {
    std::cout << "ClapTrap " << name_ << " does not have enough hit points "
              << "or energy points to be repaired!" << std::endl;
  } else {
    --energy_points_;
    hit_points_ += amount;
    std::cout << "ClapTrap " << name_ << " repairs itself for " << amount
              << " hit points! Current hit points: " << hit_points_
              << std::endl;
  }
}
