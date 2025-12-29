/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:15:03 by cwon              #+#    #+#             */
/*   Updated: 2025/12/29 19:32:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap( void );
  explicit ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);

  ScavTrap& operator=(const ScavTrap& other);

  ~ScavTrap();

  void attack(const std::string& target); 
  void guardGate( void );
};

#endif  // SCAVTRAP_HPP_
