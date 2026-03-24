/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:59:40 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 11:48:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template <typename T>
class Array {
 public:
  Array(unsigned int n = 0);
  Array(const Array& other);
  Array& operator=(const Array& other);
  ~Array();

  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;

  unsigned int size() const;

 private:
  T* data_;
  unsigned int size_;
};

#include "Array.tpp"

#endif  // ARRAY_HPP_
