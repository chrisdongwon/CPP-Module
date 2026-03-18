/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:33:16 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 14:36:57 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145, 137), 
      target_(target) {}

void ShrubberyCreationForm::executeAction() const {
  std::ofstream file((target_ + "_shrubbery").c_str());
  file << "   ^   \n"
          "  ^^^  \n"
          " ^^^^^ \n"
          "   |   \n";
}
