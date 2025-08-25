/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:24:49 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:36:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog( void );
  Dog(const Dog& other);

  Dog& operator=(const Dog& other);

  ~Dog();

  void makeSound( void ) const;
};

#endif // DOG_HPP_
