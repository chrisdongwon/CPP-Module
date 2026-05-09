/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:46:31 by cwon              #+#    #+#             */
/*   Updated: 2026/05/09 13:13:33 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "Intern.hpp"

int main() {
  Bureaucrat boss("Boss", 1);
  Intern intern;

  AForm *form = intern.makeForm("robotomy request", "Bender");
  if (form != NULL) {
    boss.signForm(*form);
    boss.executeForm(*form);
  }
  delete form;

  form = intern.makeForm("shrubbery creation", "Home");
  if (form != NULL) {
    boss.signForm(*form);
    boss.executeForm(*form);
  }
  delete form;

  form = intern.makeForm("presidential pardon", "Chris");
  if (form != NULL) {
    boss.signForm(*form);
    boss.executeForm(*form);
  }
  delete form;

  form = intern.makeForm("???", "Chris");
  if (form != NULL) {
    boss.signForm(*form);
    boss.executeForm(*form);
  }
  delete form;
  
  return 0;
}
