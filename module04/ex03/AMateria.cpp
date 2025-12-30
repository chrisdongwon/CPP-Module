/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:46:47 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 14:08:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type_(type) {}

AMateria::AMateria(const AMateria& other) : type_(other.type_) {}

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
  return type_;
}

void AMateria::use(ICharacter& target) {
  std::cout << "* AMateria use() called on " << target.getName() << " *"
            << std::endl;
}
