/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:24:06 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 12:44:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP_
#define EASYFIND_TPP_

#include <algorithm>

const char* NotFoundException::what() const throw() {
  return "Value not found in container";
}

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it;

  it = std::find(container.begin(), container.end(), value);

  if (it == container.end())
    throw NotFoundException();

  return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
  typename T::const_iterator it;

  it = std::find(container.begin(), container.end(), value);

  if (it == container.end())
    throw NotFoundException();

  return it;
}

#endif  // EASYFIND_TPP_
