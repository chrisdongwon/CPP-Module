/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:40:47 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 14:40:36 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat( void );
  Cat(const Cat& other);

  Cat& operator=(const Cat& other);

  ~Cat();

  Brain* brain( void ) const;
  void makeSound( void ) const;

 private:
  Brain *brain_;
};

#endif // CAT_HPP_
