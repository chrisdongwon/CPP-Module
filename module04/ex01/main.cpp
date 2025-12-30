/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:43:46 by cwon              #+#    #+#             */
/*   Updated: 2025/08/25 16:43:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

#define ARRAY_SIZE 4

int main( void ) {
  {
    std::cout << "=== Brain Leak Check ===" << std::endl;
    const Animal* i = new Dog();
    const Animal* j = new Cat();

    delete j;
    delete i;
  }
  {
    std::cout << "\n=== Creating Animals ===" << std::endl;
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
    if (i < ARRAY_SIZE / 2) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
    }

    std::cout << "\n=== Making Sounds ===" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
      animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
      delete animals[i];  // must call Dog/Cat destructor properly
    }

    std::cout << "\n=== Deep Copy Test (Dog) ===" << std::endl;
    Dog originalDog;
    originalDog.brain()->set_ideas(0, "Chase the cat!");
    originalDog.brain()->set_ideas(1, "Dig a hole!");

    Dog copiedDog(originalDog);  // uses copy constructor

    std::cout << "Original Dog idea[0]: " << originalDog.brain()->ideas(0) << std::endl;
    std::cout << "Copied Dog ideas[0]: "   << copiedDog.brain()->ideas(0) << std::endl;
    std::cout << "Original Dog idea[1]: " << originalDog.brain()->ideas(1) << std::endl;
    std::cout << "Copied Dog ideas[1]: "   << copiedDog.brain()->ideas(1) << std::endl;

    // Change original's brain to verify deep copy
    originalDog.brain()->set_ideas(0, "Eat food!");
    std::cout << "After change:" << std::endl;
    std::cout << "Original Dog ideas[0]: " << originalDog.brain()->ideas(0) << std::endl;
    std::cout << "Copied Dog ideas[0]: "   << copiedDog.brain()->ideas(0) << std::endl;
    std::cout << "Original Dog idea[1]: " << originalDog.brain()->ideas(1) << std::endl;
    std::cout << "Copied Dog ideas[1]: "   << copiedDog.brain()->ideas(1) << std::endl;

    std::cout << "\n=== Deep Copy Test (Cat) ===" << std::endl;
    Cat originalCat;
    originalCat.brain()->set_ideas(0, "Sleep all day.");
    originalCat.brain()->set_ideas(1, "Knock things off the table.");

    Cat assignedCat;
    assignedCat = originalCat;  // uses assignment operator

    std::cout << "Original Cat ideas[0]: " << originalCat.brain()->ideas(0) << std::endl;
    std::cout << "Assigned Cat ideas[0]: " << assignedCat.brain()->ideas(0) << std::endl;

    originalCat.brain()->set_ideas(0, "Scratch the couch!");
    std::cout << "After change:" << std::endl;
    std::cout << "Original Cat ideas[0]: " << originalCat.brain()->ideas(0) << std::endl;
    std::cout << "Assigned Cat ideas[0]: " << assignedCat.brain()->ideas(0) << std::endl;
  }
  return 0;
}
