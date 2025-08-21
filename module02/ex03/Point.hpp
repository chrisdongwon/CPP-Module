/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:03:35 by cwon              #+#    #+#             */
/*   Updated: 2025/08/21 13:24:11 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point {
 public:
  Point( void );
  Point(float x, float y);

  Point(const Point& other);

  Point& operator=(const Point& other);

  ~Point();

  Fixed x( void ) const;
  Fixed y( void ) const;

 private:
  const Fixed x_;
  const Fixed y_;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // POINT_HPP_
