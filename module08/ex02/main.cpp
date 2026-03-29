/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:14:59 by cwon              #+#    #+#             */
/*   Updated: 2026/03/29 14:26:49 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

static void subjectTest() {
  std::cout << "===== SUBJECT TEST =====" << std::endl;

  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::stack<int> s(mstack);
}

static void copyTest() {
  std::cout << "\n===== COPY TEST =====" << std::endl;

  MutantStack<int> original;

  for (int i = 0; i < 5; i++) original.push(i * 10);

  MutantStack<int> copy(original);

  std::cout << "Original:" << std::endl;
  for (MutantStack<int>::iterator it = original.begin(); it != original.end();
       ++it)
    std::cout << *it << " ";

  std::cout << "\nCopy:" << std::endl;
  for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
    std::cout << *it << " ";

  std::cout << std::endl;
}

static void assignmentTest() {
  std::cout << "\n===== ASSIGNMENT TEST =====" << std::endl;

  MutantStack<int> a;
  MutantStack<int> b;

  for (int i = 1; i <= 3; i++) a.push(i);

  b = a;

  a.push(100);

  std::cout << "A:" << std::endl;
  for (MutantStack<int>::iterator it = a.begin(); it != a.end(); ++it)
    std::cout << *it << " ";

  std::cout << "\nB:" << std::endl;
  for (MutantStack<int>::iterator it = b.begin(); it != b.end(); ++it)
    std::cout << *it << " ";

  std::cout << std::endl;
}

static void constTest() {
  std::cout << "\n===== CONST ITERATOR TEST =====" << std::endl;

  MutantStack<int> stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  const MutantStack<int> constStack(stack);

  MutantStack<int>::const_iterator it = constStack.begin();
  MutantStack<int>::const_iterator ite = constStack.end();

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}

static void reverseTest() {
  std::cout << "\n===== REVERSE ITERATOR TEST =====" << std::endl;

  MutantStack<int> stack;

  for (int i = 0; i < 5; i++) stack.push(i);

  MutantStack<int>::reverse_iterator rit = stack.rbegin();
  MutantStack<int>::reverse_iterator rite = stack.rend();

  while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
  }
}

static void listComparisonTest() {
  std::cout << "\n===== LIST COMPARISON TEST =====" << std::endl;

  MutantStack<int> mstack;
  std::list<int> list;

  for (int i = 0; i < 5; i++) {
    mstack.push(i);
    list.push_back(i);
  }

  MutantStack<int>::iterator mit = mstack.begin();
  std::list<int>::iterator lit = list.begin();

  while (mit != mstack.end() && lit != list.end()) {
    std::cout << *mit << " == " << *lit << std::endl;
    ++mit;
    ++lit;
  }
}

static void largeTest() {
  std::cout << "\n===== LARGE TEST =====" << std::endl;

  MutantStack<int> stack;

  for (int i = 0; i < 10000; i++) stack.push(i);

  std::cout << "Size: " << stack.size() << std::endl;
  std::cout << "Top: " << stack.top() << std::endl;
}

int main() {
  {
    subjectTest();
    copyTest();
    assignmentTest();
    constTest();
    reverseTest();
    listComparisonTest();
    largeTest();
    std::cout << "testing finished\n" << std::endl;
  }
  {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }

  return 0;
}
