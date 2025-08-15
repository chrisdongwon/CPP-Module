/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:47:50 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 00:38:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie* zombieHorde(int N, const std::string name) {
  if (N <= 0) {
    return NULL;
  }
  try {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
      horde[i] = Zombie(name);
    }
    return horde;
  } catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocation failed for zombie horde: "
              << e.what() << std::endl;
    return NULL;
  }
}
