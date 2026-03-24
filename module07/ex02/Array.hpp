/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:59:40 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 11:03:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template <typename T>
class Array {
 public:
  Array();
  Array(unsigned int n);
  Array(const Array& other);
  Array& operator=(const Array& other);
  ~Array();

  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

  unsigned int size() const;

 private:
  T* _data;
  unsigned int _size;
};

#include "Array.tpp"

#endif  // ARRAY_HPP_
