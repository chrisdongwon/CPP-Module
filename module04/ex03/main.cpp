/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 09:11:32 by cwon              #+#    #+#             */
/*   Updated: 2025/09/03 11:38:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) {  
  {
    Ice* ice = new Ice();
    Cure* cure = new Cure();
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(ice);
    src->learnMateria(cure);

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
    delete ice;
    delete cure;
  }
  {
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

    // Test use to check deep copy
    copyAlice->use(0, *bob);  // should work
    alice->use(0, *bob);      // nothing

    // Polymorphic clone test
    AMateria* iceMateria = new Ice();
    AMateria* cureMateria = new Cure();
    AMateria* cloneIce = iceMateria->clone();
    AMateria* cloneCure = cureMateria->clone();

    delete iceMateria;
    delete cureMateria;
    delete cloneIce;
    delete cloneCure;

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
