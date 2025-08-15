/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:00:34 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:10:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type_(type) {}

const std::string& Weapon::getType() const {
  return type_;
}

void Weapon::setType(const std::string& type) {
  type_ = type;
}
