/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 09:07:06 by cwon              #+#    #+#             */
/*   Updated: 2025/09/03 09:38:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource( void ) {
  for (int i = 0; i < 4; ++i) {
    storage_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  for (int i = 0; i < 4; ++i) {
    if (other.storage_[i])
      storage_[i] = other.storage_[i]->clone();
    else
      storage_[i] = NULL;
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if (this != &other) {
    for (int i = 0; i < 4; ++i) {
      delete storage_[i];
      if (other.storage_[i])
        storage_[i] = other.storage_[i]->clone();
      else
        storage_[i] = NULL;
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    delete storage_[i];
  }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < 4; ++i) {
    if (storage_[i] && storage_[i]->getType() == type) {
      return storage_[i]->clone();
    }
  }
  return NULL;
}

void MateriaSource::learnMateria(AMateria* m) {
  if (m) {
    for (int i = 0; i < 4; ++i) {
      if (storage_[i] == NULL) {
        storage_[i] = m->clone();
        return;
      }
    }
  }
}
