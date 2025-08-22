/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:15:03 by cwon              #+#    #+#             */
/*   Updated: 2025/08/22 12:55:23 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  explicit ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);

  ScavTrap& operator=(const ScavTrap& other);

  ~ScavTrap();

  void attack(const std::string& target); 
  void guardGate( void );
};

#endif  // SCAVTRAP_H_
