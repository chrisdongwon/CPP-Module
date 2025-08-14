/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:17:18 by cwon              #+#    #+#             */
/*   Updated: 2025/08/14 16:49:06 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) : name_(name) {}

Zombie::~Zombie( void ) {
  std::cout << name_ << " has been destroyed" << std::endl;
}

void Zombie::announce( void ) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
