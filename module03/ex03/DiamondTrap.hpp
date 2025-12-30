/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:25:10 by cwon              #+#    #+#             */
/*   Updated: 2025/12/29 21:36:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  explicit DiamondTrap(const std::string& name = "DiamondTrap");
  DiamondTrap(const DiamondTrap& other);

  DiamondTrap& operator=(const DiamondTrap& other);
  
  ~DiamondTrap();

  void attack(const std::string& target);
  void whoAmI();

 private:
  std::string name_;
};

#endif // DIAMONDTRAP_HPP_
