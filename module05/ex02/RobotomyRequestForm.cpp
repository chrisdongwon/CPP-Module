/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:39:24 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 14:40:59 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy", 72, 45),
      target_(target) {}

void RobotomyRequestForm::executeAction() const {
  std::cout << "BZZZZZZ... drilling noises...\n";

  if (rand() % 2)
    std::cout << target_ << " has been robotomized successfully\n";
  else
    std::cout << "Robotomy failed\n";
}
