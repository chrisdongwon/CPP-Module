/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:42 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:29:37 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal( void ) : type_("") {
  std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other) {
  *this = other;
  std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructed" << std::endl;
}

std::string Animal::Type( void ) const {
  return type_;
}

void Animal::makeSound( void ) const {
  std::cout << "Animal makes sound" << std::endl;
}

Animal::Animal(std::string type) : type_(type) {}
