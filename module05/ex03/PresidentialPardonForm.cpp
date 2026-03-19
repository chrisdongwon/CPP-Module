/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:42:34 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 11:43:50 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Pardon", 25, 5), target_(target) {}

void PresidentialPardonForm::executeAction() const {
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox\n";
}
