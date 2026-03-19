/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:16:15 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 13:44:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat a("Alice", 2);
    std::cout << a << std::endl;

    a.incrementGrade();
    std::cout << a << std::endl;

    a.incrementGrade();
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "------------------" << std::endl;

  try {
    Bureaucrat b("Bob", 150);
    std::cout << b << std::endl;

    b.decrementGrade();
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "------------------" << std::endl;

  try {
    Bureaucrat c("Charlie", 0);
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
