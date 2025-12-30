/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:11:24 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 13:51:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP_
#define AANIMAL_HPP_

#include <string>

class AAnimal {
 public:
  AAnimal(std::string type = "");
  AAnimal(const AAnimal& other);

  AAnimal& operator=(const AAnimal& other);

  virtual ~AAnimal();

  std::string getType( void ) const;
  virtual void makeSound( void ) const = 0;

 protected:
  std::string type_;
};

#endif // AANIMAL_HPP_
