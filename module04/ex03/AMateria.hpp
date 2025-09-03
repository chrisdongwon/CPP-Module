/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:32:06 by cwon              #+#    #+#             */
/*   Updated: 2025/09/02 15:40:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <string>

class ICharacter;

class AMateria {
 public:
  AMateria( void );
  AMateria(std::string const & type);

  AMateria(const AMateria& other);

  AMateria& operator=(const AMateria& other);

  virtual ~AMateria();

  std::string const & getType() const;

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 protected:
  std::string type_;
};

#endif
