/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:09:01 by cwon              #+#    #+#             */
/*   Updated: 2026/03/20 11:45:54 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
  return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};

  AForm* (Intern::* creators[3])(const std::string&) = {
      &Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};

  for (int i = 0; i < 3; ++i) {
    if (name == formNames[i]) {
      std::cout << "Intern creates " << name << std::endl;
      return (this->*creators[i])(target);
    }
  }
  std::cout << "Intern couldn't find form: " << name << std::endl;
  return NULL;
}
