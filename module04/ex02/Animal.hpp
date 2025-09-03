/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:11:24 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 15:20:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal {
 public:
  Animal( void );
  Animal(const Animal& other);

  Animal& operator=(const Animal& other);

  virtual ~Animal();

  std::string getType( void ) const;
  virtual void makeSound( void ) const = 0;

 protected:
  Animal(std::string type);
  
  std::string type_;
};

#endif // ANIMAL_HPP_
