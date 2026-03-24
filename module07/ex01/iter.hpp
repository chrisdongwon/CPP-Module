/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:52:33 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 10:53:39 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>

template <typename T, typename F>
void iter(T* array, const size_t length, F func) {
  for (size_t i = 0; i < length; ++i) {
    func(array[i]);
  }
}

#endif  // ITER_HPP_
