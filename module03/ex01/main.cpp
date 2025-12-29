/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:06:50 by cwon              #+#    #+#             */
/*   Updated: 2025/12/29 19:25:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
  ScavTrap foo("Foo");

  foo.attack("Bar");
  foo.takeDamage(20);
  foo.beRepaired(10);
  foo.guardGate();

  ScavTrap bar = foo;
  ScavTrap baz("Baz");
  baz = bar;

  return 0;
}
