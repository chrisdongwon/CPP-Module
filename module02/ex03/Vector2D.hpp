/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2D.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:25:08 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 14:34:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

#include "Point.hpp"

class Vector2D {
 public:
  Vector2D( void );
  Vector2D(const Point& start, const Point& end);

  Vector2D(const Vector2D& other);

  ~Vector2D();

  Vector2D& operator=(const Vector2D& other);

  Fixed i() const;
  Fixed j() const;

  Fixed Determinant(const Vector2D& other) const;

 private:
  Fixed i_;
  Fixed j_;
};

#endif  // VECTOR2D_HPP_
