/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:26:18 by cwon              #+#    #+#             */
/*   Updated: 2025/08/16 00:09:29 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
  Zombie* zombie = newZombie("Foo");
  zombie->announce();
  delete zombie;

  randomChump("Bar");
  return 0;
}
