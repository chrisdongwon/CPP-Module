/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:42 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:51:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal(std::string type)
    : type_(type) {
  std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
  *this = other;
  std::cout << "AAnimal copied" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}

AAnimal::~AAnimal() {
  std::cout << "AAnimal destructed" << std::endl;
}

std::string AAnimal::getType( void ) const {
  return type_;
}
