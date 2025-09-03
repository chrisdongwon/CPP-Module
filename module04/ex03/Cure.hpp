/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:14:17 by cwon              #+#    #+#             */
/*   Updated: 2025/09/02 15:51:09 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP_
#define CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure( void );
  Cure(const Cure& other);

  Cure& operator=(const Cure& other);

  ~Cure();

  AMateria* clone( void ) const;
  void use(ICharacter& target);
};

#endif  // CURE_HPP_
