/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:46:31 by cwon              #+#    #+#             */
/*   Updated: 2026/03/20 10:54:42 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Bureaucrat boss("Boss", 1);
  Bureaucrat intern("Intern", 150);

  ShrubberyCreationForm shrub("home");
  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  boss.signForm(shrub);
  boss.executeForm(shrub);

  boss.signForm(robot);
  boss.executeForm(robot);

  boss.signForm(pardon);
  boss.executeForm(pardon);

  intern.executeForm(pardon);
  return 0;
}
