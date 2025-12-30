/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:28:06 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 14:43:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
  explicit Character(const std::string& name = "");
  Character(const Character& other);

  Character& operator=(const Character& other);
  
  ~Character();

  const std::string& getName( void ) const;

  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);

 private:
  void copy_inventory(const Character& other, int i);
  
  AMateria* inventory_[4];
  std::string name_;
};

#endif  // CHARACTER_HPP_
