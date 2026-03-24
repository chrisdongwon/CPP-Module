/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:44:35 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 10:47:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
T min(T a, T b) {
  if (a < b)
    return a;
  return b;
}

template <typename T>
T max(T a, T b) {
  if (a > b)
    return a;
  return b;
}

#endif  // WHATEVER_HPP_
