/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 00:22:45 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 01:02:17 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main() {
  int N = 5;
  Zombie* horde = zombieHorde(N, "Foo");

  if (horde == NULL) {
    std::cerr << "Failed to create zombie horde" << std::endl;
    return 1;
  }
  for (int i = 0; i < N; ++i) {
    horde[i].announce();
  }
  delete[] horde;
  return 0;
}
