/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:40:47 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:40:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat( void );
  Cat(const Cat& other);

  Cat& operator=(const Cat& other);

  ~Cat();

  void makeSound( void ) const;
};

#endif // CAT_HPP_
