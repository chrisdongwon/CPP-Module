/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:44:09 by cwon              #+#    #+#             */
/*   Updated: 2026/03/18 14:47:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string& target);
    
    void executeAction() const;

  private:
    std::string target_;
};

#endif // PRESIDENTIALPARDONFORM_HPP_
