/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:39:48 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:35:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat( void ) : Animal("Cat") {
  try {
    brain_ = new Brain();
  } catch (const std::bad_alloc& e) {
    std::cerr << "Cat failed to allocate Brain: " << e.what() << std::endl;
    brain_ = NULL;
  }
  std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other),
      brain_(NULL) {
  copy_brain(other);
  std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete brain_;
    brain_ = NULL;
    copy_brain(other);
  }
  return *this;
}

Cat::~Cat() {
  delete brain_;
  std::cout << "Cat destructed" << std::endl;
}

Brain* Cat::brain( void ) const {
  return brain_;
}

void Cat::makeSound( void ) const {
  std::cout << "Cat meows" << std::endl;
}

void Cat::copy_brain(const Cat& other) {
  if (other.brain_) {
    try {
      brain_ = new Brain(*other.brain_);
    } catch (const std::bad_alloc& e) {
      std::cerr << "Cat failed to allocate Brain: " << e.what() << std::endl;
      brain_ = NULL;
    }
  }
}
