/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:26:41 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 09:40:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include <stdint.h>

#include "Data.hpp"

class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);
  ~Serializer();
};

#endif  // SERIALIZER_HPP_
