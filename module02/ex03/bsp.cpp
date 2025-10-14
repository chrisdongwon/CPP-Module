/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:23:51 by cwon              #+#    #+#             */
/*   Updated: 2025/10/14 16:05:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2D.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p) {
  Vector2D ab(a, b);
  Vector2D bc(b, c);
  Vector2D ca(c, a);

  Vector2D ap(a, p);
  Vector2D bp(b, p);
  Vector2D cp(c, p);
  
  Fixed det1 = ab.Determinant(ap);
  Fixed det2 = bc.Determinant(bp);
  Fixed det3 = ca.Determinant(cp);

  // determinant of parallel vectors is zero
  // if the determinant is zero, then the point lies on the edge
  if (det1 == Fixed(0) || det2 == Fixed(0) || det3 == Fixed(0)) {
    return false; 
  }

  bool found_neg = (det1 < Fixed(0)) || (det2 < Fixed(0)) || (det3 < Fixed(0));
  bool found_pos = (det1 > Fixed(0)) || (det2 > Fixed(0)) || (det3 > Fixed(0));

  // if p is in the triangle, then the determinants must have the same signs
  // e.g. the cross products will have the same signs
  return !(found_pos && found_neg);
}
