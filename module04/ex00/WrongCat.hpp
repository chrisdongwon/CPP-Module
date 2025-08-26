/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:56:31 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:57:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat( void );
  WrongCat(const WrongCat& other);

  WrongCat& operator=(const WrongCat& other);

  ~WrongCat();

  void makeSound( void ) const;
};

#endif // WRONGCAT_HPP_
