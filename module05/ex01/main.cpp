/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:12:25 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 10:47:32 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    Form contract("Contract", 50, 25);

    std::cout << contract << std::endl;

    intern.signForm(contract);
    boss.signForm(contract);

    std::cout << contract << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
