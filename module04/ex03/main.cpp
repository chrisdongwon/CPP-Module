/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 09:11:32 by cwon              #+#    #+#             */
/*   Updated: 2025/12/30 15:42:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) {
  {
    std::cout << "===================== Test 1 =================" << std::endl;
    Ice* ice = new Ice();
    Cure* cure = new Cure();
    AMateria* cloneIce = ice->clone();
    AMateria* cloneCure = cure->clone();
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(cloneIce);
    src->learnMateria(cloneCure);

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    delete cloneIce;
    delete cloneCure;
    delete ice;
    delete cure;
  }
  {
    std::cout << "===================== Test 2 =================" << std::endl;
    Ice* ice = new Ice();
    Cure* cure = new Cure();
    IMateriaSource* src = new MateriaSource();
    
    src->learnMateria(ice);
    src->learnMateria(cure);

    Character* alice = new Character("Alice");
    Character* bob = new Character("Bob");

    // Create materias and equip immediately
    AMateria* m0 = src->createMateria("ice");   // owned by Alice
    AMateria* m1 = src->createMateria("cure");  // owned by Alice
    AMateria* m2 = src->createMateria("ice");   // owned by Alice
    AMateria* m3 = src->createMateria("cure");  // owned by Alice

    alice->equip(m0);
    alice->equip(m1);
    alice->equip(m2);
    alice->equip(m3);

    // Use materias
    for (int i = 0; i < 4; ++i) {
      alice->use(i, *bob);
    }

    // Unequip slot 1, must delete manually
    alice->unequip(1);
    delete m1;

    // Equip a new materia in slot 1
    AMateria* m4 = src->createMateria("cure"); // now owned by Alice
    alice->equip(m4);

    // Deep copy test
    Character* copyAlice = new Character(*alice);

    // Unequip slot 0 of original Alice and delete it
    alice->unequip(0);
    delete m0;

    std::cout << "---------- Checking for deep copy ---------" << std::endl;
    // Test use to check deep copy
    copyAlice->use(0, *bob);  // should work
    alice->use(0, *bob);      // nothing

    // Clean up all objects
    delete alice;       // deletes m2, m3, m4
    delete copyAlice;   // deletes its own cloned materias
    delete bob;
    delete src;

    delete ice;
    delete cure;
  }
  return 0;
}
