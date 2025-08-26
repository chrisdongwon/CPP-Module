/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:54:54 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:55:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 public:
  WrongAnimal( void );
  WrongAnimal(const WrongAnimal& other);

  WrongAnimal& operator=(const WrongAnimal& other);

  ~WrongAnimal();

  std::string getType( void ) const;
  void makeSound( void ) const;

 protected:
  WrongAnimal(std::string type);
  
  std::string type_;
};

#endif // WRONGANIMAL_HPP_
