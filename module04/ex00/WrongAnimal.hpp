/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:54:54 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:04:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 public:
  WrongAnimal(std::string type = "");
  WrongAnimal(const WrongAnimal& other);

  WrongAnimal& operator=(const WrongAnimal& other);

  ~WrongAnimal();

  std::string getType( void ) const;
  void makeSound( void ) const;

 protected:
  std::string type_;
};

#endif // WRONGANIMAL_HPP_
