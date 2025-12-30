/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:15:03 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 12:37:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  explicit ScavTrap(const std::string& name = "ScavTrap");
  ScavTrap(const ScavTrap& other);

  ScavTrap& operator=(const ScavTrap& other);

  ~ScavTrap();

  void attack(const std::string& target); 
  void guardGate();

 protected:
  static const int kHitPoints = 100;
  static const int kEnergyPoints = 50;
  static const int kAttackDamage = 20;
};

#endif  // SCAVTRAP_HPP_
