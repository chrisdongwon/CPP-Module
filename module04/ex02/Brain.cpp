/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:04:54 by cwon              #+#    #+#             */
/*   Updated: 2025/08/26 14:35:11 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain( void ) {
  std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copied" << std::endl;
  *this = other;
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < 100; ++i) {
      ideas_[i] = other.ideas_[i];
    }
  }
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain destructed" << std::endl;
}

std::string Brain::ideas(int i) const {
  if (i >= 0 && i < 100) {
    return ideas_[i];
  }
  return "";
}

void Brain::set_ideas(int i, const std::string& idea) {
  if (i >= 0 && i < 100) {
    ideas_[i] = idea;
  }
}
