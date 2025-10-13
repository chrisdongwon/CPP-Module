/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:17:50 by cwon              #+#    #+#             */
/*   Updated: 2025/10/13 12:52:15 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie* newZombie(std::string name) {
  try {
    return new Zombie(name);
  } catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocation failed for Zombie: " << e.what() << '\n';
    return NULL;
  }
}
