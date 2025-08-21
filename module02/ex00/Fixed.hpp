/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:22:18 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 12:10:05 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
 public:
  Fixed( void );
  Fixed(const Fixed& other);
  
  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits( void ) const;
  void setRawBits(int const raw);

 private:
  int value_;
  static const int kFractionalBits = 8;
};

#endif  // FIXED_HPP_
