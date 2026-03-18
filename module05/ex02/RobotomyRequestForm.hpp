/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:37:41 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 14:40:53 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP_H
#define ROBOTOMYREQUESTFORM_HPP_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  public:
    RobotomyRequestForm(const std::string& target);

    void executeAction() const;

  private:
    std::string target_;
};

#endif // ROBOTOMYREQUESTFORM_HPP_H
