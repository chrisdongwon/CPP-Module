/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:00:06 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 09:49:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed( void ) : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  value_ = value << kFractionalBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  value_ = static_cast<int>(roundf(value * (1 << kFractionalBits)));
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    value_ = other.value_;
  }
  return *this;
}

Fixed::~Fixed( void ) {
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
  return static_cast<float>(value_) / (1 << kFractionalBits);
}

int Fixed::toInt ( void ) const {
  return value_ >> kFractionalBits;
}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
