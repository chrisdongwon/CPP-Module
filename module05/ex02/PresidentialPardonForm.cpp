/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:46:25 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 14:47:10 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Pardon", 25, 5),
      target_(target) {}

void PresidentialPardonForm::executeAction() const {
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox\n";
}
