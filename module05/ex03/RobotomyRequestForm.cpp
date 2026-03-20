/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:32:34 by cwon              #+#    #+#             */
/*   Updated: 2026/03/20 11:03:19 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->target_ = other.target_;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
  std::cout << "BZZZZZZ... drilling noises...\n";

  if (rand() % 2)
    std::cout << target_ << " has been robotomized successfully\n";
  else
    std::cout << "Robotomy failed\n";
}
