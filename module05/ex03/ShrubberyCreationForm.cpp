/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:58:42 by cwon              #+#    #+#             */
/*   Updated: 2026/03/20 11:03:27 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->target_ = other.target_;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
  std::ofstream file((target_ + "_shrubbery").c_str());
  file << "   ^   \n"
          "  ^^^  \n"
          " ^^^^^ \n"
          "   |   \n";
}
