/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:08:52 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 15:49:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void )
    : x_(0),
      y_(0) {}

Point::Point(float x, float y)
    : x_(x),
      y_(y) {}

Point::Point(const Point& other)
    : x_(other.x_),
      y_(other.y_) {}

// since x_ and y_ are const attributes, they cannot be reassigned
// therefore, assignment operator has no effect
Point& Point::operator=(const Point& other) {
  (void)other;
  return *this;
}

Point::~Point() {}

Fixed Point::x( void ) const {
  return x_;
}

Fixed Point::y( void ) const {
  return y_;
}
