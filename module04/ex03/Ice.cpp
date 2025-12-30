/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:55:10 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 14:31:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone( void ) const {
  try {
    return new Ice(*this);
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Ice failed to clone: " << e.what() << std::endl;
    return NULL;
  }
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
