/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:52 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:04:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog( void )
    : Animal("Dog") {
  std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound( void ) const {
  std::cout << "Dog barks" << std::endl;
}
