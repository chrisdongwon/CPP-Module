/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:41:04 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 14:39:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>

class AMateria;

class ICharacter {
 public:
  virtual ~ICharacter() {}
  virtual std::string const & getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP_
