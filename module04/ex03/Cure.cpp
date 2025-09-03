/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:16:26 by cwon              #+#    #+#             */
/*   Updated: 2025/09/03 08:07:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone( void ) const {
  return new Cure(*this);
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "’s wounds *"
            << std::endl;
}
