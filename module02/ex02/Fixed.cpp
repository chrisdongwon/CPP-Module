/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:30:49 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 12:57:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed( void ) : value_(0) {}

Fixed::Fixed(const int value) {
  value_ = value << kFractionalBits;
}

Fixed::Fixed(const float value) {
  value_ = static_cast<int>(roundf(value * (1 << kFractionalBits)));
}

Fixed::Fixed(const Fixed& other) {
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    value_ = other.value_;
  }
  return *this;
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed& other) const {
  return value_ > other.value_;
}

bool Fixed::operator<(const Fixed& other) const {
  return value_ < other.value_;
}

bool Fixed::operator>=(const Fixed& other) const {
  return value_ >= other.value_;
}

bool Fixed::operator<=(const Fixed& other) const {
  return value_ <= other.value_;
}

bool Fixed::operator==(const Fixed& other) const {
  return value_ == other.value_;
}

bool Fixed::operator!=(const Fixed& other) const {
  return value_ != other.value_;
}

Fixed Fixed::operator+(const Fixed& other) const {
  Fixed result;

  result.value_ = value_ + other.value_;
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;

  result.value_ = value_ - other.value_;
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;
  long temp = static_cast<long>(value_) * other.value_;

  result.value_ = static_cast<int>(temp >> kFractionalBits);
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;
  long temp = (static_cast<long>(value_) << kFractionalBits) / other.value_;

  result.value_ = static_cast<int>(temp);
  return result;
}

Fixed& Fixed::operator++( void ) {
  ++value_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);

  value_++;
  return tmp;
}

Fixed& Fixed::operator--( void ) {
  --value_;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);

  value_--;
  return tmp;
}

int Fixed::getRawBits( void ) const {
  return value_;
}

void Fixed::setRawBits(int const raw) {
  value_ = raw;
}

float Fixed::toFloat( void ) const {
  return static_cast<float>(value_) / (1 << kFractionalBits);
}

int Fixed::toInt ( void ) const {
  return value_ >> kFractionalBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
