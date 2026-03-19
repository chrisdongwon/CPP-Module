/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:39:58 by cwon              #+#    #+#             */
/*   Updated: 2026/03/19 13:32:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string& target = "");
  // copy constructor
  // assignment operator
  // destructor
  
  void executeAction() const;

 private:
  std::string target_;
};

#endif  // PRESIDENTIALPARDONFORM_HPP_
