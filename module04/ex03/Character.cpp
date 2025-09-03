/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:13:34 by cwon              #+#    #+#             */
/*   Updated: 2025/09/03 11:52:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include "AMateria.hpp"

Character::Character( void ) {
  for (int i = 0; i < 4; ++i) {
    inventory_[i] = NULL;
  }
}

Character::Character(const std::string& name) : name_(name) {
  for (int i = 0; i < 4; ++i) {
    inventory_[i] = NULL;
  }
}

Character::Character(const Character& other) : name_(other.name_) {
  for (int i = 0; i < 4; ++i) {
    if (other.inventory_[i])
      inventory_[i] = other.inventory_[i]->clone();
    else
      inventory_[i] = NULL;
  }
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    name_ = other.name_;
    for (int i = 0; i < 4; ++i) {
      delete inventory_[i];
      if (other.inventory_[i])
        inventory_[i] = other.inventory_[i]->clone();
      else
        inventory_[i] = NULL;
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; ++i) {
    delete inventory_[i];
  }
}

const std::string& Character::getName( void ) const {
  return name_;
}

void Character::equip(AMateria* m) {
  if (m) {
    for (int i = 0; i < 4; ++i) {
      if (inventory_[i] == NULL) {
        inventory_[i] = m;
        return;
      }
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    inventory_[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && inventory_[idx]) {
    inventory_[idx]->use(target);
  }
}
