/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 09:03:19 by cwon              #+#    #+#             */
/*   Updated: 2025/09/03 09:33:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource( void );
  MateriaSource(const MateriaSource& other);

  MateriaSource& operator=(const MateriaSource& other);

  ~MateriaSource();

  AMateria* createMateria(const std::string& type);
  void learnMateria(AMateria* m);

 private:
  AMateria* storage_[4];
};

#endif // MATERIASOURCE_HPP_
