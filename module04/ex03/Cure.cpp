/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:16:26 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 14:30:56 by cwon             ###   ########.fr       */
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
  try {
    return new Cure(*this);
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Cure failed to clone: " << e.what() << std::endl;
    return NULL;
  }
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "’s wounds *"
            << std::endl;
}
