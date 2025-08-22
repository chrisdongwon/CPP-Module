/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:07:07 by cwon              #+#    #+#             */
/*   Updated: 2025/08/22 12:33:42 by cwon             ###   ########.fr       */
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

  virtual ~ClapTrap();

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 protected:
  ClapTrap(const std::string& name,
           int hit_points,
           int energy_points,
           int attack_damage);
 
  std::string name_;
  int hit_points_;
  int energy_points_;
  int attack_damage_;
};

#endif  // CLAPTRAP_HPP_
