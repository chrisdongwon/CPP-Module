/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:03:13 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 13:03:24 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>

class Fixed {
 public:
  Fixed( void );
  Fixed(const Fixed& other);
  explicit Fixed(const int value);
  explicit Fixed(const float value);

  ~Fixed();
  
  Fixed& operator=(const Fixed& other);

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  Fixed& operator++( void );
  Fixed operator++(int);
  Fixed& operator--( void );
  Fixed operator--(int);

  int getRawBits( void ) const;
  void setRawBits(int const raw);

  float toFloat( void ) const;
  int toInt ( void ) const;

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

 private:
  int value_;
  static const int kFractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

#endif  // FIXED_HPP_
