/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:25:52 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:37:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog( void ) : Animal("Dog") {
  try {
    brain_ = new Brain();
  } catch (const std::bad_alloc& e) {
    std::cerr << "Dog failed to allocate Brain: " << e.what() << std::endl;
    brain_ = NULL;
  }
  std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other),
      brain_(NULL) {
  copy_brain(other);
  std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete brain_;
    brain_ = NULL;
    copy_brain(other);
  }
  return *this;
}

Dog::~Dog() {
  delete brain_;
  std::cout << "Dog destructed" << std::endl;
}

Brain* Dog::brain( void ) const {
  return brain_;
}

void Dog::makeSound( void ) const {
  std::cout << "Dog barks" << std::endl;
}

void Dog::copy_brain(const Dog& other) {
  if (other.brain_) {
    try {
      brain_ = new Brain(*other.brain_);
    } catch (const std::bad_alloc& e) {
      std::cerr << "Dog failed to allocate Brain: " << e.what() << std::endl;
      brain_ = NULL;
    }
  }
}
