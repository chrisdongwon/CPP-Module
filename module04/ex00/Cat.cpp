/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:39:48 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:04:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat( void )
    : Animal("Cat") {
  std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound( void ) const {
  std::cout << "Cat meows" << std::endl;
}
