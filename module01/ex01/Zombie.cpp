/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:46:11 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 00:36:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string& name) : name_(name) {}

void Zombie::announce( void ) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
