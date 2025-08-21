/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2D.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:31:52 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 14:41:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2D.hpp"

Vector2D::Vector2D( void )
    : i_(0),
      j_(0) {}

Vector2D::Vector2D(const Point& start, const Point& end)
    : i_(end.x() - start.x()),
      j_(end.y() - start.y()) {}

Vector2D::Vector2D(const Vector2D& other)
    : i_(other.i_),
      j_(other.j_) {}

Vector2D::~Vector2D() {}

Vector2D& Vector2D::operator=(const Vector2D& other) {
  if (this != &other) {
    i_ = other.i_;
    j_ = other.j_;
  }
  return *this;
}

Fixed Vector2D::i() const {
  return i_;
}

Fixed Vector2D::j() const {
  return j_;
}

Fixed Vector2D::Determinant(const Vector2D& other) const {
  return i_ * other.j_ - j_ * other.i_;
}
