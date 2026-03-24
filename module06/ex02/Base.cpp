/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:11:03 by cwon              #+#    #+#             */
/*   Updated: 2026/03/24 10:26:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
  std::srand(std::time(0));

  int r = std::rand() % 3;

  if (r == 0) {
    std::cout << "Generated A" << std::endl;
    return new A;
  } else if (r == 1) {
    std::cout << "Generated B" << std::endl;
    return new B;
  } else {
    std::cout << "Generated C" << std::endl;
    return new C;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (...) {
  }

  try {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (...) {
  }

  try {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (...) {
  }
}
