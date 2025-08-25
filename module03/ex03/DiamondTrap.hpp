/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:25:10 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 15:37:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 public:
  explicit DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& other);

  DiamondTrap& operator=(const DiamondTrap& other);
  
  ~DiamondTrap();

  using ScavTrap::attack;
  void whoAmI();

 private:
  std::string name_;
};

#endif // DIAMONDTRAP_HPP_
