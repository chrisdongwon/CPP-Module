/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 08:47:10 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 12:10:21 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  Fixed(const Fixed& other);
  explicit Fixed(const int value);
  explicit Fixed(const float value);

  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  int value_;
  static const int kFractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif  // FIXED_HPP_
