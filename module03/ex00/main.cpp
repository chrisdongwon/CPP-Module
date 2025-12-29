/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:06:50 by cwon              #+#    #+#             */
/*   Updated: 2025/12/29 19:26:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
  ClapTrap foo("Foo");

  foo.attack("Bar");
  foo.takeDamage(3);
  foo.beRepaired(10);

  for (int i = 0; i < 15; ++i)
    foo.attack("Another Robot");
  for (int i = 0; i < 5; ++i)
    foo.beRepaired(2);

  ClapTrap baz("Baz");
  baz = foo;

  ClapTrap robot(baz);

  return 0;
}
