/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:31:39 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 14:36:40 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(const std::string& target);
    
    void executeAction() const;

  private:
    std::string target_;
};

#endif // SHRUBBERYCREATIONFORM_HPP_
