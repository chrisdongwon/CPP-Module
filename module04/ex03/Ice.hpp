/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:59:03 by cwon              #+#    #+#             */
/*   Updated: 2025/09/03 08:11:58 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP_
#define ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice( void );
  Ice(const Ice& other);

  Ice& operator=(const Ice& other);
  
  ~Ice();
  
  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif // ICE_HPP_
