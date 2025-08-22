/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:07:07 by cwon              #+#    #+#             */
/*   Updated: 2025/08/22 08:09:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

class ClapTrap {
 public:
  explicit ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);

  ClapTrap& operator=(const ClapTrap& other);

  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string name_;
  int hit_points_;
  int energy_points_;
  int attack_damage_;
};

#endif  // CLAPTRAP_HPP_
