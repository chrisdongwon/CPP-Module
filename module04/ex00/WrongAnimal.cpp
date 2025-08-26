/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:55:53 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:56:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal( void ) : type_("") {
  std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  *this = other;
  std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructed" << std::endl;
}

std::string WrongAnimal::getType( void ) const {
  return type_;
}

void WrongAnimal::makeSound( void ) const {
  std::cout << "WrongAnimal makes wrong sound" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
  std::cout << "WrongAnimal constructed" << std::endl;
}
