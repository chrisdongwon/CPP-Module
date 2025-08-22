/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:06:50 by cwon              #+#    #+#             */
/*   Updated: 2025/08/22 09:07:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
  ClapTrap foo("Foo");

  foo.attack("Bar");
  foo.takeDamage(3);
  foo.beRepaired(5);

  foo.takeDamage(12);
  foo.attack("Another Robot");

  ClapTrap baz("Baz");
  baz = foo;

  ClapTrap robot(baz);

  return 0;
}
