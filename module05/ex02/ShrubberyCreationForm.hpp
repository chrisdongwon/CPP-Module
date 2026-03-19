/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:57:08 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 13:30:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string& target = "");
  // copy constructor
  // assignment operator
  // destructor
  
  void executeAction() const;

 private:
  std::string target_;
};

#endif  // SHRUBBERYCREATIONFORM_HPP_
